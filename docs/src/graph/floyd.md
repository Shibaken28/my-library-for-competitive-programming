# ワーシャルフロイド法
## 概要
全ての頂点の組の最短距離が求められる．

## 計算量
頂点数を$V$とすると$O(V^3)$．

## 注意
行列でグラフを表現するが，同じ頂点同士の距離は0，辺が存在しない場合は距離を$\infty$とする．
## ソースコード
```cpp
/*
Gは隣接行列である必要があり，辺がない場合はINF，自己ループ辺は0
*/
const long INF = 1e17;

vector<vector<long>> floydWarshall(vector<vector<long>> &G){
    const int N = G.size();
    auto H = G;
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            for(int c=0;c<N;c++){
                long d = H[b][a] + H[a][c];
                if(H[b][a]==INF||H[a][c]==INF)d = INF;
                if(H[b][c] > d){
                    H[b][c] = d;
                }
            }
        }
    }
    return H;
}

```

