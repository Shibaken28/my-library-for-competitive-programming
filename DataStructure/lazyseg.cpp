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
#define ZEROi 1000000001
#define ZEROl 1000000000000000001
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

template<typename X,typename M> struct LazySegmentTree{
    public:
        using FX = function<X(X, X)>;
        using FA = function<X(X, M)>;
        using FM = function<M(M, M)>;
        using FP = function<M(M, int)>;
        int n;
        FX fx;
        FA fa;
        FM fm;
        FP fp;
        const X ex;
        const M em;
        vector<X> dat;
        vector<M> lazy;
    LazySegmentTree(int n_,FX fx_,FA fa_,FM fm_,FP fp_,X ex_,M em_):n(n_),fx(fx_),fa(fa_),fm(fm_),fp(fp_),ex(ex_),em(em_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,ex);
        lazy.assign(2*n-1,em);
    }
    void set(int k,X x){
        dat[k+n-1]=x;
    }
    void build(){
        for(int k=n-2;k>=0;k--){
            dat[k]=fx(dat[2*k+1],dat[2*k+2]);
        }
    }
    void update(int a,int b,M x,int k,int l,int r){
        eval(k,r-l);
        if(a <= l && r <= b){
            lazy[k]= fm(lazy[k],x);
            eval(k,r-l);
        }else if(a < r && l < b){
            update(a,b,x,k*2+1,l,(l+r)/2);
            update(a,b,x,k*2+2,(l+r)/2,r);
            dat[k]=fx(dat[k*2+1],dat[k*2+2]);
        }
    }
    void update(int k,M a){
        update(k,k+1,a,0,0,n);
    }
    void update(int a,int b,M x){
        update(a,b,x,0,0,n);
    }
    void eval(int k,int len){
        if(lazy[k]==em)return;
        if(k<n-1){
            lazy[k*2+1]=  fm(lazy[k*2+1],lazy[k]);
            lazy[k*2+2] = fm(lazy[k*2+2],lazy[k]);
        }
        dat[k]=fa(dat[k],fp(lazy[k],len));
        lazy[k]=em;
    }
    X query(int a,int b,int k,int l,int r){
        eval(k,r-l);
        if(r<=a||b<=l)return ex;//範囲外
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            X vl=query(a,b,k*2+1,l,(l+r)/2);
            X vr=query(a,b,k*2+2,(l+r)/2,r);
            return fx(vl,vr);
        }
    }
    X query(int a,int b){
        return query(a,b,0,0,n);
    }
    X get(int k){
        return query(k,k+1);
    }
};

int main(void){
    int N;cin>>N;
    using X = long;
    using M = long;
    auto fx = [](X a,X b){return a+b;};
    auto fa = [](X a,M b){return b;};
    auto fm = [](M a,M b){return b;};
    auto fp = [](M a,int b){return a*(long)b;};
    X ex = 0; //加算の単位元
    M em = 1237615273123L; //更新クエリの単位元
    LazySegmentTree<X,M> seg(N,fx,fa,fm,fp,ex,em);
    for(int i=0;i<N;i++){
        seg.set(i,0);//初期化
    }
    seg.build();
    int Q;cin>>Q;
    for(int i=0;i<Q;i++){
        int com;cin>>com;
        if(com==0){
            long s,t,x;cin>>s>>t>>x;
            seg.update(s,t+1,x);
        }else{
            long s,t;cin>>s>>t;
            cout<<seg.query(s,t+1)<<endl;
        }
    }
}


