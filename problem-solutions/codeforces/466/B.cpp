#include <bits/stdc++.h>
using namespace std;
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

ll n, k, a, b;

int main(void){
	scanf("%lld%lld%lld%lld", &n, &k, &a, &b);

	if(n == 1){
		printf("0\n");
		return 0;
	}
	if(k == 1){
		ll ans = (n-1)*a;
		printf("%lld\n", ans);
		return 0;
	}

	ll ans = 0;
	while(n > 1){
		if(n%k == 0){
			if(b < (n-(n/k))*a){
				ans += b;
				n /= k;
			}
			else{
				ans += (n-(n/k))*a;
				n /= k;
			}
		}
		else{
			if(n > k){
				ans += (n%k)*a;
				n -= (n%k);
			}
			else{
				ans += (n-1)*a;
				n = 1;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}