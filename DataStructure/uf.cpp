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

struct UnionFind{
    public:
    vector<int> par;//親
    vector<long> weight;//重み
    vector<long> weightAlone;//単体の重み
    UnionFind(int n):par(n),weight(n),weightAlone(n){
        for(int i=0;i<n;i++){
            par[i]=i; //親は自分自身にしておく
            weight[i] = weightAlone[i] = 1;
        }
    }
    //途中で実行すると壊れます
    void setWeight(int i,long w){
        weight[i] = weightAlone[i] = w;
    }
    //途中で実行しても大丈夫
    void changeWeight(int i,long w){
        long pre = weightAlone[i];
        weightAlone[i] = w;
        weight[root(i)] += w-pre;
    }
    int root(int x){
        if(par[x]==x){
            return x;
        }else{
            int r = root(par[x]);
            par[x]=r;
            return r;
        }
    }
    void unite(int x,int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry){
            return;
        }
        par[rx]=ry;
        weight[ry] += weight[rx];
    }
    bool same(int x,int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
    long getWeight(int x){
        return weight[root(x)];
    }
    vector<vector<int>> getGroups(){
        vector<vector<int>> res;
        map<int,vector<int>> mp;
        for(int i=0;i<(int)par.size();i++){
            mp[root(i)].push_back(i);
        }
        for(auto&[k,v]:mp){
            (void)k; //使いません
            res.push_back(v);
        }
        return res;
    }
};

int main(void){
    UnionFind uf(3);
    uf.unite(1,2);
    cout<<uf.getWeight(1)<<endl;
    uf.changeWeight(1,10);
    cout<<uf.getWeight(1)<<endl;
    uf.unite(0,1);
    cout<<uf.getWeight(1)<<endl;
}
