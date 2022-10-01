# 約数列挙
## 概要
正の整数$N$の約数を列挙する
## 計算量
$O(\sqrt{N})$

## ソースコード
```cpp
//約数列挙
vector<long> divisor(long x){
    vector<long> f(0);
    for(long i=1;i*i<=x;i++){
        if(x%i==0){
            f.push_back(i);
            if(i!=x/i)f.push_back(x/i);
        }
    }
    sort(f.begin(),f.end());
    return f;
}
```

