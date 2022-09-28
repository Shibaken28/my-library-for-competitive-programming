# 素数判定
## 概要
素数かどうかを判定する．
## 計算量
\\(O(\sqrt{N})\\)

```cpp
bool isPrime(long N){
    if(N<=1)return false;
    for(long i=2;i*i<=N;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}
```
