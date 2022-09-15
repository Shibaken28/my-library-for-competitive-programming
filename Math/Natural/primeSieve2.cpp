/*
素数篩+素数判定+素因数分解
メモリ削減版
verify失敗
https://onlinejudge.u-aizu.ac.jp/problems/1642
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

struct primeSieve{
    vector<int> mfactor;
    //既知の素数(随時追加される)
    vector<int> primes;
    set<int> primeSet;
    long N;
    primeSieve(){
        N = 0;
        calc();
    }
    primeSieve(long N){
        this-> N = N;
        calc();
    }
    void calc(){
        primes.clear();
        mfactor.resize(N+1);
        fill(mfactor.begin(),mfactor.end(),-1);
        mfactor[0] = 0;
        mfactor[1] = 1;
        for(int i=2;i<=N;i++){
            if(mfactor[i] == -1){
                for(int j=i;j<=N;j+=i){
                    mfactor[j] = i;
                }
            }
        }
        for(int i=2;i<=N;i++){
            if(mfactor[i] == i){
                primes.push_back(i);
                //primeSet.insert(i);
            }
        }
    }
    bool isPrime(long x){
        if(x==1)return false;
        if(x<=N) return x == mfactor[x];
        if(primeSet.count(x))return true;
        return isPrimeSqrt(x);
    }
    bool isPrimeSqrt(long x){
        if(x<=1)return false;
        for(long i=2;i*i<=x;i++){
            if(x%i==0){
                return false;
            }
        }
        primes.push_back(x);
        primeSet.insert(x);
        return true;
    }
    //素因数分解
    vector<long> factorization(long x){
        if(x>N){
            return factorizationSqrt(x);
        }
        vector<long> A(0);
        if(x==1){
            A.push_back(1);
            return A;
        }
        while(x>1){
            A.push_back(mfactor[x]);
            x /= mfactor[x];
        }
        return A;
    }
    vector<long> factorizationSqrt(long x){
        vector<long> A(0);
        for(long i=2;i*i<=x;){
            if(x%i==0){
                x/=i;
                A.push_back(i);
            }else{
                i++;
            }
        }
        if(x>1){
            A.push_back(x);
        }
        return A;
    }
    //約数列挙
    vector<long> factors(long x){
        //if(x>N*N)return {}; //未定義
        vector<long> A(0);
        A.push_back(1);
        for(const auto&p:primes){
            int cnt=0;
            while(x%p==0){
                x/=p;cnt++;
            }
            int s=A.size();
            for(int i=0;i<s;i++){
                long a=1;
                for(int j=0;j<cnt;j++){
                    a*=p;
                    A.push_back(a*A[i]);
                }
            }
            if(x==1)break;
        }
        if(x>1){
            int s=A.size();
            for(int i=0;i<s;i++){
                A.push_back(A[i]*x);
            }
        }
        sort(A.begin(),A.end());
        return A;
    }
};

constexpr long INF = 1001002003004005006;

int main(){
    constexpr long M = 31622777;
    primeSieve sieve{M};
    vector<long> ans;
    while(true){
        long x;cin>>x;
        if(x==0)break;
        long m=INF;
        const auto factor = sieve.factors(x);
        //p<q<rである
        for(int i=0;i<factor.size();i++){
            const long p = factor[i];
            // p*p*p <= x である
            if(p>x/p/p)break;
            for(int j=i;j<factor.size();j++){
                const long q = factor[j];
                // p*q*q <= x である
                if(p>x/q/q)break;
                if((x/p)%q!=0)continue;
                const long r = x/p/q;
                m = min(m,p+q+r);
            }
        }
        ans.push_back(m);
    }
    for(auto&a:ans)cout<<a<<endl;
    return 0;
}

