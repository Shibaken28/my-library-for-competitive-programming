/*
線分の当たり判定(共通の点があるか)
verify
https://atcoder.jp/contests/math-and-algorithm/submissions/34894773
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



template<class T> struct Vector3D{
    T x{0};
    T y{0};
    T z{0};
    constexpr Vector3D(T x,T y,T z){
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    constexpr Vector3D(T x1,T y1,T z1,T x2,T y2,T z2){
        this -> x = x2 - x1;
        this -> y = y2 - y1;
        this -> z = z2 - z1;
    }
    constexpr Vector3D cross(const Vector3D &a)const{
        return Vector3D(this->y * a.z - this->z * a.y, this->z * a.x - this->x * a.z, this->x * a.y - this->y * a.x);
    }
    constexpr Vector3D operator-(const Vector3D &r)const{
        return Vector3D(*this)-=r;
    }
    constexpr Vector3D operator-=(const Vector3D &r){
        this->x -= r.x;
        this->y -= r.y;
        this->z -= r.z;
        return *this;
    }
    constexpr Vector3D operator+(const Vector3D &r){
        return Vector3D(*this)+=r;
    }
    constexpr Vector3D operator+=(const Vector3D &r){
        this->x += r.x;
        this->y += r.y;
        this->z += r.z;
        return *this;
    }
    constexpr bool operator==(const Vector3D &r) const{
        return this->x == r.x && this->y == r.y && this->z == r.z;
    }
    friend constexpr std::ostream &operator<<(std::ostream &out,const Vector3D &a){
        out<<"{"<<a.x<<", "<<a.y<<", "<<a.z<<"}";
        return out;
    }
};

inline bool rangeInRange(long l0,long r0,long l1,long r1){
    if(l0>r0)swap(l0,r0);
    if(l1>r1)swap(l1,r1);
    if(l1<l0&&r1<l0)return false;
    if(r0<l1&&r0<r1)return false;
    return true;
}

inline long getSign(long a){
    if(a>0)return 1;
    else if(a<0)return -1;
    return 0;
}

bool isIntersects(long x1,long y1,long x2,long y2,long x3,long y3,long x4,long y4){
    using Vec3 = Vector3D<long>;
    Vec3 A{x1,y1,0};
    Vec3 B{x2,y2,0};
    Vec3 C{x3,y3,0};
    Vec3 D{x4,y4,0};
    auto AB=B-A;
    auto AC=C-A;
    auto AD=D-A;
    auto CD=D-C;
    auto CA=A-C;
    auto CB=B-C;
    long a = getSign(AB.cross(AC).z);
    long b = getSign(AB.cross(AD).z);
    long c = getSign(CD.cross(CA).z);
    long d = getSign(CD.cross(CB).z);
    bool intersects = (a*b<=0&&c*d<=0);
    if(a==0&&b==0){
        intersects = rangeInRange(A.x,B.x,C.x,D.x) && rangeInRange(A.y,B.y,C.y,D.y);
    }
    return intersects;
}

int main(){
    long a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    cout<<(isIntersects(a,b,c,d,e,f,g,h)?"Yes":"No")<<endl;
}
