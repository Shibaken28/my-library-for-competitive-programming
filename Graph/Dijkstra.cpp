
/*
ダイクストラ法
Verify
https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
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

struct Edge{
    int to;
    long cost;
};

struct WeightedVertex{
    int v;
    long cost;
};

using Graph = vector<vector<Edge>>; //隣接グラフ


/*
ダイクストラ法
重みはlong型
始点s，グラフGの点をDに
*/
void dijkstra(int s,Graph &G,vector<long>&D){
    auto comp = [](WeightedVertex &l,WeightedVertex &r){return l.cost > r.cost;};
    priority_queue < 
        WeightedVertex,
        vector<WeightedVertex>,
        function<bool(WeightedVertex&,WeightedVertex&)>
        > qu (comp);
    D.resize(G.size());
    fill(D.begin(),D.end(),-1);
    D[s] = 0;
    qu.push({s,0});
    while(!qu.empty()){
        auto a = qu.top(); qu.pop();
        int from = a.v;
        for(auto&e:G[from]){
            if(D[e.to] == -1 || D[e.to] > D[from] + e.cost){
                D[e.to] = D[from] + e.cost;
                qu.push({e.to,D[e.to]});
            }
        }
    }
}

int main(){
    int N,M,r;cin>>N>>M>>r;
    Graph G(N);
    for(int i=0;i<M;i++){
        int u,v;
        long w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
    }
    vector<long> D(N);
    dijkstra(r,G,D);
    for(int i=0;i<N;i++){
        if(D[i] == -1){
            cout<<"INF"<<endl; 
        }else{
            cout<<D[i]<<endl; 
        }
    }
}
