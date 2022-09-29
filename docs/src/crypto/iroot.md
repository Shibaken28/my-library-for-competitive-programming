# 累乗根
## 概要
\\(y,n\\)から\\(x^n\leq y\\)を満たすような最大の整数\\(x\\)を求める．
## 計算量
\\(O(\log N)\\)

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
```
