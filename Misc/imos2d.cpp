/*
2次元imos

verify
https://atcoder.jp/contests/typical90/submissions/34913042
*/

#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>
#include <climits>
#include <cmath>
#include <functional>
#include <numeric>
#include <regex>
#include <array>
#include <fstream>
#include <sstream>
using namespace std;


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

int main(){
    int N;cin>>N;
    Imos2d<int> imos(1004,1004);
    for(int i=0;i<N;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        imos.add(b,a,d-1,c-1,1);
    }
    imos.calc();
    vector<int> A(N+1,0);
    for(int i=0;i<=1000;i++)for(int j=0;j<=1000;j++){
        A[imos.get(i,j)]++;
    }
    for(int i=1;i<=N;i++)cout<<A[i]<<endl;
}
