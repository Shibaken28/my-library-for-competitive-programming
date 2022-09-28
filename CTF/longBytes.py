from Crypto.Util.number import getPrime, bytes_to_long, long_to_bytes,inverse,isPrime

def bytesToLong(b : bytes):
    res = 0
    for a in b:
        res = (res << 8) + a
    return res

def longToBytes(n : int):
    S = ""
    while n>0:
        S += chr(n%(1<<8))
        n >>= 8
    T = S[::-1] # 逆順に
    return T.encode(encoding='utf-8')

m = b'Hello'
a = bytesToLong(m)
print(a)
print(longToBytes(a))
