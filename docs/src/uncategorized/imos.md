# imos法
## 概要
要素数$N$の数列について，区間への加算を$O(1)$で行い，$O(N)$の処理を行うことで各値が$O(1)$で得られる．
## ソースコード
```cpp
template<class T> struct Imos{
    vector<T> A;
    int N;
    constexpr Imos(int N){
        this -> N = N;
        init();
    }
    constexpr void init(){
        A.resize(N+1);
        fill(A.begin(),A.end(),0);
    }
    /*[l,r]にxを加算*/
    constexpr void add(int l,int r,T x){
        A[l] += x;
        A[r+1] += -x;
    }
    constexpr void calc(){
        for(int i=0;i<N;i++){
            A[i+1] += A[i];
        }
    }
    constexpr T get(int i){
        return A[i];
    }
};
```
