/*
GridをGraphに変換
verify
https://atcoder.jp/contests/math-and-algorithm/submissions/34995733
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
struct GridGraph{
    int H,W;
    Graph G;
    vector<vector<int>> A;
    vector<long> D;
    GridGraph(int h,int w){
        H = h;
        W = w;
        init();
    }
    void init(){
        D.clear();
        G.clear();
        A.clear();
        G.resize(H*W);
        A.resize(H);
        for(int i=0;i<H;i++){
            A[i].resize(W);
        }
    }
    void in(){
        map<char,int> mp = {{'.',0},{'#',1}};
        for(int i=0;i<H;i++){
            string S;cin>>S;
            for(int j=0;j<W;j++){
                A[i][j] = mp[(S[j])];
            }
        }
    }
    void build(){
        static vector<int> dx = {1,0};
        static vector<int> dy = {0,1};
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                for(int a=0;a<(int)dx.size();a++){
                    int h = i + dy[a];
                    int w = j + dx[a];
                    if(h<0||w<0||h>=H||w>=W)continue;
                    if(A[h][w]==A[i][j]&&A[h][w]==0){
                        int x = toInt(i,j);
                        int y = toInt(h,w);
                        G[x].push_back({y,1});
                        G[y].push_back({x,1});
                    }
                }
            }
        }
    }
    void calc(int h,int w){
        dijkstra(toInt(h,w),G,D);
    }
    int toInt(int h,int w){
        return W*h + w;
    }
    long getDis(int h,int w){
        return D[toInt(h,w)];
    }
};

int main(){
    int H,W;cin>>H>>W;
    int sy,sx,gy,gx;cin>>sy>>sx>>gy>>gx;
    sy--;sx--;gy--;gx--;
    GridGraph grid(H,W);
    grid.in();
    grid.build();
    grid.calc(sy,sx);
    cout<<grid.getDis(gy,gx)<<endl;
}
