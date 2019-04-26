p,phi,arr,fact = [27,11,13,37],[18,10,12,36],[1]*40,[1]*40

def crt(a): # Chinese Remainder Theorem
	prod, ret = reduce(lambda x,y: x*y,p,1), 0
	for i in range(4): ret += a[i]*(prod/p[i])*pow(prod/p[i],phi[i]-1,p[i])
	return (ret%prod + prod)%prod

# Precalculation	
for i in range(2,40):
	x = 1
	if i%3: x = i
	arr[i], fact[i] = arr[i-1]*x%27, fact[i-1]*i
	
def lucas(n,r,p): # Using Lucas Theorem to find nCr modulo prime.
	if n < p: return (fact[n]/(fact[r]*fact[n-r]))%p	
	ret = 1	
	while r: ret,n,r = ret*lucas(n%p,r%p,p)%p, n/p, r/p
	return ret

def E(n,p): # exponent of p in n!
	ret,n = 0,n/p
	while n: ret, n = ret+n, n/p
	return ret

def f(n): # product of numbers <=n, and coprime to 3.
	return pow(arr[27],n/27,27)*arr[n%27]

def F(n): # n!/3^e modulo 27, where 3^e||n!
	i,ret = 1,1
	while i <= n: ret,i = (ret*f(n/i))%27,3*i
	return ret

def mod_27(n,r): # nCr modulo 27
	pow3 = E(n,3) - E(r,3) - E(n-r,3)
	mod1, mod2 = F(n),(F(r)*F(n-r))%27
	return (pow(3,pow3,27)*mod1*pow(mod2,17,27))%27

for t in range(input()):
	n,r = map(int,raw_input().split())
	a = [mod_27(n,r), lucas(n,r,p[1]), lucas(n,r,p[2]), lucas(n,r,p[3])]
	print crt(a)