# 2次方程式

## 概要
$x$に関する方程式$ax^2+bx+c=0$を整数の範囲で代数的に解く．

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

//整数の範囲でax^2+bx+c=0を解く
vector<long> quad(long a,long b,long c){
    long d=b*b-4*a*c;
    if(d<0)return {}; //解なし
    long sqrtd=iroot(d,2);
    if(sqrtd*sqrtd!=d)return {}; //整数解はない
    if((sqrtd-b)%2!=0)return {}; //整数解はない
    if(sqrtd==0)return {(-b)/(2*a)}; //重解
    return {(-b+sqrtd)/(2*a),(-b-sqrtd)/(2*a)};
}


int main(void){
    auto x=quad(1,2,1);//x^2+2x+1=0
    cout<<x<<endl;// {-1}
    x=quad(1,2,2);//x^2+2x+2=0
    cout<<x<<endl;// {}
    x=quad(2,-12,-182);//2x^2-12x-182=0
    cout<<x<<endl;//{13,-7}
}
```
