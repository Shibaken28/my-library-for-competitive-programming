/*
matrix
verify
https://atcoder.jp/contests/math-and-algorithm/submissions/35059887
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



namespace MatrixLib {
    class print_format_error: public std::exception {
        virtual const char* what() const noexcept { return "Error: print() method cannot print these values because of unsupported!"; }
    };
    class matrix_product_error: public std::exception {
        virtual const char* what() const noexcept { return "Error: Impossible to calculate matrix product!"; }
    };
    class determinant_error: public std::exception {
        virtual const char* what() const noexcept { return "Error: Impossible to calculate determinant!"; }
    };
    class inversion_error: public std::exception {
        virtual const char* what() const noexcept { return "Error: Impossible to calculate inversion!"; }
    };


    /*** 二次元行列のライブラリMatrix ***/
    template <typename T>
    class Matrix {
        private:
            vector<vector<T>> A;

            T __cofactor(const vector<vector<T>>& coA) const {
                /* 各余因子の計算を再帰的にする */
                if (coA.size() == 1) return coA[0][0];
                if (coA.size() == 2) {
                    return coA[0][0]*coA[1][1]-coA[0][1]*coA[1][0];
                }

                T res = 0;
                for (int col2=0; col2<coA.size(); col2++) {
                    vector<vector<T>> cocoA(coA.size()-1);
                    for (int row=1; row<coA.size(); row++) {
                        for (int col=0; col<coA.size(); col++) {
                            if (col2==col) continue;
                            cocoA[row-1].emplace_back(coA[row][col]);
                        }
                    }
                    if (!(col2&1)) res += coA[0][col2] * __cofactor(cocoA);
                    else res -= coA[0][col2] * __cofactor(cocoA);
                }
                return res;
            }
        public:
            size_t row;
            size_t col;
            Matrix(size_t row=1, size_t col=1) {
                this->row = row;
                this->col = col;
                this->A.resize(row);
                for(size_t i=0; i<row; i++) this->A[i].resize(col);
            }

            vector<T>& operator[](const size_t i) {
                return this->A[i];
            }

            Matrix& operator+=(Matrix other) {
                for(size_t i=0; i<this->row; i++) {
                    for(size_t j=0; j<this->col; j++) {
                        this->A[i][j] += other[i][j];
                    }
                }
                return *this;
            }
            Matrix operator+(const Matrix other) const {
                return Matrix(*this) += other;
            }
            Matrix& operator+=(const double a) {
                /* 各要素にaを足す */
                for (size_t i=0; i<this->row; i++) {
                    for (size_t j=0; j<this->col; j++) {
                        this->A[i][j] += a;
                    }
                }
                return *this;
            }
            Matrix operator+(const double a) const {
                return Matrix(*this) += a;
            }

            Matrix& operator-=(Matrix other) {
                for(size_t i=0; i<this->row; i++) {
                    for(size_t j=0; j<this->col; j++) {
                        this->A[i][j] -= other[i][j];
                    }
                }
                return *this;
            }
            Matrix operator-(const Matrix other) const {
                return Matrix(*this) -= other;
            }
            Matrix operator-() const {
                Matrix res(this->row, this->col);
                for (size_t i=0; i<this->row; i++) {
                    for (size_t j=0; j<this->col; j++) {
                        res[i][j] = -this->A[i][j];
                    }
                }
                return res;
            }
            Matrix& operator-=(const double a) {
                /* 各要素にaを引く */
                for (size_t i=0; i<this->row; i++) {
                    for (size_t j=0; j<this->col; j++) {
                        this->A[i][j] -= a;
                    }
                }
                return *this;
            }
            Matrix operator-(const double a) const {
                return Matrix(*this) -= a;
            }

            Matrix& operator*=(Matrix other) {
                /* NxN行列 x NxN行列 の積を求める */
                if (!(this->row==this->col && other.row==other.col && this->row==other.row)) throw matrix_product_error();

                vector<vector<T>> res(this->row, vector<T>(this->col, 0));
                for(size_t i=0; i<other.row; i++) {
                    for (size_t j=0; j<this->col; j++) {
                        for (size_t k=0; k<this->col; k++) {
                            res[i][j] += this->A[i][k]*other[k][j];
                        }
                    }
                }
                this->A = res;
                return *this;
            }
            Matrix operator*(Matrix other) const {
                /* ixk行列 * kxj行列 の積を求める */
                if (this->col!=other.row) throw matrix_product_error();

                Matrix<T> res(this->row, other.col);
                for (size_t i=0; i<this->row; i++) {
                    for (size_t j=0; j<other.col; j++) {
                        for (size_t k=0; k<this->col; k++) {
                            res[i][j] += this->A[i][k]*other[k][j];
                        }
                    }
                }
                return res;
            }

            Matrix& operator*=(const double a) {
                /* 各要素にaをかける */
                for (size_t i=0; i<this->row; i++) {
                    for (size_t j=0; j<this->col; j++) {
                        this->A[i][j] *= a;
                    }
                }
                return *this;
            }
            Matrix operator*(const double a) const {
                return Matrix(*this) *= a;
            }

            void print() {
                /* 行列の状態を表示する */
                string format;
                if (typeid(T)==typeid(int)) format = "%*d"s;
                else if (typeid(T)==typeid(unsigned int) || typeid(T)==typeid(unsigned short)) format = "%*u"s;
                else if (typeid(T)==typeid(long)) format = "%*ld"s;
                else if (typeid(T)==typeid(unsigned long)) format = "%*lu"s;
                else if (typeid(T)==typeid(long long)) format = "%*lld"s;
                else if (typeid(T)==typeid(unsigned long long)) format = "%*llu"s;
                else if (typeid(T)==typeid(short)) format = "%*f"s;
                else if (typeid(T)==typeid(double)) format = "%*lf"s;
                else if (typeid(T)==typeid(long double)) format = "%*LF"s;
                else throw print_format_error();

                int len = 0;
                for (size_t i=0; i<this->row; i++) {
                    for (size_t j=0; j<this->col; j++) {
                        string str = to_string(this->A[i][j]);
                        len = max(len, (int)str.size());
                    }
                }

                printf("[[");
                for (size_t i=0; i<this->row; i++) {
                    for (size_t j=0; j<this->col; j++) {
                        printf(format.c_str(), len, this->A[i][j]);
                        if (j!=this->col-1) printf(", ");
                        else printf("]");
                    }
                    if (i!=this->row-1) printf(",\n  ");
                    else printf("]\n");
                }
            }

            T det() const {
                /* 行列式を計算して返す */
                if (this->row!=this->col) throw determinant_error();

                return this->__cofactor(this->A);
            }

            Matrix dot(const Matrix B) const {
                /* ドット積（内積）計算をする */
                return Matrix(*this) * B;
            }

            Matrix inv() const {
                /* 逆行列を返す（掃き出し法） */
                if (!(this->row==this->col)) throw inversion_error();

                size_t N = this->row;
                Matrix<T> A = *this;
                Matrix<T> invA(N, N);
                for (size_t i=0; i<N; i++) {
                    for (size_t j=0; j<N; j++) {
                        invA[i][j] = (i==j) ? 1 : 0;
                    }
                }

                for (size_t i=0; i<N; i++) {
                    T buf = 1/A[i][i];
                    for (size_t j=0; j<N; j++) {
                        A[i][j] *= buf;
                        invA[i][j] *= buf;
                    }

                    for (size_t j=0; j<N; j++) {
                        if (i!=j) {
                            buf = A[j][i];
                            for (size_t k=0; k<N; k++) {
                                A[j][k] -= A[i][k]*buf;
                                invA[j][k] -= invA[i][k]*buf;
                            }
                        }
                    }
                }

                return invA;
            }

            Matrix pow(long N){
                Matrix mat = (*this);
                Matrix res(mat.row,mat.col);
                for (size_t i=0; i<mat.row; i++) {
                    for (size_t j=0; j<mat.row; j++) {
                        res[i][j] = (i==j) ? 1 : 0;
                    }
                }
                while(N){
                    if(N%2==1){
                        res *= mat;
                    }
                    mat *= mat;
                    N/=2;
                }
                return res;
            }
    };

    
}

using namespace MatrixLib;

const int MOD = 1000000000;
using mint = Fp<MOD>;



int main(void){
    long N;cin>>N;
    Matrix<mint> mat(2,2);
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;
    Matrix<mint> r(2,1);
    r[0][0] = 1;
    r[1][0] = 1;
    auto m2 = mat.pow(N-2) * r;
    cout<<m2[0][0]<<endl;
}