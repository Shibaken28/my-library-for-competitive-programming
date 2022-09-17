/*
座圧imos

verify
https://atcoder.jp/contests/abc188/submissions/34914669
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

template<class T> bool underElement(vector<T> &A,T x,T &find,int &index){
    index = upper_bound(A.begin(),A.end(),x) - A.begin();
    index--;
    if(index >= (int)A.size())return false;
    find = A[index];
    return true;
}

template<class T> struct shrinkImos{
    vector<pair<long,T>> query;
    vector<pair<long,T>> result;
    shrinkImos(){
        init();
    }
    void init(){
        query.clear();
        result.clear();
    }
    /*[l,r]にxを加算*/
    void add(int l,int r,T x){
        query.push_back({l,x});
        query.push_back({r,0});
        query.push_back({r+1,-x});
    }
    void calc(){
        result.clear();
        for(const auto&[p,v]:query){
            result.push_back({p,v});
        }
        sort(result.begin(),result.end());
        for(int i=0;i<(int)result.size()-1;i++){
            result[i+1].second += result[i].second;
        }
    }
    constexpr T get(long i){
        pair<long,T> f;
        int _;
        if(!underElement(result,i,f,_)){
            return 0;
        }
        return f.second;
    }
};


int main(){
    int N;cin>>N;
    long C;cin>>C;
    shrinkImos<long> imos;
    for(int i=0;i<N;i++){
        long a,b,c;cin>>a>>b>>c;
        imos.add(a,b,c);
    }
    long sum = 0;
    imos.calc();
    for(int i=0;i<(int)imos.result.size()-1;i++){
        long d = imos.result[i+1].first - imos.result[i].first;
        if(imos.result[i].second<C)sum += d * imos.result[i].second;
        else sum += d*C;
    }
    cout<<sum<<endl;
}
