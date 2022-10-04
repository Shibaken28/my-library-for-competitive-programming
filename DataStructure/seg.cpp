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
#define ll long long
using namespace std;



template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> void printArray(vector<T>&A){
    for(T&a:A){
        cout<<a<<" ";
    }
    cout<<endl;
}
template<class T> void printArrayln(vector<T>&A){
    for(T&a:A){
        cout<<a<<endl;
    }
}


template<class T1,class T2> std::ostream &operator<<(std::ostream &out, const pair<T1,T2> &A){
    cout<<"{"<<A.first<<","<<A.second<<"}";
    return out;
}

template<class T1,class T2> std::ostream &operator<<(std::ostream &out, const map<T1,T2> &M){
    for(const auto&A:M){
        cout<<"{"<<A.first<<","<<A.second<<"}";
    }
    return out;
}

template<class T1> std::ostream &operator<<(std::ostream &out, const set<T1> &M){
    cout<<"{";
    for(const auto&A:M){
        cout<<A<<", ";
    }
    cout<<"}"<<endl;
    return out;
}


template<class T1> std::ostream &operator<<(std::ostream &out, const multiset<T1> &M){
    cout<<"{";
    for(const auto&A:M){
        cout<<A<<", ";
    }
    cout<<"}"<<endl;
    return out;
}

template<class T> std::ostream &operator<<(std::ostream &out, const vector<T> &A){
    for(const T &a:A){
        cout<<a<<" ";
    }
    return out;
}

void print() { cout << endl; }
 
template <typename Head, typename... Tail>
void print(Head H, Tail... T) {
  cout << H << " ";
  print(T...);
}


template<class T> std::istream &operator>>(std::istream &in,vector<T>&A){
    for(T&a:A){
        std::cin>>a;
    }
    return in;
}


// matrix
template<class T> struct Matrix {
    vector<vector<T> > val;
    Matrix(int n = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v)) {}
    void init(int n, int m, T v = 0) {val.assign(n, vector<T>(m, v));}
    void resize(int n, int m) {
        val.resize(n);
        for (int i = 0; i < n; ++i) val[i].resize(m);
    }
    Matrix<T>& operator = (const Matrix<T> &A) {
        val = A.val;
        return *this;
    }
    size_t size() const {return val.size();}
    vector<T>& operator [] (int i) {return val[i];}
    const vector<T>& operator [] (int i) const {return val[i];}
    friend ostream& operator << (ostream& s, const Matrix<T>& M) {
        s << endl;
        for (int i = 0; i < (int)M.size(); ++i) s << M[i] << endl;
        return s;
    }
};

template<class T> Matrix<T> operator * (const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> R(A.size(), B[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < B[0].size(); ++j)
            for (int k = 0; k < B.size(); ++k)
                R[i][j] += A[i][k] * B[k][j];
    return R;
}

template<class T> Matrix<T> pow(const Matrix<T> &A, long long n) {
    Matrix<T> R(A.size(), A.size());
    auto B = A;
    for (int i = 0; i < (int)A.size(); ++i) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * B;
        B = B * B;
        n >>= 1;
    }
    return R;
}

template<class T> vector<T> operator * (const Matrix<T> &A, const vector<T> &B) {
    vector<T> v(A.size());
    for (int i = 0; i < (int)A.size(); ++i)
        for (int k = 0; k < (int)B.size(); ++k)
            v[i] += A[i][k] * B[k];
    return v;
}



template<typename T>
struct SegTree{
    using FX = function<T(T,T)>; // TとTの演算結果Tを返す
    FX fx;
    int n;
    vector<T>dat;
    const T ex;//単位元(こいつとxを演算をしてもxになる)
    SegTree(int n_,T ex_,FX fx_):ex(ex_),fx(fx_){
        n=1;
        while(n<n_)n*=2;
        //完全二分木にする
        dat.assign(2*n-1,ex);
    }
    void update(int k,T a){
        k+=n-1;// i番目は、配列上では n-1+i 番目に格納されている
        dat[k] = a;// 葉の更新
        while(k>0){
            k=(k-1)/2; //親のインデックス
            // 子の和を計算
            dat[k]=fx(dat[k*2+1],dat[k*2+2]);
        }
    }
    void set(int k,T a){
        k+=n-1;
        dat[k]=a;
    }
    void build(){
        for(int k=n-2;k>=0;k--){
            dat[k]=fx(dat[k*2+1],dat[k*2+2]);
        }
    }
    T query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return ex;//範囲外なので単位元を返す
        if(a<=l&&r<=b)return dat[k]; //範囲内である
        else{
            T vl=query(a,b,k*2+1,l,(l+r)/2);
            T vr=query(a,b,k*2+2,(l+r)/2,r);
            return fx(vl,vr);
        }
    }
    //[a,b)のfx(A_a,A_a+1,...,A_b-1)を返す
    T query(int a,int b){
        return query(a,b,0,0,n);
    }
};


int main(void){
    long N,M;cin>>N>>M;
    vector<long> P(M);
    vector<double> A(M),B(M);
    map<long,int> mp;
    for(int i=0;i<M;i++){
        cin>>P[i];
        mp[P[i]]=-1;
        cin>>A[i]>>B[i];
    }
    int c=0;
    for(auto&[a,b]:mp){
        b=c;
        c++;
    }
    for(int i=0;i<M;i++){
        P[i]=mp[P[i]];
    }
    double mi = 1;//最小
    double ma = 1;//最大
    using Mat = Matrix<double>;
    Mat I(2,2,0);
    I[0][0]=I[1][1]=1;//単位元の単位行列
    N = (int)mp.size();
    SegTree<Mat>st (N,I,[](Mat a,Mat b){return a*b;});
    for(int i=0;i<M;i++){
        Mat m(2,2,0);
        m[0][0]=A[i];
        m[0][1]=0;
        m[1][0]=B[i];
        m[1][1]=1;
        st.update(P[i],m);
        auto c=st.query(0,N);
        Mat x(1,2,1.0);
        auto a = x*c; 
        chmax(ma,a[0][0]);
        chmin(mi,a[0][0]);
    }
    cout<<fixed<<setprecision(10);
    cout<<mi<<endl;
    cout<<ma<<endl;
}

