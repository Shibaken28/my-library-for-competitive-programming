# 累乗根
## 概要
\\(y,n\\)から\\(x^n\leq y\\)を満たすような最大の整数\\(x\\)を求める．
## 計算量
\\(O(\log N)\\)
## ソースコード
```cpp
long iroot(long y,int n){
    //x^n <= yとなる最大のn
    long ok = 0;
    long ng = y+1;
    while(abs(ok-ng)>1){
        long mid = (ok+ng)/2;
        long x = 1;
        bool inf = false;
        for(int i=0;i<n;i++){
            if(((long)1e18)/x < mid)inf = true;
            x *= mid;
        }
        if(inf||x>y){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return ok;
}
```
