# ナップザック問題
多くの亜種，応用パターンがある．

⚠️ todo 厳密には漸化式が間違っているので直す


## 01ナップザック
- [0-1ナップザック問題](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_B)

- $1\leq N\leq 100$
- $1\leq v_i\leq 1000$
- $1\leq w_i\leq 1000$
- $1\leq W\leq 10000$

$$
\begin{align}
dp[i][j] &:= i番目まで選んで，重さの総和がjとなるように選んだときの価値の総和の最大値\\\\
dp[i][j] &= 
\begin{cases}
    0&(i=0)\\\\
    \max(dp[i-1][j],dp[i-1][j-w_i]+v_i) & (j\geq w_i)\\\\
    dp[i-1][j] & (otherwise)
\end{cases}
\end{align}
$$

復元は，その時の品物を選んだかどうかを記録しておく方法もある．
```cpp
int main(void){
    //01ナップザック
    int N,W;
    cin>>N>>W;
    vector<int> w(N+1),v(N+1);
    for(int i=0;i<N;i++){
        cin>>v[i+1]>>w[i+1];
    }
    vector<vector<long>> dp(N+1,vector<long>(W+1,0));
    // dp[i][j] = i番目まで選んで重さがjになるような最大の価値
    long ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=W;j++){
            if(j-w[i]>=0){
                //選ぶ
                chmax(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }
            //選ばない
            chmax(dp[i][j],dp[i-1][j]);
            chmax(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
    //復元
    vector<int> res;
    int j = W;
    for(int i=N;i>=1;i--){
        if(dp[i][j] == dp[i-1][j-w[i]]+v[i]){
            res.push_back(i);
            j -= w[i];
        }
    }
    cout<<res<<endl;
}
```
## 01ナップザック2(価値が小さい)
- [0-1 ナップザック問題 II](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_F)

- $1\leq N\leq 100$
- $1\leq v_i\leq 100$
- $1\leq w_i\leq 10^7$
- $1\leq W\leq 10^9$
$$
\begin{align}
dp[i][j] &:= i番目まで選んで，価値の総和がjとなるように選んだときの重さの総和の最小値\\\\
dp[i][j] &= 
\begin{cases}
    0&(i=0,j=0)\\\\
    \min(dp[i-1][j],dp[i-1][j-v_i]+w_i) & (j\geq v_i)\\\\
    dp[i-1][j] & (otherwise)
\end{cases}
\end{align}
$$


```cpp
int main(void){
    //01ナップザック
    int N,W;
    cin>>N>>W;
    vector<int> w(N+1),v(N+1);
    for(int i=0;i<N;i++){
        cin>>v[i+1]>>w[i+1];
    }
    vector<vector<long>> dp(N+1,vector<long>(100001,INFl));
    //dp[i][j]:=i番目までの品物から価値の総和がjになるように選んだときの重さの総和の最小値
    dp[0][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=100000;j++){
            if(j-v[i]>=0){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    long ans = 0;
    for(int i=0;i<=100000;i++){
        if(dp[N][i]<=W){
            ans = i;
        }
    }
    cout<<ans<<endl;
    //復元
    vector<int> res;
    int j = ans;
    for(int i=N;i>=1;i--){
        if(dp[i][j]==dp[i-1][j])continue;
        res.push_back(i);
        j-=v[i];
    }
    cout<<res<<endl;
}
```




## 個数制限なしナップザック
- [ナップザック問題](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_C)

- $1\leq N\leq 100$
- $1\leq v_i\leq 1000$
- $1\leq w_i\leq 1000$
- $1\leq W\leq 10000$
$$
\begin{align}
dp[i][j] &:= i番目まで選んで，重さの総和がjとなるように選んだときの価値の総和の最大値\\\\
dp[i][j] &= 
\begin{cases}
    0&(i=0,j=0)\\\\
    \max(dp[i-1][j],dp[i][j-w_i]+v_i) & (otherwise)
\end{cases}
\end{align}
$$


