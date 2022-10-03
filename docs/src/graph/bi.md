# ❌2部グラフ判定
## 概要
2部グラフであるかを判定する．
## アルゴリズム
BFSで隣り合う頂点を異なる2色で塗っていき，最後に全ての隣り合う頂点が異なる色で塗られているかを判定する．計算量は$O\log(V+E)$

## ソースコード
```cpp
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
```
