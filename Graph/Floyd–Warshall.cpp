/*
ワーシャルフロイド法
verify
https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C
*/

#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>
#include <climits>
#include <cmath>
#include <functional>
#include <numeric>
#include <regex>
#include <array>
#include <fstream>
#include <sstream>
using namespace std;

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

int main(){
    int N,M;cin>>N>>M;
    vector<vector<long>> G(N,vector<long>(N,INF));
    for(int i=0;i<N;i++)G[i][i] = 0;
    for(int i=0;i<M;i++){
        long a,b,c;
        cin>>a>>b>>c;
        G[a][b] = c;
        //G[b][a] = c;
    }
    auto F = floydWarshall(G);
    bool nega=false;
    for(int i=0;i<N;i++){
        if(F[i][i]<0)nega=true;
    }
    if(nega){
        cout<<"NEGATIVE CYCLE"<<endl;
        return 0;
    }
    for(auto&A:F){
        for(int i=0;i<N;i++){
            if(A[i]<INF){
                cout<<A[i];
            }else{
                cout<<"INF";
            }
            if(i<N-1)cout<<" ";
        }
        cout<<endl;
    }
}
