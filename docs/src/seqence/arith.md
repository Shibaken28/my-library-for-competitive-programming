# 等差数列
## 概要
\\(O(1)\\)で等差数列の次の項目を求める．
- 第\\(n\\)項までの和
- 第\\(n\\)項はいくつか
- 第\\(l\\)項目から第\\(r\\)項目までの和
- \\(b\\)は何項目であるか
## ソースコード
```cpp
//初項s公差d第n項までの和
long arithSum(long a,long d,long n){
    return n*(2*a+(n-1)*d)/2;
}

//初項s公差dの第n項
long arith(long a,long d,long n){
    return a + d*(n-1);
}

//初項a公差d第l項から第r項までの和
long arithSumRange(long a,long d,long l,long r){
    //第l項が初項となるような数列を作る．
    return arithSum(arith(a,d,l),d,r-l+1);
}

//初項aで公差dのときbは第何項であるか．
long arithWhere(long a,long d,long b){
    if(d==0){
        if(a==b)return 1;
        return -1;
    }
    // a+d*(n-1) = bとなるようなnが存在するか
    // a + dn - d = b
    // n = (b + d - a)/d
    if((b+d-a)%d==0 && (b+d-a)/d > 0 )return (b+d-a)/d;
    return -1;
}

```
## 実行例
```cpp
int main(void){
    long a,d;
    /*
        a = 2
        d = 3
        2,5,8,11,14,17,20,...
    */
    a = 2,d = 3;
    cout<<arith(a,d,4)<<endl;
    cout<<arithSum(a,d,5)<<endl;
    cout<<arithSumRange(a,d,3,6)<<endl;
    cout<<arithWhere(a,d,20)<<endl;
    /*
        a = 10
        d = -5
        10,5,0,-5,-10,-15,...
    */
    a = 10,d = -5;
    cout<<arith(a,d,4)<<endl;
    cout<<arithSum(a,d,5)<<endl;
    cout<<arithSumRange(a,d,3,6)<<endl;
    cout<<arithWhere(a,d,15)<<endl;

    deque<int> qu
}
```
実行結果
```cpp
11
40
50
7
-5
0
-30
-1
```
