/*
線分の当たり判定

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



struct Vector3D{
    double x{0},y{0},z{0};
    constexpr Vector3D(double x,double y,double z){
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    constexpr Vector3D(double x1,double y1,double z1,double x2,double y2,double z2){
        this -> x = x2 - x1;
        this -> y = y2 - y1;
        this -> z = z2 - z1;
    }
    constexpr Vector3D cross(const Vector3D &a){
        return Vector3D(this->y * a.z - this->z * a.y, this->z * a.x - this->x * a.z, this->x * a.y - this->y * a.x);
    }
    ostream &operator << (ostream &out, const Vector3D &a){
        cout<<"{"<<a.x<<", "<<a.y<<", "<<a.z<<"}";
        return out;
    }
};


int main(){

}
