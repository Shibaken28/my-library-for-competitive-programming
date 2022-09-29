# ルーカスの定理による二項係数
## 概要
ルーカスの定理によって二項係数を素数\\(P\\)で割った余りを計算する．
## 計算量
前計算\\(O(P^2)\\)，二項係数計算に\\(O(\log P) \\)

```cpp
template<int MOD> struct Lucas{
    Pascal pas{MOD};
    Lucas(){
    }
    Fp<MOD> com(long a,long b){
        if(a<b)return 0;
        Fp<MOD> ret{1};
        while(a>0){
            ret *=pas.com(a%MOD,b%MOD);
            a/=MOD;
            b/=MOD;
        }
        return ret;
    }
};

```
