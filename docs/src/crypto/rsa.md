# RSAテンプレ
## 概要
`PyCryptodome`ライブラリを使用した実装例です．

```python
from Crypto.Util.number import getStrongPrime, bytes_to_long, long_to_bytes, inverse

# 各パラメータの設定
m = bytes_to_long(b'this_is_secret_message')
e = 0x10001
p = getStrongPrime(1024)
q = getStrongPrime(1024)
n = p * q
assert p != q

# 暗号文
c = pow(m,e,n)

# 復元
phi = (p-1)*(q-1)
d = inverse(e,phi) # pow(e,-1,phi)でも可
m2 = pow(c,d,n)

print("[+] 公開鍵")
print(f'[+] e = {hex(e)}')
print(f'[+] n = {hex(n)}')
print(f'[+] c = {hex(n)}')
print("[+] 秘密情報")
print(f'[+] p = {hex(p)}')
print(f'[+] q = {hex(q)}')
print(f'[+] d = {hex(d)}')
print(f'[+] m = {hex(m)}')
print("[+} 計算結果")
print(f'[+] {long_to_bytes(m2)}')
```
