# Segment Tree
## はじめに
さっそく抽象化すると(僕が)よくわからんので、例を挙げていく．
## Range Minimum Query
長さ$N$の数列($A_0,A_1,A_2,\cdots,A_{N-1}$)について，次のクエリを$O(\log N)$で行う
- $a_i$を$x$に**更新**する
- 区間の**最小値**を求める

[verify用問題](https://onlinejudge.u-aizu.ac.jp/courses/library/3/dsl/all/dsl_2_a)


```cpp
template<typename T>
struct RMQ{
    int n;
    vector<T>dat;
    const T INF;
    RMQ(int n_,T INF_):INF(INF_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,INF);
    }
    void update(int k,T a){
        k+=n-1;// i番目は、配列上では n-1+i 番目に格納されている
        dat[k]=a;// 葉の更新
        while(k>0){
            k=(k-1)/2; //親のインデックス
            // 子の内小さい方を選ぶ
            dat[k]=min(dat[k*2+1],dat[k*2+2]);
        }
    }
    // [a,b)の最小値を求める，頂点kは[l,r)に対応している
    T query(int a,int b,int k,int l,int r){
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
};
```

## Range Sum Query
- $A_i$に$x$を**加算**する．
- 区間の**総和**を求める

[verify用問題](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B)

```cpp
template<typename T>
struct RSQ{
    int n;
    vector<T>dat;
    const T ZERO;
    RSQ(int n_,T ZERO_):ZERO(ZERO_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,ZERO);
    }
    void update(int k,T a){
        k+=n-1;// i番目は、配列上では n-1+i 番目に格納されている
        dat[k]+=a;// 葉の更新
        while(k>0){
            k=(k-1)/2; //親のインデックス
            // 子の和を計算
            dat[k]=dat[k*2+1]+dat[k*2+2];
        }
    }
    
    T query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return ZERO;//範囲外
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            T vl=query(a,b,k*2+1,l,(l+r)/2);
            T vr=query(a,b,k*2+2,(l+r)/2,r);
            return vl+vr;
        }
    }
    //[a,b)の総和を求める
    T query(int a,int b){
        return query(a,b,0,0,n);
    }
};

```
## 抽象化
RMQとRSQを比較すると，`min`と`+`，`INF`と`ZERO`が違うだけで，ほとんど同じ．
これらを抽象化する．
`min`と`+`に当たるものを`FX`と定義し，`INF`と`ZERO`に当たるものを`ex`と定義する．

また，新たに
- 葉の値を取得する関数`get`
- 更新をせずに値を入れる関数`set`
- `set`した後に実行したい構築処理`build`
  
を追加した．

```cpp
template<typename T>
struct SegTree{
    using FX = function<T(T,T)>; // TとTの演算結果Tを返す
    FX fx;
    int n;
    vector<T>dat;
    const T ex;//単位元(こいつとxを演算をしてもxになる)
    SegTree(int n_,T ex_,FX fx_):ex(ex_),fx(fx_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,ex);
    }
    void set(int k,T a){
        k+=n-1;
        dat[k]=a;
    }
    void build(){
        for(int k=n-2;k>=0;k--){
            dat[k]=fx(dat[k*2+1],dat[k*2+2]);
        }
    }
    void update(int k,T a){
        k+=n-1;// i番目は、配列上では n-1+i 番目に格納されている
        dat[k] = a;// 葉の更新
        while(k>0){
            k=(k-1)/2; //親のインデックス
            // 子の和を計算
            dat[k]=fx(dat[k*2+1],dat[k*2+2]);
        }
    }
    
    T query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return ex;//範囲外なので単位元を返す
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            T vl=query(a,b,k*2+1,l,(l+r)/2);
            T vr=query(a,b,k*2+2,(l+r)/2,r);
            return fx(vl,vr);
        }
    }
    //[a,b)のfx(A_a,A_a+1,...,A_b-1)を返す
    T query(int a,int b){
        return query(a,b,0,0,n);
    }
    T get(int k){
        return dat[k+n-1];
    }

};
```
RMQにしたいときは，次のように単位元と関数を与える．
```cpp
SegTree<int>st(n,2147483647,[](int a,int b){return min(a,b);});
```
先程のRSQにしたいときは，次のように単位元と関数を与える．
ただし，$x$を加算するという操作が先程の設計だとできないので．$A_i+x$に更新すると言い換える必要がある．あるいはコードを変更する．
```cpp
SegTree<int>st(n,0,[](int a,int b){return a+b;});
```

**モノイド**であればセグ木に乗せることができると知られている．

モノイドとは次の性質を満たす集合$M$と演算$\circ$($M\times M\longmapsto M$)の**組**である．
- $M$の任意の元$a,b,c$に対して，$(a\circ b)\circ c=a\circ (b\circ c)$を満たす．
- $M$の任意の元$a$に対して，$a\circ e=e\circ a=a$を満たす$M$の単位元$e$が存在する．

RMQで考えると，$M=\mathbb{N}$，$a\circ b=\textrm{min}(a,b)$，$e=\infty$であり，次が成り立つ．
- $\textrm{min}(\textrm{min}(a,c),b)=\textrm{min}(a,\textrm{min}(b,c))$
- $\textrm{min}(a,\infty)=\textrm{min}(\infty,a)=a$

モノイドであり，セグ木に乗せられることが確認できる．

## Range GCD Query
亜種として，区間の最大公約数を求める[問題](https://atcoder.jp/contests/abc125/tasks/abc125_c)について考える．

この問題は，好きな$A_i$を一つ選んでそれを削除したときの，$A_1,A_2,...,A_{N-1}$の最大公約数の最大値を求める問題だと言い換えることができる．

- 演算を$\textrm{GCD}$とする．
- $\textrm{GCD}(x,0)=x$と定義すると単位元は$0$である．

$\textrm{GCD}$は計算順序は関係なく，モノイドの条件をみたすため，セグ木にのせられることがわかる．

```cpp
int GCD(int a,int b){
    if(a<b)return GCD(b,a);
    if(b==0)return a;
    return GCD(b,a%b);
}

int main(void){
    int n;cin>>n;
    SegTree<int>st(n,0,[](int a,int b){return GCD(a,b);});
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.set(i,a);
    }
    st.build();
    int ans = 0;
    for(int i=0;i<n;i++){
        int l = st.query(0,i);
        int r = st.query(i+1,n);
        chmax(ans,GCD(l,r));
    }
    cout<<ans<<endl;
}


```
[提出結果](https://atcoder.jp/contests/abc125/submissions/35400383)

なお，この問題は左からと右からの累積GCDを使って解くことができるのでセグ木はオーバーキル解法である(しかもこっちのほうが遅い)が，新たに書くコードの少なくバグりづらいので殴れると何かと嬉しい．

## タコヤキオイシクナール
[問題リンク](https://atcoder.jp/contests/arc008/tasks/arc008_4)
試験管橙diffだが，今出題されれば水～青レベルだと思う(本当？)．

線形変換を行っていることに注目し，行列を考える．
美味しさ$x$のたこ焼きを$(a,b)$の機械に通すことを行列で表すと次のようになる．
$$
\begin{pmatrix}
x & 1 \\\\
\end{pmatrix}
\begin{pmatrix}
a & 0 \\\\
b & 1 \\\\
\end{pmatrix}
\=
\begin{pmatrix}
ax+b & 1\\\\
\end{pmatrix}
$$
さらに，$(c,d)$の機械に通したものは次のように表現できる．
$$
\begin{pmatrix}
x & 1 \\\\
\end{pmatrix}
\begin{pmatrix}
a & 0 \\\\
b & 1 \\\\
\end{pmatrix}
\begin{pmatrix}
c & 0 \\\\
d & 1 \\\\
\end{pmatrix}
\=
\begin{pmatrix}
? & 1\\\\
\end{pmatrix}
$$
また，
- $\mathbb{R}^{2\times 2}$の任意の元$A,B,C$で$(AB)C=A(BC)$
- $\mathbb{R}^{2\times 2}$の任意の元$A$で，単位行列$I$を用意すると$AI=IA=A$

であり，2次の正方行列の集合$\mathbb{R}^{2\times 2}$に対して，演算を行列の積とすると，モノイドであることがわかる．よって，セグ木に乗る．
なお，解くためには座標圧縮する必要がある．
[提出リンク](https://atcoder.jp/contests/arc008/submissions/35401150)

行列+セグ木+座圧のライブラリてんこ盛り問題．

## セグ木上の二分探索
未実装
