# ベルマンフォード法

## 概要
2頂点間のパスの内の辺の重みの総和が最小となる値を求めるアルゴリズム

ダイクストラと違って負の辺がある場合も正しく動作，負の閉路の検出ができる．
## 計算量
頂点数を\\(V\\)，辺の数を\\(E\\)とすると，\\(O(VE)\\) である．

全ての頂点から全ての辺を見ているため．

```cpp
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
```

