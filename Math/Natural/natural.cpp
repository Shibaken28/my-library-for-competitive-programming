/*
整数(GCD,CRT)詰め合わせ
verify
CRT
https://yukicoder.me/submissions/797615

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

long GCD(long a,long b){
    if(a<b)return GCD(b,a);
    if(b==0)return a;
    return GCD(b,a%b);
}

long GCD(vector<long>&A){
    long gcd = A.front();
    for(auto&a:A)gcd = GCD(gcd,a);
    return gcd;
}

long LCM(long a,long b){
    return (a/GCD(a,b))*b;
}


long LCM(vector<long>&A){
    long lcm = 1;
    for(auto&a:A)lcm = LCM(lcm,a);
    return lcm;
}

/*
ax + by = c の一般解
x = alpha t + beta
y = gamma t + delta
*/
bool Bezout(long a,long b,long c,long &alpha,long &beta,long &gamma,long &delta){
    long x=0,y=0;
    long gcd=extGCD(a,b,x,y);
    if(c%gcd!=0){
        return false;
    }
    x *= c/gcd;
    y *= c/gcd;
    gamma = a/gcd;
    delta = y;
    alpha = -b/gcd;
    beta = x;
    return true;
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

int main(){
    vector<long> A={20,10,12};
    cout<<GCD(A)<<" "<<LCM(A)<<endl;
}
