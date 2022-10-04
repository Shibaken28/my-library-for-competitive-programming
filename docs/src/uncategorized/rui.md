# 累積和
## 概要
静的な数列の区間和を高速で求める．

## 計算量
- 構築: $O(N)$
- クエリ：$O(1)$

## ソースコード

```cpp
template<class T> struct CumulativeSum{
    size_t n;
    vector<T> A;
    CumulativeSum(size_t n){
        this->n=n;
        init();
    };
    void init(){
        A.resize(n+1);
    }
    void add(int i,T x){
        A[i+1]=x;
    }
    void build(){
        for(int i=0;i<n;i++){
            A[i+1]+=A[i];
        }
    }
    /*[l,r)の総和を求める*/
    T query(int l,int r){
        return A[r]-A[l];
    }
};
```