```cpp
int main(void){
    //01ナップザック
    int N,W;
    cin>>N>>W;
    vector<int> w(N+1),v(N+1);
    for(int i=0;i<N;i++){
        cin>>v[i+1]>>w[i+1];
    }
    vector<vector<long>> dp(N+1,vector<long>(W+1,0));
    // dp[i][j] = i番目まで選んで重さがjになるような最大の価値
    long ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=W;j++){
            dp[i][j] = dp[i-1][j];
        }
        for(int j=0;j<=W;j++){
            if(j-w[i]>=0){
                //選ぶ
                chmax(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
            chmax(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}
```

復元するために，そのdpテーブルを更新するときに品物を選んだかを記録しておく(他に方法がある？)．
```cpp
int main(void){
    //01ナップザック
    int N,W;
    cin>>N>>W;
    vector<int> w(N+1),v(N+1);
    for(int i=0;i<N;i++){
        cin>>v[i+1]>>w[i+1];
    }
    vector<vector<long>> dp(N+1,vector<long>(W+1,0));
    // dp[i][j] = i番目まで選んで重さがjになるような最大の価値
    vector<vector<int>> pre(N+1,vector<int>(W+1,0));
    long ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=W;j++){
            dp[i][j] = dp[i-1][j];
        }
        for(int j=0;j<=W;j++){
            if(j-w[i]>=0){
                //選ぶ
                if(chmax(dp[i][j],dp[i][j-w[i]]+v[i])){
                    pre[i][j] = 1;
                }
            }
            chmax(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
    vector<int> res;
    int j = W;
    int i=N;
    while(i>0){
        if(pre[i][j]){
            res.push_back(i);
            j -= w[i];
        }else{
            i--;
        }
    }
    cout<<res<<endl;
}
```
## 個数制限つきナップザック
- [個数制限付きナップザック問題](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_G)
- $1\leq N\leq 100$
- $1\leq v_i\leq 1000$
- $1\leq w_i\leq 1000$
- $1\leq m_i\leq 10000$
- $1\leq W\leq 10000$

- $m_i$個の品物$i$を，$2^0$個，$2$個，$2^2$個，$2^3$，$\cdots$，$2^k$個と余りの塊に分けると，これらの組み合わせで$1$から$m_i$個の組み合わせが実現でき，せいぜい$O(\log m_i)$個で表現できる．
  - $O(\sum\log{m_i})$個の品物がある01ナップザックに帰着する．

```cpp
int main(void){
    long N,W;cin>>N>>W;
    vector<long> w,v;
    w.push_back(0);//インデックス埋め
    v.push_back(0);
    rep(i,N){
        long a,b,c;cin>>a>>b>>c;
        long k=1;
        while(k<=c){
            v.push_back(a*k);
            w.push_back(b*k);
            c-=k;
            k*=2;
        }
        if(c>0){
            v.push_back(a*c);
            w.push_back(b*c);
        }
    }
    N=(int)w.size();
    vector<vector<long>> dp(N+1,vector<long>(W+1,0));
    // dp[i][j] = i番目まで選んで重さがjになるような最大の価値
    long ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=W;j++){
            if(j-w[i]>=0){
                //選ぶ
                chmax(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }
            //選ばない
            chmax(dp[i][j],dp[i-1][j]);
            chmax(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}
```

## 個数制限付きナップザック問題(価値が小さい)
- [個数制限付きナップザック問題 II](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_I)
- $1\leq N\leq 50$
- $1\leq v_i\leq 50$
- $1\leq w_i\leq 10^9$
- $1\leq m_i\leq 10^9$
- $1\leq W\leq 10^9$

## 巨大ナップザック(品物が少ない)
- [巨大ナップザック問題](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_H)
- $1\leq N\leq 40$
- $1\leq v_i\leq 10^{15}$
- $1\leq w_i\leq 10^{15}$
- $1\leq W\leq 10^{15}$
- 半分全列挙
