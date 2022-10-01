# 要素を2分探索
## 概要
C++には`lower_bound`や`upper_bound`，`binary_search`が用意されているが，例外処理が面倒なので関数したもの．
次の関数を作成した．
- その数が存在するかの`isExist`
- $x$以上の最小の数を探す`lowerElement`
- $x$より大きい最小の数を探す`upperlement`
- $x$以下の最大の数を探す`underElement`
- $x$未満の最大の数を探す`lessElement`
- $x$の個数を数える`countElement`
- $l$以上$r$以下の個数を数える`countElementInRange`
## 注意
`vector`はソート済みである必要がある．

## ソースコード

```cpp
/*
Aにxが存在するか
O(log N)
*/
template<class T> bool isExist(vector<T> &A,T x){
    return binary_search(A.begin(),A.end(),x);
}
template<class T> bool isExist(set<T> &A,T x){
    auto it = A.lower_bound(x);
    if(it==A.end()){
        return false;
    }
    return *it == x;
}

/*
Aに存在するx以上の数
最も小さいindexとその値find
O(log N)
*/
template<class T> bool lowerElement(vector<T> &A,T x,T &find,int &index){
    index = lower_bound(A.begin(),A.end(),x) - A.begin();
    if(index == (int)A.size())return false;
    find = A[index];
    return true;
}
template<class T> bool lowerElement(set<T> &A,T x,T &find){
    auto it = A.lower_bound(x);
    if(it==A.end())return false;
    find = *it;
    return true;
}



/*
Aに存在するxより大きい数
最も小さいindexとその値find
O(log N)
*/
template<class T> bool upperElement(vector<T> &A,T x,T &find,int &index){
    index = upper_bound(A.begin(),A.end(),x) - A.begin();
    if(index == (int)A.size())return false;
    find = A[index];
    return true;
}
template<class T> bool upperElement(set<T> &A,T x,T &find){
    auto it = A.upper_bound(x);
    if(it == A.end())return false;
    find = *it;
    return true;
}               




/*
Aに存在するx以下
最も大きいindexとその値find
O(log N)
*/
template<class T> bool underElement(vector<T> &A,T x,T &find,int &index){
    index = upper_bound(A.begin(),A.end(),x) - A.begin();
    index--;
    if(index >= (int)A.size())return false;
    find = A[index];
    return true;
}
template<class T> bool underElement(set<T> &A,T x,T &find){
    auto it = A.upper_bound(x);
    if(it == A.begin())return false;
    it--;
    find = *it;
    return true;
}

/*
Aに存在するxより小さい数
最も大きいindexとその値find
O(log N)
*/
template<class T> bool lessElement(vector<T> &A,T x,T &find,int &index){
    index = lower_bound(A.begin(),A.end(),x) - A.begin();
    index--;
    if(index < 0)return false;
    find = A[index];
    return true;
}
template<class T> bool lessElement(set<T> &A,T x,T &find){
    auto it = A.lower_bound(x);
    if(it == A.begin())return false;
    it--;
    find = *it;
    return true;
}

/*
Aに含まれるxの個数をO(log N)で求める
*/
template<class T> int countElement(vector<T> &A,T x){
    T f1,f2;
    int i1,i2;
    lowerElement(A,x,f1,i1);
    underElement(A,x,f2,i2);
    return isExist(A,x)?i2-i1+1:0;
}

/*
Aに含まれるl以上r以下の個数をO(log N)で求める
*/
template<class T> int countElementInRange(vector<T> &A,T l,T r){
    T f1,f2;
    int i1,i2;
    lowerElement(A,l,f1,i1);
    underElement(A,r,f2,i2);
    int c = i2-i1+1;
    return c>0?c:0;
}

```
