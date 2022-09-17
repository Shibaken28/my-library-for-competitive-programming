/*
imos
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


template<class T> struct imos{
    
}

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
