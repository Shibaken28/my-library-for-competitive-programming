# C++の仕様や便利機能


## 参考になった資料
- [C++11実践復習(β)](https://zenn.dev/tetsurom/books/restart-cpp11/viewer/range-for-loops)
- [ラムダ式で再帰をする](https://koturn.hatenablog.com/entry/2018/06/10/060000)

## Makefile
オプションをつけないとC++17でコンパイル**されない**．構造体束縛とかが使えなくて泣く．
毎回オプションを付けるのは面倒なので，Makefileを作っておくと便利．
```makefile
#Makefile
CC=g++
CFLAGS=-Wall -std=c++17
.SUFFIXES = .cpp
objs:=$(wildcard *.cpp)
targets:=$(objs:.cpp= )

.PHONY:all
all: $(targets)
.cpp:
	$(CC) $(CFLAGS) -o $@ $<
```

## 構造体束縛
[C++日本語リファレンス](https://cpprefjp.github.io/lang/cpp17/structured_bindings.html)よりコードを引用
```cpp
std::pair<int, std::string> f()
{
  return {3, "Hello"};
}

// 関数f()の戻り値である整数と文字列の組を分解する。
// pairのfirstをid変数に代入し、secondをmessage変数に代入する。
// id変数の型はfirstの型(int)となり、message変数の型はsecondの型(string)となる。
auto [id, message] = f();
```
これにより，pair型などで受け取って中身をいちいち別の変数に取り出す手間がなくなる．

`map`の値の取り出しでも重宝する．
```cpp
map<int,int> mp;
for(auto [key,value]:mp){
    //key,valueを使う
    cout<<key<<" "<<value<<endl;
}
```

## ラムダ式
関数に関数を渡すときに便利．構文は次の通り．
```cpp
[キャプチャする変数](引数){ 関数の本体 }
```
型名はよくわかんないので`auto`に任しておく．
```cpp
auto pow = [](int a){return a*a;}; //引数aを受け取ってa*aを返す関数
cout<<pow(4)<<endl; //16
```
ラムダ式の中で外の変数を使いたい場合はキャプチャする．
```cpp
int x=4;
auto mul = [x](int a){return x*a;};
cout<<mul(3)<<endl; //12
```
`&`を付けると参照キャプチャになる．他にもキャプチャの種類があるがここでは紹介しない．
```cpp
int x=4;
auto mul = [&x](int a){return x*a;};
cout<<mul(3)<<endl; //12
```

## `cin`と`cout`を定義
`vector`とか`pair`，`set`を`cout`できるようにすると便利(これをまとめて書く方法を知っている方がいれば教えてください)．
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



