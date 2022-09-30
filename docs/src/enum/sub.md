# ビットの部分集合列挙

## 概要
ある非負整数\\(x\\)があるとき，\\(x|a =x\\)となるような\\(a\\)を列挙する
## ソースコード
```cpp
vector<long> bitsub(long x){
    vector<long> A(0);
    //xの部分集合
    for(long T=x; ; T=(T-1)&x) {
        if(T==0)break;
        A.push_back(T);
    }
    return A;
}
```
