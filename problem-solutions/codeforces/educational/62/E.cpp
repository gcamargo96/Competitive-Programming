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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;


const ll MOD = 998244353LL;
const int N = 200005;
ll n, k;
ll f[N], v[N];

ll mul(ll a, ll b){
	return (a*b)%MOD;
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

ll Div(ll a, ll b){
	return mul(a, fastpow(b, MOD-2));
}

void precalc(){
	f[k+1] = 1;
	f[k] = k;
	for(int i = k-1; i >= 1; i--){
		f[i] = mul(i, f[i+1]);
	}
}

ll solve(ll pos, ll neg){
	ll opts = k - pos;
	ll replaces = neg;

	if(opts <= 0 or opts < replaces){
		// printf("0\n");
		return 0;
	}

	// printf("opts = %lld, replaces = %lld\n", opts, replaces);

	ll id = k-pos-replaces+1;
	// printf("id = %lld\n", id);

	if(id+replaces > k+1){
		return 0;
	}

	ll A = Div(f[id], f[id+replaces]);

	// printf("A = %lld\n", A);

	return A;
}

int main(void){
	scanf("%lld%lld", &n, &k);
	precalc();

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
	}

	ll neg = 0;
	set<ll> pos;
	for(int i = 0; i < n; i += 2){
		if(v[i] == -1){
			neg++;
		}
		else{
			pos.insert(v[i]);
		}
	}

	ll A = solve(pos.size(), neg);

	neg = 0;
	pos.clear();
	for(int i = 1; i < n; i += 2){
		if(v[i] == -1){
			neg++;
		}
		else{
			pos.insert(v[i]);
		}
	}

	ll B = solve(pos.size(), neg);
	ll ans = mul(A,B);
	printf("%lld\n", ans);

	return 0;
}