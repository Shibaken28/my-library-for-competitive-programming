# フィボナッチ数列の第n項
線形漸化式の第\\(n\\)項を求める様々な方法を紹介する．
ここでは例として，代表的な線形漸化式であるフィボナッチ数列の第\\(n\\)項を\\(\mod 10^9\\)で求めることにする．計算量は，\\(k\\)項間の線形漸化式の場合のものを示す．

## 愚直
第\\(3\\)項，第\\(4\\)項，第\\(5\\)項と定義通り順に求めていく方法．計算量は\\(O(kn)\\)．
第\\(n\\)項までの全ての項の値がほしいときに有効である．

```cpp
long N;cin>>N;
vector<mint> fibo={1,1};
for(int i=3;i<=N;i++){
    int a = (int)fibo.size();
    fibo.push_back(fibo[a-1]+fibo[a-2]);
}
cout<<fibo.back()<<endl;
```

## 行列累乗
ダブリングの考え方によって，\\(O(k^3\log n)\\)で求まる．
行列の掛け算自体がコストが高く，\\(k\\)が大きいときに時間がかかる．

```cpp
long N;cin>>N;
Matrix<mint> mat(2,2);
mat[0][0] = 1;
mat[0][1] = 1;
mat[1][0] = 1;
mat[1][1] = 0;
auto ans = pow(mat,N-1);
cout<<ans[0][0]<<endl;
```

## きたまさ法
これもダブリングである．
計算量は，\\(O(k^2\log n)\\)である．
[参考](https://outline.hatenadiary.jp/entry/2020/07/02/205628)(誤植がある気がする)

\\(k\\)項漸化式版は[こちら](https://atcoder.jp/contests/tdpc/submissions/35257624)．

```cpp

vector<mint> kitamasa(long n,const vector<mint>&d,const int k){
    //f(n)の係数ベクトルを求める．
    if(n==k){
        return d;
    }
    if(n&1||n<k*2){
        vector<mint> res(k);
        auto x1 = kitamasa(n-1,d,k);
        for(int i=0;i<k;i++){
            res[i] = d[i]*x1[k-1] + (i>0?x1[i-1]:0);
        }
        return res;
    }else{
        vector<mint> res(k,0);
        auto x0 = kitamasa(n/2,d,k);
        auto x1 = x0;
        for(int l=0;l<k;l++){//f(n/2+l)
            for(int j=0;j<k;j++){
                res[j] += x0[l]*x1[j];
            }
            vector<mint> next(k);
            for(int i=0;i<k;i++){
                next[i] = d[i]*x1[k-1] + (i>0?x1[i-1]:0);
            }
            swap(x1,next);
        }
        return res;
    }
}

int main(){
    vector<mint> d = {1,1};
    auto a = kitamasa(N-1,d,2);//N-1が2以下だと壊れる
    cout<<a[0]*d[0]+a[1]*d[1]<<endl;
}
```


