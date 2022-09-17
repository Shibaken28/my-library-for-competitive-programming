/*
配列要素二分探索詰め合わせ

verify

isExist
https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_B

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

/*
Aにxが存在するか
O(log N)
*/
template<class T> bool isExist(vector<T> &A,T x){
    return binary_search(A.begin(),A.end(),x);
}
template<class T> bool isExist(set<T> &A,T x){
    auto it = A.lower_bound(x);
    if(it==A.end()){
        return false;
    }
    return *it == x;
}

/*
Aに存在するx以上の数
最も小さいindexとその値find
O(log N)
*/
template<class T> bool lowerElement(vector<T> &A,T x,T &find,int &index){
    index = lower_bound(A.begin(),A.end(),x) - A.begin();
    if(index == (int)A.size())return false;
    find = A[index];
    return true;
}
template<class T> bool lowerElement(set<T> &A,T x,T &find){
    auto it = A.lower_bound(x);
    if(it==A.end())return false;
    find = *it;
    return true;
}



/*
Aに存在するxより大きい数
最も小さいindexとその値find
O(log N)
*/
template<class T> bool upperElement(vector<T> &A,T x,T &find,int &index){
    index = upper_bound(A.begin(),A.end(),x) - A.begin();
    if(index == (int)A.size())return false;
    find = A[index];
    return true;
}
template<class T> bool upperElement(set<T> &A,T x,T &find){
    auto it = A.upper_bound(x);
    if(it == A.end())return false;
    find = *it;
    return true;
}



/*
Aに存在するx以下
最も大きいindexとその値find
O(log N)
*/
template<class T> bool underElement(vector<T> &A,T x,T &find,int &index){
    index = upper_bound(A.begin(),A.end(),x) - A.begin();
    index--;
    if(index >= (int)A.size())return false;
    find = A[index];
    return true;
}
template<class T> bool underElement(set<T> &A,T x,T &find){
    auto it = A.upper_bound(x);
    if(it == A.begin())return false;
    it--;
    find = *it;
    return true;
}

/*
Aに存在するxより小さい数
最も大きいindexとその値find
O(log N)
*/
template<class T> bool lessElement(vector<T> &A,T x,T &find,int &index){
    index = lower_bound(A.begin(),A.end(),x) - A.begin();
    index--;
    if(index < 0)return false;
    find = A[index];
    return true;
}
template<class T> bool lessElement(set<T> &A,T x,T &find){
    auto it = A.lower_bound(x);
    if(it == A.begin())return false;
    it--;
    find = *it;
    return true;
}

/*
Aに含まれるxの個数をO(log N)で求める
*/
template<class T> int countElement(vector<T> &A,T x){
    T f1,f2;
    int i1,i2;
    lowerElement(A,x,f1,i1);
    underElement(A,x,f2,i2);
    return isExist(A,x)?i2-i1+1:0;
}

/*
Aに含まれるl以上r以下の個数をO(log N)で求める
*/
template<class T> int countElementInRange(vector<T> &A,T l,T r){
    T f1,f2;
    int i1,i2;
    lowerElement(A,l,f1,i1);
    underElement(A,r,f2,i2);
    int c = i2-i1+1;
    return c>0?c:0;
}


int main(){
    int n;cin>>n;
    vector<int>S(n);
    for(int i=0;i<n;i++)cin>>S[i];
    int q;cin>>q;
    int cnt = 0;
    for(int i=0;i<q;i++){
        int t;cin>>t;
        if(isExist(S,t))cnt++;
    }
    cout<<cnt<<endl;
}
