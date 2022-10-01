# 素因数分解
## 概要
$2$以上の正の整数$N$の素因数分解する
## 計算量
$O(\sqrt{N})$

## ソースコード
```cpp
//素因数分解
vector<long> factor(long x){
    vector<long> f(0);
    for(long i=2;i*i<=x;i++){
        if(x%i==0){
            f.push_back(i);
            x/=i;
            i--;
        }
    }
    if(x>1)f.push_back(x);
    return f;
}

//素因数分解2
// (素数,指数) のpair
vector<pair<long,long>> factor2(long x){
    auto f = factor(x);
    vector<pair<long,long>> f2(0);
    for(auto a:f){
        if(f2.empty()){
            f2.push_back({a,1});
        }else if(f2.back().first==a){
            f2.back().second ++;
        }else{
            f2.push_back({a,1});
        }
    }
    return f2;
}
```
