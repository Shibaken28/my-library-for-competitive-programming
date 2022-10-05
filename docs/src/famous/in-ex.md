# 包除原理
## 簡単な例
$f(X)$を集合$X$の大きさとすると，
$$
f(A\cup B)= f(A) + f(B) -f(A\cap B)
$$
が成り立つ．これを一般化したものが包除原理．

## 例題
[問題リンク](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_be)

- 正の整数$N$と$A_1,A_2,A_3,\cdots,A_K$が与えられる
- $1\leq K \leq 10$
- $1\leq N \leq 10^{12}$
- $1$以上$N$以下の整数で$A_1,A_2,A_3,\cdots,A_K$のいずれかの倍数であるものの個数を求める．

言い換えると，$A_1$の倍数，$A_2$の倍数，$A_3$の倍数，$\cdots$，$A_K$の倍数，の$K$個の集合の和集合の大きさを求める．この$K$個の集合から$1$つ以上を選ぶ全ての組み合わせについて，
- 奇数個の集合であれば，積集合の大きさを足す
- 偶数個の集合であれば，積集合の大きさを引く

を行っていくと，最終的には辻褄が合って，条件を1つ以上満たすものの個数が求まる．

```cpp
long GCD(long a,long b){
    if(a<b)return GCD(b,a);
    if(b==0)return a;
    return GCD(b,a%b);
}
long LCM(long a,long b){
    return (a/GCD(a,b))*b;
}
int main(void){
    long N,K;cin>>N>>K;
    vector<long> V(K);
    rep(i,K)cin>>V[i];
    long ans = 0;
    for(int i=1;i<(1<<K);i++){
        int c=0;
        long lcm=1;
        for(int k=0;k<K;k++){
            if(i&(1<<k)){
                c++;
                lcm = LCM(V[k],lcm);
            }
        }
        ans += (N/lcm) * (c%2==1?1L:-1L);
    }
    cout<<ans<<endl;
}

```
