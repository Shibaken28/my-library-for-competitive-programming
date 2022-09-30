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

//初項s公差d第n項までの和
long arithSum(long a,long d,long n){
    return n*(2*a+(n-1)*d)/2;
}

//初項s公差dの第n項
long arith(long a,long d,long n){
    return a + d*(n-1);
}

//初項a公差d第l項から第r項までの和
long arithSumRange(long a,long d,long l,long r){
    //第l項が初項となるような数列を作る．
    return arithSum(arith(a,d,l),d,r-l+1);
}

//初項aで公差dのときbは第何項であるか．
long arithWhere(long a,long d,long b){
    if(d==0){
        if(a==b)return 1;
        return -1;
    }
    // a+d*(n-1) = bとなるようなnが存在するか
    // a + dn - d = b
    // n = (b + d - a)/d
    if((b+d-a)%d==0 && (b+d-a)/d > 0 )return (b+d-a)/d;
    return -1;
}



int main(void){
    long a,d;
    /*
        a = 2
        d = 3
        2,5,8,11,14,17,20,...
    */
    a = 2,d = 3;
    cout<<arith(a,d,4)<<endl;
    cout<<arithSum(a,d,5)<<endl;
    cout<<arithSumRange(a,d,3,6)<<endl;
    cout<<arithWhere(a,d,20)<<endl;
    /*
        a = 10
        d = -5
        10,5,0,-5,-10,-15,...
    */
    a = 10,d = -5;
    cout<<arith(a,d,4)<<endl;
    cout<<arithSum(a,d,5)<<endl;
    cout<<arithSumRange(a,d,3,6)<<endl;
    cout<<arithWhere(a,d,15)<<endl;
    
}