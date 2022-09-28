# GCD,LCM
## 概要
最大公約数，最小公倍数を求めます．

## 計算量
\\(O(\log a)\\)

```python
def GCD(a,b):
    if a%b==0:
        return b
    return GCD(b,a%b)

def LCM(a,b):
    return a//GCD(a,b)*b
```

