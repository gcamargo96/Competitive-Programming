#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n;

int main(void){
	scanf("%lld", &n);

	ll ans = n/2LL+1LL;

	for(ll i = 2; i <= n; i++){
		if(n%i == 0){
			ll qnt = n/i;
			ll aux = ll(qnt/2LL+1LL) * ll(i/2LL+1LL);
			ans = min(ans, aux);
		}
	}

	printf("%lld\n", ans);

	return 0;
}