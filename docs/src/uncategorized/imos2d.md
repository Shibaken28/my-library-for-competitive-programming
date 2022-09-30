# 2次元imos法

## 概要
## ソースコード
```cpp
template<class T> struct Imos2d{
    vector<vector<T>> A;
    int H,W;
    constexpr Imos2d(int H,int W){
        this->H = H;
        this->W = W;
        init();
    }
    constexpr void init(){
        A.resize(H+1);
        for(int i=0;i<=H;i++){
            A[i].resize(W+1);
            fill(A[i].begin(),A[i].end(),0);
        }
    }
    /*四角形にxを加算*/
    constexpr void add(int ly,int lx,int ry,int rx,T x){
        A[ly][lx] += x;
        A[ry+1][lx] += -x;
        A[ly][rx+1] += -x;
        A[ry+1][rx+1] += x;
    }
    constexpr void calc(){
        for(int h=0;h<=H;h++){
            for(int w=0;w<W;w++){
                A[h][w+1] += A[h][w];
            }
        }
        for(int h=0;h<H;h++){
            for(int w=0;w<=W;w++){
                A[h+1][w] += A[h][w];
            }
        } 
    }
    constexpr T get(int y,int x){
        return A[y][x];
    }
};
```