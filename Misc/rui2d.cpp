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

//#include<atcoder/modint>
//using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define repl(i,l,r) for (int i = l; i < (int)(r); i++)
#define all(a) a.begin(),a.end()
#define Pii pair<int,int>
#define Pll pair<long,long>
#define INFi 1000000001
#define INFl 1000000000000000001
#define ll long long
using namespace std;



template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> void printArray(vector<T>&A){
    for(T&a:A){
        cout<<a<<" ";
    }
    cout<<endl;
}
template<class T> void printArrayln(vector<T>&A){
    for(T&a:A){
        cout<<a<<endl;
    }
}


template<class T1,class T2> std::ostream &operator<<(std::ostream &out, const pair<T1,T2> &A){
    cout<<"{"<<A.first<<","<<A.second<<"}";
    return out;
}

template<class T1,class T2> std::ostream &operator<<(std::ostream &out, const map<T1,T2> &M){
    for(const auto&A:M){
        cout<<"{"<<A.first<<","<<A.second<<"}";
    }
    return out;
}

template<class T1> std::ostream &operator<<(std::ostream &out, const set<T1> &M){
    cout<<"{";
    for(const auto&A:M){
        cout<<A<<", ";
    }
    cout<<"}"<<endl;
    return out;
}


template<class T1> std::ostream &operator<<(std::ostream &out, const multiset<T1> &M){
    cout<<"{";
    for(const auto&A:M){
        cout<<A<<", ";
    }
    cout<<"}"<<endl;
    return out;
}

template<class T> std::ostream &operator<<(std::ostream &out, const vector<T> &A){
    for(const T &a:A){
        cout<<a<<" ";
    }
    return out;
}

void print() { cout << endl; }
 
template <typename Head, typename... Tail>
void print(Head H, Tail... T) {
  cout << H << " ";
  print(T...);
}


template<class T> std::istream &operator>>(std::istream &in,vector<T>&A){
    for(T&a:A){
        std::cin>>a;
    }
    return in;
}

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



int main(void){
    CumulativeSum2D<int>cs(3,3);
    cs.add(0,0,1);
    cs.add(0,1,2);
    cs.add(0,2,3);
    cs.add(1,0,4);
    cs.add(1,1,5);
    cs.build();
    cout<<cs.sum(0,0,3,3)<<endl;
    return 0;
}

/*
verify
https://onlinejudge.u-aizu.ac.jp/problems/0516
*/
