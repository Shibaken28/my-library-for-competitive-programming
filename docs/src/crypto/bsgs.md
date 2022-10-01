# baby step giant step

## 概要
素数$p$と$0\leq a,b< p $について，$a^x = b \mod p$となる$x$を求める．

## 計算量
$O(\sqrt{p}) $

## ソースコード
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

## 実行例
```python
x = BSGS(10,3,97)
print(x)

x = BSGS(12345,1,998244353)
print(x)

x = BSGS(2,3,7)
print(x) #存在しない
```
```python
2
142606336
-1
```
存在しないと$-1$が返される．
