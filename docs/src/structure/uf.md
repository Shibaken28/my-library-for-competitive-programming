# UnionFind
## 概要
UnionFindは、グラフの連結成分を管理するデータ構造．
次の操作がそれぞれ高速(ほぼ定数時間)に行える．
- `root(x)` : `x`の根を返す．
- `unite(u,v)` : `u`,`v`をマージする
- `same(u,v)` : `u`,`v`が同じ連結成分に属するかを判定する．
- `getGroup(x)` : 現在の連結成分のリストを返す．
- `getWeight(x)` : `x`が属する連結成分の重みを返す．
- `changeWeight(x)` : 頂点`x`の重みを変更する．

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

```


重みは途中で変更できる．
```cpp
int main(void){
    UnionFind uf(3);
    //初期の全ての頂点の重みは1
    uf.unite(1,2);
    cout<<uf.getWeight(1)<<endl; // 2(=1+1)
    uf.changeWeight(1,10);
    cout<<uf.getWeight(1)<<endl; // 11(=10+1)
    uf.unite(0,1);
    cout<<uf.getWeight(1)<<endl; // 12(=10+1+1)
}
```
