
/*
ベルマンフォード法
Verify
https://atcoder.jp/contests/abc061/submissions/34873553
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
    int from;
    int to;
    long cost;
};

struct WeightedVertex{
    int v;
    long cost;
};

using Graph = vector<vector<Edge>>; //隣接グラフ

const long INF = 1e17; 

/*
ダイクストラ法
重みはlong型
始点s，グラフGの点をDに
戻り値は **sからgの経路** を作るときに重みが負の無限になるか
*/
bool bellmanFord(int s,int g,Graph &G,vector<long>&D){
    const int N = G.size();
    vector<Edge>edges;
    for(auto A:G){
        for(Edge& a:A){
            edges.push_back(a);
        }
    }
    fill(D.begin(),D.end(),INF);
    D[s] = 0;
    for(int i=0;i<=N;i++){
        for(auto&e:edges){
            long d = D[e.from] + e.cost;
            if(D[e.from] < INF && D[e.to] > d){
                D[e.to] = d;
                if(i==N&&e.to==g){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int N,M;cin>>N>>M;
    Graph G(N);
    for(int i=0;i<M;i++){
        int u,v;
        long w;
        cin>>u>>v>>w;
        u--;v--;
        G[u].push_back({u,v,-w});
    }
    vector<long> D(N);
    if(bellmanFord(0,N-1,G,D)){
        cout<<"inf"<<endl;
        return 0;
    }
    cout<<-D[N-1]<<endl;
}
