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

print(iroot(35,2))
print(iroot(36,2))
print(iroot(37,2))
print(iroot(1200,10))


