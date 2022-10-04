# Rolling Hash
## 概要
文字列$S$で，連続した部分文字列のハッシュ値を計算する．
## 計算量
- 前計算: $O(|S|)$
- ハッシュ値計算: $O(1)$

## ソースコード
```cpp
/*HashRolling*/
template<class T> class RollingHash{
    public:
    vector<T> hash,pow;
    RollingHash(vector<T> &A,T base){
        int N = (int)A.size();
        hash.resize(N+1);
        pow.resize(N+1);
        pow[0]=1;
        for(int i=0;i<N;i++){
            hash[i+1]=hash[i]*base+A[i];
            pow[i+1]=pow[i]*base;
        }
    }
    T get(int l,int r){
        return hash[r]-hash[l]*pow[r-l];
    }
};
```
