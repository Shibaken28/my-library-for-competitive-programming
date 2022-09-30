# Level Ancestor

## 概要
根つき木で，前計算を行うことで，ある頂点の\\(x\\)個先の祖先，ある頂点で深さが\\(d\\)である祖先を高速に求める．
## 計算量
頂点数を\\(N\\)とすると前計算\\(O(N\log N)\\)，各クエリ\\(O(\log N)\\)で動作．
## ソースコード

```cpp

struct Edge{
    int to;
};

using Graph = vector<vector<Edge>>;

struct LA{
    Graph G;
    vector<vector<int>> ancestor;
    //ancestor[i][j]:=頂点iの2^j個親
    vector<int> depth;//深さ
    int N;
    int root = 0;
    const int maxDepth = 25;
    LA(int _N){
        this-> N = _N;
        init();
    }
    void init(){
        G.resize(N);
        depth.resize(N);
        ancestor.resize(N);
        for(int i=0;i<N;i++){
            ancestor[i].resize(maxDepth);
        }
    }
    void build(){
        ancestor[root][0] = root;
        bfs(root,0,0);
        for(int i=1;i<maxDepth;i++){
            for(int j=0;j<N;j++){
                ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
            }
        }
    }
    void bfs(int n,int pre,int d){
        depth[n] = d;
        ancestor[n][0] = pre;
        for(auto&E:G[n]){
            if(E.to==pre)continue;
            bfs(E.to,n,d+1);
        }
    }
    //頂点nのs個先の祖先
    int anc(int n,int s){
        for(int i=0;i<maxDepth;i++){
            if(s&(1<<i)){
                n = ancestor[n][i];
            }
        }
        return n;
    }
    //頂点nの深さs(root=0)の祖先
    int levelAnc(int n,int s){
        return anc(n,depth[n]-s);
    }
};
```
