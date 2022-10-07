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

//dfsの行きがけ順
void preorder(const Graph &G,int n,int p,vector<bool>&visited,vector<int>&order){
    visited[n]=true;
    order.push_back(n);
    for(auto&e:G[n]){
        if(e.to==p)continue;
        if(visited[e.to])continue;
        preorder(G,e.to,n,visited,order);
    }
}

//dfsの帰りがけ順
void postorder(const Graph &G,int n,int p,vector<bool>&visited,vector<int>&order){
    visited[n]=true;
    for(auto&e:G[n]){
        if(e.to==p)continue;
        if(visited[e.to])continue;
        postorder(G,e.to,n,visited,order);
    }
    order.push_back(n);
}

void eulerTour(const Graph &G,int n,int p,vector<bool>&visited,vector<int>&order){
    visited[n]=true;
    order.push_back(n);
    for(auto&e:G[n]){
        if(e.to==p)continue;
        if(visited[e.to])continue;
        eulerTour(G,e.to,n,visited,order);
        order.push_back(n);
    }
}

int main(void){
    std::cin.tie(0)->sync_with_stdio(0);
    int N,A;cin>>N>>A;
    Graph G(N);
    rep(i,N-1){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }
    vector<bool>visited(N,false);
    vector<int>order;
    eulerTour(G,0,-1,visited,order);
    for(int i=0;i<order.size();i++){
        cout<<order[i]+1<<" ";
    }
}
