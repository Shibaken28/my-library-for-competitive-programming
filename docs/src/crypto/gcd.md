# GCD,LCM
## 概要
最大公約数，最小公倍数を求めます．

## 計算量
$O(\log a)$


## ソースコード
```python
def GCD(a,b):
    if a%b==0:
        return b
    return GCD(b,a%b)

def LCM(a,b):
    return a//GCD(a,b)*b
```

## 実行例
```python
print(GCD(18,24))
print(LCM(18,24))
print(GCD(29879889137498173123,13918739184798747613272))
```
```python
6
72
7
```
計算量が$O(\log a)$と小さいため大きな数でも簡単に求められる．
