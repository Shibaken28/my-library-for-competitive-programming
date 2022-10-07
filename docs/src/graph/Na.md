# N頂点N辺グラフ分析

## 概要
連結な$N$頂点$N$辺無向グラフは閉路が必ず$1$つできる．
その一つの閉路を$O(N)$で求める．このようなグラフは俗になもりグラフと呼ばれる．
## ソースコード
自己ループには対応していない．
```cpp
struct Edge{
    int to;
};

using Graph = vector<vector<Edge>>;

void dfs(Graph&G,int n,vector<int> &pre,int &x){
    for(Edge&e:G[n]){
        if(e.to==pre[n])continue;
        if(pre[e.to]==-1){
            pre[e.to]=n;
            dfs(G,e.to,pre,x);
        }else{
            x = n;
        }
    }
}

vector<int> namori(Graph graph){
    //なもりグラフの閉路に含まれる頂点を返す
    int n=(int)graph.size();
    vector<int> res;
    vector<int> pre(n,-1);//前回の頂点
    int x=-1;
    dfs(graph,0,pre,x);
    cout<<x<<endl;
    if(x==-1)return res;
    int y=pre[x];
    while(x!=y){
        res.push_back(y);
        y=pre[y];
    }
    res.push_back(x);
    return res;
}
```

