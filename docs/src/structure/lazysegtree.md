# Lazy Segment Tree
## はじめに
遅延評価セグメント木は，抽象化してるやつを持っておいて，コンテストで出題されたらペタってやろうと企んでいる人がいる．しかし，意外と罠が多く，バグ取りに時間がかかってしまうことが多い．これは体験談．やはり，具体例を実際に実装して，その中で注意点を理解しておくのが良いと思う．

## Range Minimum Query and Range Update Query
長さ$N$の数列($A_0,A_1,A_2,\cdots,A_{N-1}$)について，次のクエリを$O(\log N)$で行う．
- 区間の値を$x$に**更新**
- 区間の最小値を取得

[verify用問題](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F)

なお，AOJにあるRangeUpdateQueryという問題は幅1のクエリだと考えれば解ける．

```cpp
/*lazy segment tree*/
template<class T> class RMUQ{
    public:
        int n;
        vector<T>dat,lazy;
        const int INF;
    RMUQ(int n_,T INF_):INF(INF_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,INF);
        lazy.assign(2*n-1,INF);
    }
    void update(int a,int b,T x,int k,int l,int r){
        eval(k);
        if(a <= l && r <= b){
            lazy[k]=x;
            eval(k);
        }else if(a < r && l < b){
            update(a,b,x,k*2+1,l,(l+r)/2);
            update(a,b,x,k*2+2,(l+r)/2,r);
            dat[k]=min(dat[k*2+1],dat[k*2+2]);
        }
    }
    void update(int k,T a){
        update(k,k+1,a,0,0,n);
    }
    void update(int a,int b,T x){
        update(a,b,x,0,0,n);
    }
    void eval(int k){
        if(lazy[k]==INF)return;
        if(k<n-1){
            lazy[k*2+1]=lazy[k];
            lazy[k*2+2]=lazy[k];
        }
        dat[k]=lazy[k];
        lazy[k]=INF;
    }
    // [a,b)の最小値を求める，頂点kは[l,r)に対応している
    T query(int a,int b,int k,int l,int r){
        eval(k);
        if(r<=a||b<=l)return INF;//範囲外
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            T vl=query(a,b,k*2+1,l,(l+r)/2);
            T vr=query(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
    //[a,b)の最小値を求める
    T query(int a,int b){
        return query(a,b,0,0,n);
    }
    T get(int k){
        return query(k,k+1);
    }
};
```
## Range Add Query and Range Sum Query
- 区間の値に$x$を**加算**
- 区間の和を取得

実装で注意しなければならないのが区間に$x$を加算するときは，$x\times (区間の幅)$を`dat`に加算する必要があること．

[verify用問題](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G)

```cpp

template<class T> class RSAQ{
    public:
        int n;
        vector<T>dat,lazy;
        const int ZERO;
    RSAQ(int n_,T ZERO_):ZERO(ZERO_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,ZERO);
        lazy.assign(2*n-1,ZERO);
    }
    void update(int a,int b,T x,int k,int l,int r){
        eval(k,r-l);
        if(a <= l && r <= b){
            lazy[k]+=x;
            eval(k,r-l);
        }else if(a < r && l < b){
            update(a,b,x,k*2+1,l,(l+r)/2);
            update(a,b,x,k*2+2,(l+r)/2,r);
            dat[k]=dat[k*2+1]+dat[k*2+2];
        }
    }
    void update(int k,T a){
        update(k,k+1,a,0,0,n);
    }
    void update(int a,int b,T x){
        update(a,b,x,0,0,n);
    }
    void eval(int k,int len){
        if(lazy[k]==ZERO)return;
        if(k<n-1){
            lazy[k*2+1]+=lazy[k];
            lazy[k*2+2]+=lazy[k];
        }
        dat[k]=dat[k] + lazy[k]*len;
        lazy[k]=ZERO;
    }
    // [a,b)の和を求める，頂点kは[l,r)に対応している
    T query(int a,int b,int k,int l,int r){
        eval(k,r-l);
        if(r<=a||b<=l)return ZERO;//範囲外
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            T vl=query(a,b,k*2+1,l,(l+r)/2);
            T vr=query(a,b,k*2+2,(l+r)/2,r);
            return vl+vr;
        }
    }
    //[a,b)の和
    T query(int a,int b){
        return query(a,b,0,0,n);
    }
    T get(int k){
        return query(k,k+1);
    }
};
```

## Range Minimum Query and Range Add Query
- 区間の値に$x$を**加算**
- 区間の最小値を取得

[verify用問題](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H)

注意する点は，演算の種類が，加算と$\textrm{min}$の2種類ある点である．
この場合，どちらも単位元が異なり，加算は$0$で，$\textrm{min}$は$\infty$である．
また，`lazy`を`dat`に反映させるときは`dat = dat + lazy`となる(なぜなら，区間に$x$が加算されたらその区間の最小値も$x$増えるから)．

