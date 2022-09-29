# 3次元ベクトル構造体
## 概要
3次元ベクトルの加算減算，外積が計算できる
## ソースコード
```cpp
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

```
