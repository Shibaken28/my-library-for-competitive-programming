//https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C

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

struct Edge{
    int to;
};

using Graph = vector<vector<Edge>>;

struct LA{
    Graph G;
    vector<vector<int>> ancestor;
    //ancestor[i][j]:=頂点iの2^j個親
    vector<int> depth;//深さ
    int N;
    int root = 0;
    const int maxDepth = 25;
    LA(int _N){
        this-> N = _N;
        init();
    }
    void init(){
        G.resize(N);
        depth.resize(N);
        ancestor.resize(N);
        for(int i=0;i<N;i++){
            ancestor[i].resize(maxDepth);
        }
    }
    void build(){
        ancestor[root][0] = root;
        bfs(root,0,0);
        for(int i=1;i<maxDepth;i++){
            for(int j=0;j<N;j++){
                ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
            }
        }
    }
    void bfs(int n,int pre,int d){
        depth[n] = d;
        ancestor[n][0] = pre;
        for(auto&E:G[n]){
            if(E.to==pre)continue;
            bfs(E.to,n,d+1);
        }
    }
    //頂点nのs個先の祖先
    int anc(int n,int s){
        for(int i=0;i<maxDepth;i++){
            if(s&(1<<i)){
                n = ancestor[n][i];
            }
        }
        return n;
    }
    //頂点nの深さs(root=0)の祖先
    int levelAnc(int n,int s){
        return anc(n,depth[n]-s);
    }
    //頂点a,bの共通最近祖先
    int lca(int a,int b){
        if(depth[a]<depth[b])swap(a,b);
        a = levelAnc(a,depth[b]);//同じ深さにする
        if(a==b)return a;
        for(int k=maxDepth-1;k>=0;k--){
            if(ancestor[a][k]!=ancestor[b][k]){
                a = ancestor[a][k];
                b = ancestor[b][k];
            }
        }
        return ancestor[a][0];
    }
};


int main(void){
    int N;cin>>N;
    LA la(N);
    for(int i=0;i<N;i++){
        int k;cin>>k;
        for(int a=0;a<k;a++){
            int c;cin>>c;
            la.G[i].push_back({c});
            la.G[c].push_back({i});
        }
    }
    la.build();
    int Q;cin>>Q;
    vector<int> ans;
    for(int i=0;i<Q;i++){
        int a,b;cin>>a>>b;
        ans.push_back(la.lca(a,b));
    }
    for(auto&a:ans)cout<<a<<endl;
}
