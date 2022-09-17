/*
座圧2次元imos

verify
https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_4_A
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

template<class T1,class T2> struct shrinkImos2d{
    vector<T1> Ay,Ax;
    vector<tuple<T1,T1,T2>> query;
    vector<vector<T2>> result;
    shrinkImos2d(){
        init();
    }
    void init(){
        Ax.push_back(2001002003);
        Ay.push_back(2001002003);
        /*
        Ax.push_back(1001002003004005006);
        Ay.push_back(1001002003004005006);
        */
        result.clear();
    }
    /*[l,r]にxを加算*/
    void add(T1 ly,T1 lx,T1 ry,T1 rx,T2 x){
        Ay.push_back(ly);
        Ay.push_back(ry);
        Ay.push_back(ry+1);
        Ax.push_back(lx);
        Ax.push_back(rx);
        Ax.push_back(rx+1);
        query.push_back({ly,lx,x});
        query.push_back({ry+1,lx,-x});
        query.push_back({ly,rx+1,-x});
        query.push_back({ry+1,rx+1,x});
    }
    void calc(){
        result.clear();
        sort(Ax.begin(),Ax.end());
        sort(Ay.begin(),Ay.end());
        Ax.erase(unique(Ax.begin(), Ax.end()), Ax.end());
        Ay.erase(unique(Ay.begin(), Ay.end()), Ay.end());
        
        result.resize(Ay.size());
        for(int i=0;i<(int)Ay.size();i++){
            result[i].resize(Ax.size());
            fill(result[i].begin(),result[i].end(),0);
        }
        for(const auto&[y,x,a]:query){
            int yi = lower_bound(Ay.begin(),Ay.end(),y)-Ay.begin();
            int xi = lower_bound(Ax.begin(),Ax.end(),x)-Ax.begin();
            result[yi][xi] += a;
        }
        for(int y=0;y<(int)result.size();y++){
            for(int x=0;x<(int)result[y].size()-1;x++){
                result[y][x+1] += result[y][x];
            }
        }
        for(int y=0;y<(int)result.size()-1;y++){
            for(int x=0;x<(int)result[y].size();x++){
                result[y+1][x] += result[y][x];
            }
        }
    }
    constexpr T2 get(T1 y,T1 x){
        T1 yf,xf;
        int yi,xi;
        bool a = underElement(Ay,y,yf,yi);
        bool b = underElement(Ax,x,xf,xi);
        if(a||b)return 0;
        return result[yi][xi];
    }
    constexpr long area(T1 iy,T1 ix){
        return (long)(Ax[ix+1]-Ax[ix])*(long)(Ay[iy+1]-Ay[iy]);
    }
    void print(){
        for(int i=0;i<(int)Ax.size();i++){
            cout<<Ax[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<(int)Ay.size();i++){
            cout<<Ay[i]<<" ";
        }
        cout<<endl;
        for(int y=0;y<(int)result.size();y++){
            for(int x=0;x<(int)result[y].size();x++){
                cout << result[y][x] <<" ";
            }
            cout<<endl;
        }
    }
};


int main(){
    int N;cin>>N;
    shrinkImos2d<int,int> imos;
    for(int i=0;i<N;i++){
        long a,b,c,d;cin>>a>>b>>c>>d;
        imos.add(b,a,d-1,c-1,1);
    }
    imos.calc();
    long sum=0;
    for(int y=0;y<(int)imos.result.size()-1;y++){
        for(int x=0;x<(int)imos.result[y].size()-1;x++){
            if(imos.result[y][x]>0) sum += imos.area(y,x);
        }
    }
    cout<<sum<<endl;
}
