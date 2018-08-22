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

int t;
ll n, k;

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%lld%lld", &n, &k);

		if(n == 2 or k <= 2){
			printf("Case #%d: 0\n", caso);
			printf("1\n");
			printf("1 2 1\n");
			continue;
		}

		ll sn;
		if(k <= n){
			sn = (k*(k-1))/2LL;

			printf("Case #%d: %lld\n", caso, abs(sn-k));
			printf("%lld\n", k);
			printf("1 %lld %lld\n", n, k);
			for(int i = 1, e = k-1; i <= k-2; i++, e--){
				printf("%d %d %d\n", i, i+1, e);
			}
			printf("%lld %lld %d\n", k-1, n, 1);
		}
		else{
			sn = ((2LL*k-n)*(n-1))/2LL;
			
			printf("Case #%d: %lld\n", caso, abs(sn-k));
			printf("%lld\n", n);
			printf("1 %lld %lld\n", n, k);
			for(int i = 1, e = k-1; i <= n-1; i++, e--){
				printf("%d %d %d\n", i, i+1, e);
			}
		}

	}

	return 0;
}