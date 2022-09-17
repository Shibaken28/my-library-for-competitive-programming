/*
imos

verify
https://atcoder.jp/contests/abc014/submissions/34912295
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


template<class T> struct Imos{
    vector<T> A;
    int N;
    constexpr Imos(int N){
        this -> N = N;
        init();
    }
    constexpr void init(){
        A.resize(N+1);
        fill(A.begin(),A.end(),0);
    }
    /*[l,r]にxを加算*/
    constexpr void add(int l,int r,T x){
        A[l] += x;
        A[r+1] += -x;
    }
    constexpr void calc(){
        for(int i=0;i<N;i++){
            A[i+1] += A[i];
        }
    }
    constexpr T get(int i){
        return A[i];
    }
};

int main(){
    int N;cin>>N;
    Imos<int> imos(1000001);
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        imos.add(a,b,1);
    }
    imos.calc();
    cout<< *(max_element(imos.A.begin(),imos.A.end())) << endl;
}
