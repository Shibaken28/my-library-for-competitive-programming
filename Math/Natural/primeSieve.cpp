/*
素数篩+素数判定+素因数分解+(前計算あり)高速素因数
verify ?
高速約数列挙ができていない
https://atcoder.jp/contests/math-and-algorithm/submissions/34876840
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
    vector<long> mfactor;
    //既知の素数(随時追加される)
    vector<long> primes;
    set<long> primeSet;
    long N;
    primeSieve(){
        N = 0;
        calc();
    }
    primeSieve(long N){
        this-> N = N;
        calc();
    }
    /*
    素数篩
    O(sqrt(N))
    */
    void calc(){
        primes.clear();
        mfactor.resize(N+1);
        fill(mfactor.begin(),mfactor.end(),-1);
        mfactor[0] = 0;
        mfactor[1] = 1;
        for(long i=2;i<=N;i++){
            if(mfactor[i] == -1){
                for(long j=i;j<=N;j+=i){
                    mfactor[j] = i;
                }
            }
        }
        for(long i=2;i<=N;i++){
            if(mfactor[i] == i){
                primes.push_back(i);
                primeSet.insert(i);
            }
        }
    }
    /*
    素数判定
    O(1)
    */
    bool isPrime(long x){
        if(x==1)return false;
        if(x<=N) return x == mfactor[x];
        if(primeSet.count(x))return true;
        return isPrimeNaive(x);
    }
    /*
    Naive素数判定
    O(sqrt(N))
    */
    bool isPrimeNaive(long x){
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
    /*
    素因数分解
    O(log N)
    */
    vector<long> factorization(long x){
        if(x>N){
            return factorizationNaive(x);
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
        reverse(A.begin(),A.end());
        return A;
    }
    /*
    Naive素因数分解
    O(sqrt N)
    */
    vector<long> factorizationNaive(long x){
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
        if(x>N*N){
            return factorsNaive(x); //未定義
        /*
        }else if(x<=N){
            vector<long> A = {1};
            auto pf = factorization(x);
            for (auto p : pf) {
                int s = (int)A.size();
                for (int i = 0; i < s; ++i) {
                    int v = 1;
                    for (int j = 0; j < p.second; ++j) {
                        v *= p.first;
                        res.push_back(res[i] * v);
                    }
                }
            }
            */
        }else{
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
        }
        sort(A.begin(),A.end());
        return A;
    }
    vector<long> factorsNaive(long x){
        vector<long> A;
        for(long i=1;i*i<=x;i++){
            if(x%i==0){
                if(i*i==x){
                    A.push_back(i);
                }else{
                    A.push_back(i);
                    A.push_back(x/i);
                }
            }
        }
        sort(A.begin(),A.end());
        return A;
    }
};

const long INF = 1e18;

int main(){
    primeSieve sieve(1e7);
    //long N;cin>>N;
    //auto f = sieve.factorization(N);
    cout<<"YES"<<endl;
    for(int i=0;i<1000000;i++){
        //auto f = sieve.factorization(997*997*3);
        auto f = sieve.factorizationNaive(997*997*3);
        //auto f = sieve.factors(997*997);
        //auto f = sieve.factorsNaive(997*997);
        //for(auto&a:f)cout<<a<<endl;
    }
}

