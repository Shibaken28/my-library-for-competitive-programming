# baby step giant step

## 概要
素数\\(p\\)と\\(0\leq a,b< p \\)について，\\(a^x = b \mod p\\)となる\\(x\\)を求める．

## 計算量
\\(O(\sqrt{p} )\log \sqrt{p}\\)

```cpp
long  extgcd(long a,long b,long & x,long & y){
    long d = a;
    if(b != 0) {
        d = extgcd(b,a%b,y,x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

long mod_inverse(long a,long m){
    long x,y;
    extgcd(a,m,x,y);
    return (m + x % m) % m;
}

int modPow(long a, long n, long p) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

long iroot(long y,int n){
    //x^n <= yとなる最大のn
    long ok = 0;
    long ng = y+1;
    while(abs(ok-ng)>1){
        long mid = (ok+ng)/2;
        long x = 1;
        bool inf = false;
        for(int i=0;i<n;i++){
            if(((long)1e18)/x < mid)inf = true;
            x *= mid;
        }
        if(inf||x>y){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return ok;
}

long BSGS(long a,long b,long p){
    /* a^x = b mod p となるようなxを求める */
    long x = -1;
    long m = iroot(p,2)+1;
    map<long,long> mp;
    long ax = 1;
    for(long i=0;i<=m;i++){
        mp[ax] = i;
        ax = (ax*a) % p;
    }
    /*
    a^(im+j) = b
    a^j = b(a^-m)^i
    */
    long am = modPow(mod_inverse(a,p),m,p);
    for(long i=0;i<=m;i++){
        long d = (modPow(am,i,p)*b) % p;
        if(mp.count(d)){
            if(i==0&&mp[d]==0)continue;
            x = i*m + mp[d];
            break;
        }
    }
    return x;
}
```

