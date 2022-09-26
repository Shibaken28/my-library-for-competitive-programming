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

//#include<atcoder/modint>
//using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define repl(i,l,r) for (int i = l; i < (int)(r); i++)
#define all(a) a.begin(),a.end()
#define Pii pair<int,int>
#define Pll pair<long,long>
#define INFi 1000000001
#define INFl 1000000000000000001
#define ll long 
using namespace std;


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
            x = i*m + mp[d];
            break;
        }
    }
    return x;
}


int main(void){
    long X,P,A,B;cin>>X>>P>>A>>B;
    if(B-A<=(1e7)){
        long m = P;
        for(long i=A;i<=B;i++){
            long d = modPow(X,i,P);
            if(m>d){
                m = d;
            }
        }
        cout<<m<<endl;
    }else{
        if(B-A>=(P-1)){
            cout<<1<<endl;
            return 0;
        }
        for(long i=1;;i++){
            long d = BSGS(X,i,P);
            d = A/(P-1)*(P-1) + (d%(P-1)==0?0:d);
            if((A<=d&&d<=B)){
                cout<<i<<endl;
                break;
            }
        }
    }
}
