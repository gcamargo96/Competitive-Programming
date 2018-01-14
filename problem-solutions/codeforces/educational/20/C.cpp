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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n, k, best_gcd = 1;
bool ok = 0;

void calc(ll x){
	ll cur = (k-1LL);//*x;
	ll sum = ((1LL + k-1LL)*(k-1LL))/2LL;
	// sum *= x;

	// ll nxt = n-sum; n-nxt > cur
	if(n/x-sum > cur){
		// printf("sum = %lld, nxt = %lld\n", sum, nxt);
		best_gcd = max(best_gcd, x);
		ok = 1;
	}
}

int main(void){
	scanf("%lld%lld", &n, &k);

	if(k == 1){
		printf("%lld\n", n);
		return 0;
	}

	if(k >= 1000000){
		printf("-1\n");
		return 0;
	}

	for(ll x = 1; x*x <= n; x++){
		if(n%x != 0) continue;
		calc(x);
		if(n/x != x) calc(n/x);
	}

	if(ok){
		ll x = best_gcd;
		ll sum = 0;
		for(int i = 0; i < k-1; i++){
			printf("%lld ", x);
			sum += x;
			x += best_gcd;
		}
		printf("%lld\n", n-sum);
	}
	else{
		printf("-1\n");
	}

	return 0;
}