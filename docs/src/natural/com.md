# 二項係数(mod)

## 概要
二項係数\\({}_a \mathrm{C}_b (0\leq a,b\leq N )\\)を素数\\(P\\)で割った余りを求める．

## 計算量
前計算\\(O(N\log P)\\)，クエリ\\(O(1)\\)

```cpp
template<class T> struct Combination{
    int N;
    vector<T> fac;//階乗
    vector<T> finv;//階乗の逆元
    Combination(int N){
        this->N = N;
        init();
    }
    void init(){
        fac.resize(N);
        finv.resize(N);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        for(int i=2;i<N;i++){
            fac[i] = fac[i-1] * i;
            finv[i] = finv[i-1] / i;
        }
    }
    /*aCbの計算*/
    T com(int a,int b){
        if(a < b)return 0;
        return fac[a] * finv[b] * finv[a-b];
    }
};

```