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
    std::cin.tie(0)->sync_with_stdio(0);
    auto x=quad(1,2,1);//x^2+2x+1=0
    cout<<x<<endl;// {-1}
    x=quad(1,2,2);//x^2+2x+2=0
    cout<<x<<endl;// {}
    x=quad(2,-12,-182);//2x^2-12x-182=0
    cout<<x<<endl;//{13,-7}
}
