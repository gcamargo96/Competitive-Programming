#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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
 
const int N = 1000002;
ll a, b;
map<ll,ll> dp;
vector<ll> primes;
bool vis[N];

void crivo(){
	for(int i = 2; i <= 1000; i++){
		if(!vis[i]){
			//primes.pb(i);
			for(int j = i+i; j <= 1000000; j += i){
				vis[j] = 1;
			}
		}
	}
	for(int i = 2; i <= 1000000; i++){
		if(!vis[i]) primes.pb(i);
	}
}

ll go(ll x, int id){
	if(x == 1) return 1;
		if(dp.count(x)) return dp[x];

	ll ret = 1;
	For(i,id,primes.size()){
		ll p = primes[i];
		if(p*p > x) break;
		
		if(x%p == 0){
			ret = max(ret, go(x/p, i));
			break;
		}
	}
	ll somar = 1, aux = x;
	For(i,id,primes.size()){
		ll p = primes[i], cnt = 1;
		if(p*p > x) break;
		
		while(aux%p == 0){
			aux /= p;
			cnt++;
		}
		
		somar *= cnt;
	}

	//printf("divisores de %d = %lld\n", x, somar);

	return dp[x] = ret + somar+1;
}
 
int main(void){
	crivo();
	//printf("N PRIMOS = %d\n", primes.size());
	scanf("%lld%lld", &a, &b);
 
	ll res = 0;
	for(ll i = b; i >= a; i--){
		res += go(i, 0) - 1;
	}

	printf("%lld\n", res);
	
	return 0;
}
