# 座標圧縮imos法

## ソースコード

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

