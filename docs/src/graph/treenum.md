# 木の巡回
## 概要
木の頂点に番号を振る．

## DFSの順
### ソースコード
```cpp
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
```

## BFSの順
### ソースコード
```cpp
```

