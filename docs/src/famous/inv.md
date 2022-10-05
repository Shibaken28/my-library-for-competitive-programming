# 転倒数計算
## 問題
- 問題リンク：[転倒数](https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j)
- 転倒数とは，配列の中で，ある要素の前にある要素の値が大きいものの個数のこと
  - 厳密には，長さ$N$の数列$A_1,A_2,A_3,\cdots,A_N$で，$i<j$で$A_i>A_j$となる$(i,j)$の個数
- あるいは，バブルソートを行ったときに，要素の交換回数のこと
## 解法
実際にバブルソートをすると要素数$N$で$O(N^2)$かかってしまうが，転倒数を計算するだけなら$1$点加算と区間和が求められるデータ構造を用いて$O(N\log N)$で計算できる．

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


int main(void){
    /*転倒数計算*/
    int n;cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
        A[i]--;
    }
    RSQ<int>rsq(n,0);
    long ans=0;
    for(int i=0;i<n;i++){
        ans+=rsq.query(A[i]+1,n);
        rsq.update(A[i],1);
    }
    cout<<ans<<endl;
}
```

[提出リンク](https://atcoder.jp/contests/chokudai_S001/submissions/35410016)
