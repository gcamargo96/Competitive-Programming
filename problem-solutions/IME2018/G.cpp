#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;
#define MOD 1000000007

const int N = 1000005;
ll n, c;
ll fat[N];

ll add(ll a, ll b){
	return (a+b)%MOD;
}

ll mul(ll a, ll b){
	return (a*b)%MOD;
}

void init(){
	fat[0] = 1;
	for(int i = 1; i < N; i++){
		fat[i] = mul(fat[i-1], i);
	}
}

ll fastpow(ll b, ll e){
	if(e == 0) return 1;

	ll x = fastpow(b, e/2);
	if(e%2 == 0){
		return mul(x, x);
	}
	else{
		return mul(b, mul(x, x));
	}
}

ll ncr(ll n, ll k){
	ll num = fat[n];
	ll den = mul(fat[k], fat[n-k]);
	return mul(num, fastpow(den, MOD-2));
}

int main(void){
	init();
	scanf("%lld%lld", &n, &c);

	ll ans = fat[n];
	ans = mul(ans, fastpow(fat[3], n));
	ans = mul(ans, ncr(n+c-mul(3, n), c - mul(3, n)));

	printf("%lld\n", ans);

	return 0;
}