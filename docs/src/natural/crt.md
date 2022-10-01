# 中国剰余定理
## 概要
$a$で割った余りが$b$，$c$で割った余りが$d$を満たす数を求める．
## ソースコード
```cpp
// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long extGCD(long a, long b, long &x, long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

long mod(long a,long m){
    if(a>=0)return a%m; 
    return (m-(-a)%m)%m;
}

/*
中国剰余定理
*/
bool CRT(long b1, long m1, long b2, long m2,long &r,long &m) {
    long p, q;
    long d = extGCD(m1, m2, p, q);
    if ((b2 - b1) % d != 0) return false;
    m = m1 * (m2/d); 
    long tmp = (b2 - b1) / d * p % (m2/d);
    r = mod(b1 + m1 * tmp, m);
    return true;
}

bool CRT(const vector<pair<long,long>> &X,long &r,long &m) {
    int s = X.size();
    r = X.front().first;
    m = X.front().second;
    bool ok = true;
    for(int i=1;i<s;i++){
        ok = CRT(r,m,X[i].first,X[i].second,r,m);
        if(!ok){
            break;
        }
    }
    return ok;
}
```

