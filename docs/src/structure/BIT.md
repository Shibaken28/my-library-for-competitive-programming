# Binary Indexed Tree

## 概要
一点加算と区間和を $O(\log N)$ で行うデータ構造．
なお，~~上位互換のsegment treeもこの機能を要しており，わざわざBITを使う必要はない~~(実装が簡単，セグ木に対して定数倍早い，といった利点がある)．

## ソースコード
1-indexedなことに注意．
```cpp
template<class T> std::istream &operator>>(std::istream &in,vector<T>&A){
    for(T&a:A){
        std::cin>>a;
    }
    return in;
}

template <typename T>
struct BIT{
    int n;
    vector<T> bit;
    BIT(int n_):n(n_){
        bit.resize(n+1);
    }

    void add(int i,T x){
        i++;
        while(i<=n){
            bit[i]+=x;
            i+=i&-i;
        }
    }
    T sum(int i){
        i++;
        T s=0;
        while(i>0){
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }
};
```