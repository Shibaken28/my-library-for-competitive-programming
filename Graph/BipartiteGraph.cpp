/*
2部グラフ判定

https://atcoder.jp/contests/math-and-algorithm/submissions/34995984
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
};

using Graph = vector<vector<Edge>>; //隣接グラフ


/*
ダイクストラ法
重みはlong型
始点s，グラフGの点をDに
*/
void bfs(int n,int pre,Graph &G,vector<int>&C){
    for(auto&e:G[n]){
        if(C[e.to]!=-1)continue;
        C[e.to] = 1-C[n];
        bfs(e.to,n,G,C);
    }
}

int main(){
    int N,M;cin>>N>>M;
    Graph G(N);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        G[u].push_back({v});
        G[v].push_back({u});
    }
    vector<int>C(N,-1);
    for(int i=0;i<N;i++){
        if(C[i] != -1)continue;
        C[i]=0;
        bfs(i,-1,G,C);
    }
    bool ok = true;
    for(int i=0;i<N;i++){
        //cout<<i<<" "<<C[i]<<endl;
        for(auto&e:G[i]){
            if(C[e.to] == C[i]){
                ok = false;
            }
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
}