```cpp
template<class T> class RMAQ{
    public:
        int n;
        vector<T>dat,lazy;
        const int ZERO,INF;
    RMAQ(int n_,T ZERO_,T INF_):ZERO(ZERO_),INF(INF_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,ZERO);
        lazy.assign(2*n-1,ZERO);
    }
    void update(int a,int b,T x,int k,int l,int r){
        eval(k,r-l);
        if(a <= l && r <= b){
            lazy[k]+=x;
            eval(k,r-l);
        }else if(a < r && l < b){
            update(a,b,x,k*2+1,l,(l+r)/2);
            update(a,b,x,k*2+2,(l+r)/2,r);
            dat[k]=min(dat[k*2+1],dat[k*2+2]);
        }
    }
    void update(int k,T a){
        update(k,k+1,a,0,0,n);
    }
    void update(int a,int b,T x){
        update(a,b,x,0,0,n);
    }
    void eval(int k,int len){
        if(lazy[k]==ZERO)return;
        if(k<n-1){
            lazy[k*2+1]+=lazy[k];
            lazy[k*2+2]+=lazy[k];
        }
        dat[k]=dat[k]+lazy[k];
        lazy[k]=ZERO;
    }
    // [a,b)の和を求める，頂点kは[l,r)に対応している
    T query(int a,int b,int k,int l,int r){
        eval(k,r-l);
        if(r<=a||b<=l)return INF;//範囲外
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            T vl=query(a,b,k*2+1,l,(l+r)/2);
            T vr=query(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
    //[a,b)の和
    T query(int a,int b){
        return query(a,b,0,0,n);
    }
    T get(int k){
        return query(k,k+1);
    }
};
```

## Range Sum Query and Range Update Query
- 区間の値を$x$に**更新**
- 区間の和を取得

[verify問題](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I)

注意するのは今まで`lazy`を$0$のときは`dat`に反映させないということをしていたが，今回は`lazy`が$0$のときも`dat`に反映させる必要があるということである．今回は$0$の代わりに`NONE`を使っている．この値はあり得ない値に設定してあるが，場合によってはこれも変える必要がでてくる．

抽象化の準備として，`NONE`を更新クエリの単位元と見ることとする．

