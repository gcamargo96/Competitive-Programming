#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 5000005;
ll t, l, r;
ll pot[N];
ll dp[N];
vi primes;
int vis[N];

ll add(ll a, ll b){
	return (a+b)%M;
}

ll mul(ll a, ll b){
	return (a*b)%M;
}

void sieve(){
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			for(int j = i; j < N; j += i){
				if(!vis[j]) vis[j] = i;
			}
		}
	}
}

void precalc(){
	pot[0] = 1;
	for(int i = 1; i < N; i++){
		pot[i] = mul(pot[i-1], t);
	}
}

ll f(ll n){
	if(n == 1) return 0;
	if(dp[n] != -1) return dp[n];

	ll ret = ((n*(n-1))/2LL)%M;
	ll aux = n;
	while(aux > 1){
		ll tam = vis[aux];
		ll groups = n/tam;
		ret = min(ret, add(((n * (tam-1))/2LL)%M, f(groups)));

		aux /= vis[aux];
	}

	return dp[n] = ret;
}

int main(void){
	scanf("%lld%lld%lld", &t, &l, &r);
	precalc();
	sieve();

	memset(dp, -1, sizeof dp);

	ll ans = 0;
	for(int i = 0; i <= r-l; i++){
		// printf("f%d = %lld\n", l+i, f(l+i));	
		ans = add(ans, mul(pot[i], f(l+i)));
	}

	printf("%lld\n", ans);

	return 0;
}