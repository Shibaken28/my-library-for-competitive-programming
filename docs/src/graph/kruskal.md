# クラスカル法
最小全域木を求める．[AOJ](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_12_A)

## 依存
- [UnionFind](./../structure/uf.md)

## 計算量
$O(|E|\log|E|)$(本当？)

## ソースコード
```cpp

struct UnionFind{
    public:
    vector<int> par;//親
    vector<long> weight;//重み
    vector<long> weightAlone;//単体の重み
    UnionFind(int n):par(n),weight(n),weightAlone(n){
        for(int i=0;i<n;i++){
            par[i]=i; //親は自分自身にしておく
            weight[i] = weightAlone[i] = 1;
        }
    }
    //途中で実行すると壊れます
    void setWeight(int i,long w){
        weight[i] = weightAlone[i] = w;
    }
    //途中で実行しても大丈夫
    void changeWeight(int i,long w){
        long pre = weightAlone[i];
        weightAlone[i] = w;
        weight[root(i)] += w-pre;
    }
    int root(int x){
        if(par[x]==x){
            return x;
        }else{
            int r = root(par[x]);
            par[x]=r;
            return r;
        }
    }
    void unite(int x,int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry){
            return;
        }
        par[rx]=ry;
        weight[ry] += weight[rx];
    }
    bool same(int x,int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
    long getWeight(int x){
        return weight[root(x)];
    }
    vector<vector<int>> getGroups(){
        vector<vector<int>> res;
        map<int,vector<int>> mp;
        for(int i=0;i<(int)par.size();i++){
            mp[root(i)].push_back(i);
        }
        for(auto&[k,v]:mp){
            (void)k; //使いません
            res.push_back(v);
        }
        return res;
    }
};

/*クラスカル法*/
struct Edge{
    int from;
    int to;
    long cost;
};

using Graph = vector<vector<Edge>>;

struct Kruskal{
    vector<Edge> edges;
    Graph G;
    int V;
    Kruskal(int V):V(V){
        G.resize(V);
    }
    //無向グラフ！
    void addEdge(int from,int to,long cost){
        edges.push_back({from,to,cost});
    }
    long long build(){
        sort(edges.begin(),edges.end(),[](const Edge& e1,const Edge& e2){
            return e1.cost<e2.cost;
        });
        UnionFind uf(V);
        long long res = 0;
        for(auto& e:edges){
            if(!uf.same(e.from,e.to)){
                uf.unite(e.from,e.to);
                res += e.cost;
                G[e.from].push_back({e.from,e.to,e.cost});
                G[e.to].push_back({e.to,e.from,e.cost});
            }
        }
        return res;
    }
};
```