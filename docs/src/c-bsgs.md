# baby step giant step

## 概要
素数\\(p\\)と\\(0\leq a,b< p \\)について，\\(a^x = b \mod p\\)となる\\(x\\)を求める．

## 計算量
\\(O(\sqrt{p} \\)


```python
def iroot(N,a):
    # x^a <= Nとなる最大の整数x
    ok = 0
    ng = N
    while(abs(ok-ng)>1):
        mid = (ok+ng)//2
        d = mid**a
        if d <= N:
            ok = mid
        else:
            ng = mid
    return ok 

def BSGS(a:int,b:int,p:int):
    # a^x = b mod pとなるxを求める
    x = -1
    m = iroot(p,2)+1
    dct = dict()
    ax = 1
    for i in range(m+1):
        dct[ax] = i
        ax = (ax*a)%p
    
    am = pow(pow(a,-1,p),m,p)
    for i in range(m+1):
        d = (pow(am,i,p)*b)%p
        if d in dct:
            if i==0 and dct[d] ==0:
                continue
            x = i*m + dct[d]
            break
    return x
```