# よくあるテクニック

## メタ読み
- 制約が$N=20$のときは，$2^N$通りのbit全探索
- 制約が$N=40$くらいのときは半分全列挙
  - これは半分全列挙感がすごい[ABC271 F - XOR on Grid Path](https://atcoder.jp/contests/abc271/tasks/abc271_f)

## 線形変換
- [線形漸化式](./famous/fibo.md)
- 行列を使って表すことができる
- dpの遷移が線形変換で表せるときは高速化ができる
- [BasyStepGiantStep](./natural/bsgs.md)が使えるパターン([ABC270 G - Sequence in mod P](https://atcoder.jp/contests/abc270/tasks/abc270_g))
- セグメントツリーに乗る[ARC008 D - タコヤキオイシクナール](https://atcoder.jp/contests/arc008/tasks/arc008_4)

## `cin`と`cout`を定義
`vector`とか`pair`，`set`を`cout`できるようにすると便利．
```cpp
//vector
template<class T> std::ostream &operator<<(std::ostream &out, const vector<T> &A){
    for(const T &a:A){
        cout<<a<<" ";
    }
    return out;
}
//pair
template<class T1,class T2> std::ostream &operator<<(std::ostream &out, const pair<T1,T2> &A){
    cout<<"{"<<A.first<<","<<A.second<<"}";
    return out;
}
//map
template<class T1,class T2> std::ostream &operator<<(std::ostream &out, const map<T1,T2> &M){
    for(const auto&A:M){
        cout<<"{"<<A.first<<","<<A.second<<"}";
    }
    return out;
}
//set
template<class T1> std::ostream &operator<<(std::ostream &out, const set<T1> &M){
    cout<<"{";
    for(const auto&A:M){
        cout<<A<<", ";
    }
    cout<<"}"<<endl;
    return out;
}
```
また，`cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl`は次の定義によって`print(a,b,c,d)`で書ける(厳密には余計な空白が入るので注意)．
```cpp
void print() { cout << endl; }
 
template <typename Head, typename... Tail>
void print(Head H, Tail... T) {
  cout << H << " ";
  print(T...);
}
```
