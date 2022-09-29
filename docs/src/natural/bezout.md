# 2元1次不定方程式
## 概要
非負整数\\(a,b\\)に対して\\(ax + by = 1\\) を解く．一般解が求められる．
## ソースコード
```cpp
// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long extGCD(long a, long b, long &x, long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
/*
ax + by = c の一般解
x = alpha t + beta
y = gamma t + delta
*/
bool Bezout(long a,long b,long c,long &alpha,long &beta,long &gamma,long &delta){
    long x=0,y=0;
    long gcd=extGCD(a,b,x,y);
    if(c%gcd!=0){
        return false;
    }
    x *= c/gcd;
    y *= c/gcd;
    gamma = a/gcd;
    delta = y;
    alpha = -b/gcd;
    beta = x;
    return true;
}

```
