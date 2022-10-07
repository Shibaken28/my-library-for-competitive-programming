# 木の直径
## 概要
最も離れた$2$点の距離を木の直径と呼ぶ．頂点数を$V$とすると$O(V)$で求める．

## ソースコード
中身はDFSを2回するだけ．
```cpp
struct Edge{
    int to;
};

using Graph = vector<vector<Edge>>;

void dfs(Graph &G,int v,int p,int d,vector<int>&dist){
    dist[v]=d;
    for(auto&e:G[v]){
        if(e.to==p)continue;
        dfs(G,e.to,v,d+1,dist);
    }
}

int treeDiameter(Graph &Tree){
    int N = Tree.size();
    vector<int> dist(N,-1);
    dfs(Tree,0,-1,0,dist);
    int farthest = max_element(all(dist))-dist.begin();
    vector<int> dist2(N,-1);
    dfs(Tree,farthest,-1,0,dist2);
    return *max_element(all(dist2));
}
```
