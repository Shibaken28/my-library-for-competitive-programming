# rho法素因数分解
## 概要
かなり粗い．素因数分解ができるかもしれない．だいたい\\(O(\sqrt{p})\\)な気がする

```python
import random

def GCD(a,b):
    if a%b==0:
        return b
    return GCD(b,a%b)

def f(x,m):
    return (x*x+1)%m

def factor(N):
    fac=[]
    while(N%2==0):
        N//=2
        fac.append(2)
        print("[+] find: ",2)
    step = 0
    while True:
        if N == 1:
            break
        t = random.randint(1,N)
        s1 = t
        s2 = t
        while True:
            step += 1
            t1 = f(s1,N)
            t2 = f(f(s2,N),N)
            D = GCD(abs(t1-t2),N)
            if D!=1:
                break
            s1 = t1
            s2 = t2
        N//=D
        print("[+] find: ",D)
        fac.append(D)
        if N==1:
            break
    fac.sort()
    return fac

N = int(input())
print(factor(N))
```

