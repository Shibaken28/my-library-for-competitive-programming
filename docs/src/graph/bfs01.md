# 01BFS
辺の重みが$0,1$のどちらかであるようなグラフで，頂点$s$からの最短距離を効率よく求めるアルゴリズム．

## 計算量
$O(V+E)$

## ソースコード

```cpp
struct Edge{
    int from;
    int to;
    long cost;
};

using Graph = vector<vector<Edge>>;
/*01BFS*/
void bfs01(Graph &G,int s,vector<long>&dist){
    int n = G.size();
    dist.assign(n,INFl);
    deque<int> que;
    dist[s] = 0;
    que.push_back(s);
    while(!que.empty()){
        int v = que.front();
        que.pop_front();
        for(auto &e:G[v]){
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                if(e.cost == 0){
                    que.push_front(e.to);
                }else{
                    que.push_back(e.to);
                }
            }
        }
    }
}
```