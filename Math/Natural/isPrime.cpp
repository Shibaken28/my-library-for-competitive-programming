/*
素数判定
verify
https://atcoder.jp/contests/math-and-algorithm/submissions/34873661
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

bool isPrime(long N){
    if(N<=1)return false;
    for(long i=2;i*i<=N;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}


int main(){
    long N;cin>>N;
    cout<<(isPrime(N)?"Yes":"No")<<endl;    
}

