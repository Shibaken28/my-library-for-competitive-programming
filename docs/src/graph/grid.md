# 二次元マップをグラフに起こすやつ

## 概要
2次元`#.`マップをグラフに起こします．

## 注意
`calc()`関数内を適切に書き換えて使用してください．


```cpp
struct GridGraph{
    int H,W;
    Graph G;
    vector<vector<int>> A;
    vector<long> D;
    GridGraph(int h,int w){
        H = h;
        W = w;
        init();
    }
    void init(){
        D.clear();
        G.clear();
        A.clear();
        G.resize(H*W);
        A.resize(H);
        for(int i=0;i<H;i++){
            A[i].resize(W);
        }
    }
    void in(){
        map<char,int> mp = {{'.',0},{'#',1}};
        for(int i=0;i<H;i++){
            string S;cin>>S;
            for(int j=0;j<W;j++){
                A[i][j] = mp[(S[j])];
            }
        }
    }
    void build(){
        static vector<int> dx = {1,0};
        static vector<int> dy = {0,1};
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                for(int a=0;a<(int)dx.size();a++){
                    int h = i + dy[a];
                    int w = j + dx[a];
                    if(h<0||w<0||h>=H||w>=W)continue;
                    if(A[h][w]==A[i][j]&&A[h][w]==0){
                        int x = toInt(i,j);
                        int y = toInt(h,w);
                        G[x].push_back({y,1});
                        G[y].push_back({x,1});
                    }
                }
            }
        }
    }
    void calc(int h,int w){
        //dijkstra(toInt(h,w),G,D);
    }
    int toInt(int h,int w){
        return W*h + w;
    }
    long getDis(int h,int w){
        return D[toInt(h,w)];
    }
};

```
