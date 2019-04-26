#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000005;
int t;
ll n, k, m;
bool vis[N];
vector<ll> primes;

void sieve(){
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			primes.pb(i);

			for(int j = i+i; j < N; j += i){
				vis[j] = 1;
			}
		}
	}
}

vi factorize(int m){
	vector<ll> factors;
	for(int i = 0; i < primes.size(); i++){
		if(m%primes[i] == 0){
			int aux = m;
			while(aux > 1){
				factors.pb(primes[i]);
				aux /= primes[i];
			}
		}
	}
	return factors;
}

void extended_gcd(ll a, ll b, ll& lastx, ll& lasty){
	ll x, y, q, tmp;
	x = 0; lastx = 1;
	y = 1; lasty = 0;
	while (b != 0) {
		q = a / b;
		tmp = b;
		b = a % b;
		a = tmp;

		tmp = x;
		x = lastx - q*x;
		lastx = tmp;

		tmp = y;
		y = lasty - q*y;
		lasty = tmp;
	}
}

ll mod_inverse(ll a, ll m) {
	ll lastx, lasty;
	extended_gcd(a, m, lastx, lasty);
	while (lastx < 0)
		lastx += m;
	return lastx;
}

ll nCrModpDP(ll n, ll r, ll p){ 
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;
  
    for (int i = 1; i <= n; i++){ 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 

ll nCrModpLucas(ll n, ll r, ll p){ 
	if (r==0) 
		return 1; 

	ll ni = n%p, ri = r%p; 

	return (nCrModpLucas(n/p, r/p, p) * nCrModpDP(ni, ri, p)) % p;  
} 

ll ncr(ll n, ll k){
	vector<ll> factors = factorize(m);

	for(int i = 0; i < factors.size(); i++){

	}
}

int main(void){
	sieve();	
	scanf("%d", &t);

	while(t--){
		scanf("%lld%lld%lld", &n, &m, &k);

		if(n%k == 0){
			printf("%lld 1\n", n/k);
			continue;
		}

		ll q = n/k, r = n%k;
		ll ans = ncr(q-1 + r, r);
		printf("%lld\n", ans);
	}

	return 0;
}