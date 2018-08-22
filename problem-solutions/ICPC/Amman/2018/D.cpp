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

#define INF 1000000000000000000LL

int t, n, m;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &m);

		ll ans = INF;

		if(n%2 == 1){
			ans = min(ans, ll((n+1)/2) * ll(m));
		}
		else{
			ll cnt = n+1;
			ll q = m/2;
			ll r = m%2;

			ans = min(ans, q*cnt + r*ll(n/2));
		}
		
		if(m%2 == 1){
			ans = min(ans, ll((m+1)/2) * ll(n));
		}
		else{
			ll cnt = m+1;
			ll q = n/2;
			ll r = n%2;

			ans = min(ans, q*cnt + r*ll(m/2));
		}

		printf("%lld\n", ans);
	}

	return 0;
}