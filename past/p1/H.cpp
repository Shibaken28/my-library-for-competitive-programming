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


int main(void){
    long N;cin>>N;
    vector<long>C(N);cin>>C;
    int Q;cin>>Q;
    long cnt = 0;
    long odd = 0,sum = 0;
    long minOdd = INFl,minEven = INFl;
    rep(i,N){
        if(i%2==1){//偶数
            chmin(minEven,C[i]);
        }else{
            chmin(minOdd,C[i]);
        }
    }
    rep(i,Q){
        int t;cin>>t;
        if(t==1){
            long x,a;cin>>x>>a;
            x--;
            if(x%2==0){//奇数
                if(C[x]-odd-sum-a>=0){
                    C[x]-=a;
                    cnt+=a;
                    chmin(minOdd,C[x]);
                }
            }else{
                if(C[x]-sum-a>=0){
                    C[x]-=a;
                    cnt+=a;
                    chmin(minEven,C[x]);
                }
            }
        }else if(t==2){
            long a;cin>>a;
            if(minOdd-odd-sum-a>=0){
                odd+=a;
                cnt+=a*((N+1)/2);
            }
        }else if(t==3){
            long a;cin>>a;
            if(minOdd-odd-sum-a>=0 && minEven-sum-a>=0){
                sum+=a;
                cnt+=a*N;
            }
        }
    }
    cout<<cnt<<endl;
}


