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
[キャプチャする変数](引数) -> 戻り値の型 { 関数の本体 }
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