```cpp
template<class T> class RSUQ{
    public:
        int n;
        vector<T>dat,lazy;
        const int ZERO;
        const int NONE = 2147483647;
    RSUQ(int n_,T ZERO_):ZERO(ZERO_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,ZERO);
        lazy.assign(2*n-1,NONE);
    }
    void update(int a,int b,T x,int k,int l,int r){
        eval(k,r-l);
        if(a <= l && r <= b){
            lazy[k]=x;
            eval(k,r-l);
        }else if(a < r && l < b){
            update(a,b,x,k*2+1,l,(l+r)/2);
            update(a,b,x,k*2+2,(l+r)/2,r);
            dat[k]=dat[k*2+1]+dat[k*2+2];
        }
    }
    void update(int k,T a){
        update(k,k+1,a,0,0,n);
    }
    void update(int a,int b,T x){
        update(a,b,x,0,0,n);
    }
    void eval(int k,int len){
        if(lazy[k]==NONE)return;
        if(k<n-1){
            lazy[k*2+1]=lazy[k];
            lazy[k*2+2]=lazy[k];
        }
        dat[k]=lazy[k]*len;
        lazy[k]=NONE;
    }
    // [a,b)の和を求める，頂点kは[l,r)に対応している
    T query(int a,int b,int k,int l,int r){
        eval(k,r-l);
        if(r<=a||b<=l)return ZERO;//範囲外
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            T vl=query(a,b,k*2+1,l,(l+r)/2);
            T vr=query(a,b,k*2+2,(l+r)/2,r);
            return vl+vr;
        }
    }
    //[a,b)の和
    T query(int a,int b){
        return query(a,b,0,0,n);
    }
    T get(int k){
        return query(k,k+1);
    }
};
```
## 抽象化
今まで見てきた通り，抽象化するときは，ただのsegment treeと比べてユーザーが決める要素が多い．
遅延セグ木に乗せられる条件を列挙する([参考](https://algo-logic.info/segment-tree/))．写像$p$を$p(m,n):=m\*m\*\cdots \*m$($m$の$n$回の積)

- $X$と二項演算$\circ$がモノイド
- $M$と二項演算$\bullet$がモノイド
- $(x_1\circ x_2)\* p(m,n) = (x_1\*p(m,n/2))\circ(x_2\*p(m,n/2)) (x_1,x_2\in X)$ 
  - 子に伝播するときに半分ずつ伝播させるようなことができるか
- $(x\* m\_1)*m\_2 = x\*(m\_1\times \_2)$
  - これが何なのか正直わからん(思考停止)

なお，$p(m,n)$は高速に計算できる必要がある．

モノイドについては[SegTree](./segtree.md)を参照．
```cpp
template<typename X,typename M> struct LazySegmentTree{
    public:
        using FX = function<X(X, X)>;
        using FA = function<X(X, M)>;
        using FM = function<M(M, M)>;
        using FP = function<M(M, int)>;
        int n;
        FX fx;
        FA fa;
        FM fm;
        FP fp;
        const X ex;
        const M em;
        vector<X> dat;
        vector<M> lazy;
    LazySegmentTree(int n_,FX fx_,FA fa_,FM fm_,FP fp_,X ex_,M em_):n(n_),fx(fx_),fa(fa_),fm(fm_),fp(fp_),ex(ex_),em(em_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,ex);
        lazy.assign(2*n-1,em);
    }
    void set(int k,X x){
        dat[k+n-1]=x;
    }
    void build(){
        for(int k=n-2;k>=0;k--){
            dat[k]=fx(dat[2*k+1],dat[2*k+2]);
        }
    }
    void update(int a,int b,M x,int k,int l,int r){
        eval(k,r-l);
        if(a <= l && r <= b){
            lazy[k]= fm(lazy[k],x);
            eval(k,r-l);
        }else if(a < r && l < b){
            update(a,b,x,k*2+1,l,(l+r)/2);
            update(a,b,x,k*2+2,(l+r)/2,r);
            dat[k]=fx(dat[k*2+1],dat[k*2+2]);
        }
    }
    void update(int k,M a){
        update(k,k+1,a,0,0,n);
    }
    void update(int a,int b,M x){
        update(a,b,x,0,0,n);
    }
    void eval(int k,int len){
        if(lazy[k]==em)return;
        if(k<n-1){
            lazy[k*2+1]=  fm(lazy[k*2+1],lazy[k]);
            lazy[k*2+2] = fm(lazy[k*2+2],lazy[k]);
        }
        dat[k]=fa(dat[k],fp(lazy[k],len));
        lazy[k]=em;
    }
    X query(int a,int b,int k,int l,int r){
        eval(k,r-l);
        if(r<=a||b<=l)return ex;//範囲外
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            X vl=query(a,b,k*2+1,l,(l+r)/2);
            X vr=query(a,b,k*2+2,(l+r)/2,r);
            return fx(vl,vr);
        }
    }
    X query(int a,int b){
        return query(a,b,0,0,n);
    }
    X get(int k){
        return query(k,k+1);
    }
};
```

各パラメータのイメージは以下の通り．
```cpp
using X = long; // 持つデータの型
using M = long; // 遅延評価(クエリ)の型
auto fx = [](X a,X b){return min(a,b);}; // データの二項演算
auto fa = [](X a,M b){return b;}; // データにクエリを適用する
auto fm = [](M a,M b){return b;}; // 遅延評価の二項演算
auto fp = [](M a,int b){return a;}; // 遅延評価を幅bに適用した場合の遅延評価
X ex = (1L<<31)-1; //持つデータの演算の単位元
M em = 1e17; //遅延評価の演算の単位元
LazySegmentTree<X,M> seg(N,fx,fa,fm,fp,ex,em);
```
例を示す．
#### Range Minimum Query and Range Update Query
```cpp
using X = long;
using M = long;
auto fx = [](X a,X b){return min(a,b);};
auto fa = [](X a,M b){return b;};
auto fm = [](M a,M b){return b;};
auto fp = [](M a,int b){return a;};
X ex = (1L<<31)-1; //minの単位元
M em = 1e17; //更新クエリの単位元(ありえない数値)
LazySegmentTree<X,M> seg(N,fx,fa,fm,fp,ex,em);
```
#### Range Sum Query and Range Add Query
```cpp
using X = long;
using M = long;
auto fx = [](X a,X b){return a+b;};
auto fa = [](X a,M b){return a+b;};
auto fm = [](M a,M b){return a+b;};
auto fp = [](M a,int b){return a*b;};
X ex = 0; //sumの単位元
M em = 0; //加算クエリ+の単位元
LazySegmentTree<X,M> seg(N,fx,fa,fm,fp,ex,em);
```
#### Range Minimum Query and Range Add Query
初期値に注意．
```cpp
using X = long;
using M = long;
auto fx = [](X a,X b){return min(a,b);};
auto fa = [](X a,M b){return a+b;};
auto fm = [](M a,M b){return a+b;};
auto fp = [](M a,int b){return a;};
X ex = 1e17; //minの単位元
M em = 0; //加算クエリ+の単位元
LazySegmentTree<X,M> seg(N,fx,fa,fm,fp,ex,em);
for(int i=0;i<N;i++){
    seg.set(i,0);//初期化
}
seg.build();
```
#### Range Sum Query and Range Update Query
更新クエリの単位元はありえない数値(クエリに現れない数)にする．
```cpp
using X = long;
using M = long;
auto fx = [](X a,X b){return a+b;};
auto fa = [](X a,M b){return b;};
auto fm = [](M a,M b){return b;};
auto fp = [](M a,int b){return a*(long)b;};
X ex = 0; //加算の単位元
M em = 1237615273123L; //更新クエリの単位元
LazySegmentTree<X,M> seg(N,fx,fa,fm,fp,ex,em);
for(int i=0;i<N;i++){
    seg.set(i,0);//初期化
}
seg.build();
```
