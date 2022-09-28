# 線分の交差判定
## 概要
線分同士が共通する点を持つかを判定．

```cpp

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
```

