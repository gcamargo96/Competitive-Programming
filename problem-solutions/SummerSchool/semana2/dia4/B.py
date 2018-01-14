import sys

def fastpow(b, e):
    if(int(e) == 0):
        return 1

    x = fastpow(int(b), int(e)/2)
    if(int(e)%2 == 0): 
        return int(x)*int(x)
    else: 
        return int(b)*int(x)*int(x)

fat = [1 for i in range(402)]

def precalc():
    i = 1
    while(i < 402):
        fat[i] = i*fat[i-1]
        i = i+1

precalc()
n= int(input())

res = fat[n] * fat[2*n]/(fat[n]*fat[n])
res -= 1

i = 1
while(i < n):
    res -= fat[n]/(fat[n-i]*fat[i]) * fat[2*n - (n-i)]/(fat[n-(n-i)]) * fat[2*n - (n-i)]
    i = i+1

print(res)
