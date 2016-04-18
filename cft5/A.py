def qpow(a, b):
    if (b == 1):
        return a
    temp = qpow(a, b >> 1)
    if (b & 1):
        return temp * temp * a
    else:
        return temp * temp

lst = map(int, raw_input().split(' '))
m, n = lst[0], lst[1]
# print m, n
total = 0
for i in xrange(1, m + 1):
    total = total + (qpow(float(i) / m, n) - qpow((i - 1.0) / m, n)) * i
print total
# out = str(total)
# print "%s.%s"%(out[:-7], out[-6:])
