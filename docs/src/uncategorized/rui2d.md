# 2次元累積和
## 概要
$H$行$W$列の行列があり，各要素を$A_{ij}$とする．このとき，前処理を行うことで，次の値を$O(1)$で求めることができる．
$$
\sum\_{h_1\leq i< h_2}\sum\_{w_1\leq j<w_2} A_{ij}
$$
## 計算量
- 構築: $O(HW)$
- クエリ: $O(1)$

## ソースコード
```cpp
template<class T> struct CumulativeSum2D{
    size_t H,W;
    vector<vector<T>>data,A;
    CumulativeSum2D(size_t H,size_t W){
        this->H=H;
        this->W=W;
        data.resize(H+1,vector<T>(W+1,0));
        A.resize(H+1,vector<T>(W+1,0));
    }
    void add(size_t h,size_t w,T x){
        A[h][w]+=x;
    }
    void build(){
        int H=A.size();
        int W=A[0].size();
        data=vector<vector<T>>(H+1,vector<T>(W+1,0));
        rep(i,H){
            rep(j,W){
                data[i+1][j+1]=A[i][j];
            }
        }
        rep(i,H+1){
            rep(j,W){
                data[i][j+1]+=data[i][j];
            }
        }
        rep(i,H){
            rep(j,W+1){
                data[i+1][j]+=data[i][j];
            }
        }
    }
    /*w1<=x<w2, h1<=y<h2*/
    T sum(int h1,int w1,int h2,int w2){
        return data[h2][w2]-data[h1][w2]-data[h2][w1]+data[h1][w1];
    }
};
```
