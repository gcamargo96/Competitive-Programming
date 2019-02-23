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

ll n, k, x;

int main(void){
	scanf("%lld%lld", &n, &k);

	ll ans = 1000000000000000005LL;
	for(ll aux = 1; aux*aux <= n; aux++){
		// printf("%lld\n", a);
		if(n%aux == 0){
			ll a = aux;
			ll b = n/a;
			// cout << a << " " << b << endl;
			for(ll x = a*k; x/k == a; x++){
				if(x%k == b){
					ans = min(ans, x);
				}
			}

			swap(a,b);
			// cout << a << " " << b << endl;
			for(ll x = a*k; x/k == a; x++){
				if(x%k == b){
					ans = min(ans, x);
				}
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}