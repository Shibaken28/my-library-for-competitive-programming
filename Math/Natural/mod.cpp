/*
modint構造体
combination

verify

modpow
https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B

combination mod
https://atcoder.jp/contests/math-and-algorithm/submissions/34884143

パスカル
https://atcoder.jp/contests/math-and-algorithm/submissions/34885355

lucas
https://atcoder.jp/contests/arc117/submissions/34885971

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


// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

const int MOD = 1000000007;
using mint = Fp<MOD>;

/*
有限体Tにおけるcombination
mod <= N のとき未定義
*/
template<class T> struct Combination{
    int N;
    vector<T> fac;//階乗
    vector<T> finv;//階乗の逆元
    Combination(int N){
        this->N = N;
        init();
    }
    void init(){
        fac.resize(N);
        finv.resize(N);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        for(int i=2;i<N;i++){
            fac[i] = fac[i-1] * i;
            finv[i] = finv[i-1] / i;
        }
    }
    /*aCbの計算*/
    T com(int a,int b){
        if(a < b)return 0;
        return fac[a] * finv[b] * finv[a-b];
    }
};

struct Pascal{
    //tri[a][b] = aCb
    vector<vector<long>> tri;
    int N;
    Pascal(int N){
        this->N = N;
        init();
    }
    void init(){
        tri.clear();
        tri.push_back({1});
        for(int i=1;i<N;i++){
            vector<long> add(0);
            add.push_back(1);
            for(int k=0;k<i-1;k++){
                add.push_back(tri.back()[k]+tri.back()[k+1]);
            }
            add.push_back(1);
            tri.push_back(add);
        }
    }
    long com(int a,int b){
        if(a<b)return 0;
        return tri[a][b];
    }
};

/*
MODは素数
*/
template<int MOD> struct Lucas{
    Pascal pas{MOD};
    Lucas(){
    }
    Fp<MOD> com(long a,long b){
        if(a<b)return 0;
        Fp<MOD> ret{1};
        while(a>0){
            ret *=pas.com(a%MOD,b%MOD);
            a/=MOD;
            b/=MOD;
        }
        return ret;
    }
};

int main(){
    Lucas<3> lucas;
    long N;cin>>N;
    Fp<3> w=0;
    map<char,long> mp = {{'R',0},{'W',1},{'B',2}};
    for(int i=0;i<N;i++){
        char c;cin>>c;
        auto a=lucas.com(N-1,i);
        w+=a*mp[c];
    }
    if(N%2==0)w=-w;
    if(w==0)cout<<"R"<<endl;    
    if(w==1)cout<<"W"<<endl;
    if(w==2)cout<<"B"<<endl;
}
