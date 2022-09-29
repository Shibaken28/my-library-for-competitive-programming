# imos法
## 概要
要素数\\(N\\)の数列について，区間への加算を\\(O(1)\\)で行い，\\(O(N)\\)の処理を行うことで各値が\\(O(1)\\)で得られる．
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

## 座標圧縮版

```cpp
template<class T> bool underElement(vector<T> &A,T x,T &find,int &index){
    index = upper_bound(A.begin(),A.end(),x) - A.begin();
    index--;
    if(index >= (int)A.size())return false;
    find = A[index];
    return true;
}

template<class T> struct shrinkImos{
    vector<pair<long,T>> query;
    vector<pair<long,T>> result;
    shrinkImos(){
        init();
    }
    void init(){
        query.clear();
        result.clear();
    }
    /*[l,r]にxを加算*/
    void add(int l,int r,T x){
        query.push_back({l,x});
        query.push_back({r,0});
        query.push_back({r+1,-x});
    }
    void calc(){
        result.clear();
        for(const auto&[p,v]:query){
            result.push_back({p,v});
        }
        sort(result.begin(),result.end());
        for(int i=0;i<(int)result.size()-1;i++){
            result[i+1].second += result[i].second;
        }
    }
    constexpr T get(long i){
        pair<long,T> f;
        int _;
        if(!underElement(result,i,f,_)){
            return 0;
        }
        return f.second;
    }
};
```

