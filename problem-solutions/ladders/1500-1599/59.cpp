#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const ll MOD = 1000000007;
const int N = 1000002;

ll a, b, n;
ll fact[N];

void precalc(){
	fact[0] = 1;

	For(i,1,N){
		fact[i] = (fact[i-1]*i)%MOD;
	}
}

ll fastpow(ll b, ll e){
	if(b == 0) return 0;
	if(e == 0) return 1LL;

	ll x = fastpow(b, e/2LL)%MOD;
	if(e%2LL == 0){
		return (x*x)%MOD;
	}
	else{
		return ((b*x)%MOD * x)%MOD;
	}
}

int main(void){
	precalc();
	scanf("%lld%lld%lld", &a, &b, &n);

	ll res = 0;
	for(int i = 0; i <= n; i++){
		ll sum = a*i + b*(n-i);

		while(sum > 0){
			int d = sum%10;
			if(d != a and d != b){
				break;
			}
			sum /= 10;
		}

		if(sum == 0){
			res = ((fastpow((fact[n-i]*fact[i])%MOD, MOD-2)%MOD * fact[n])%MOD + res)%MOD;
		}
	}

	printf("%lld\n", res);
	
	return 0;
}

