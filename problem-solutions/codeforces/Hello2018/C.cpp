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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 32;
ll c[N], bestc[N], pot[N];
ll l;
int n;

int main(void){
	pot[0] = 1;
	for(int i = 1; i <= 31; i++){
		pot[i] = 2LL * pot[i-1];
	}

	scanf("%d%lld", &n, &l);

	for(int i = 0; i < n; i++){
		scanf("%lld", &c[i]);
	}

	bestc[0] = c[0];
	for(int i = 1; i <= 31; i++){
		bestc[i] = 2LL*bestc[i-1];
		if(i < n)
			bestc[i] = min(c[i], bestc[i]);
		// printf("bestc[%d] = %lld\n", i, bestc[i]);
	}

	// ll aux = l, ans = 0;
	// for(ll i = 31; i >= 0; i--){
	// 	if((1LL<<i) <= aux){
	// 		ans += bestc[i];
	// 		aux -= (1LL<<i);
	// 	}
	// }

	ll ans = 0;
	for(ll i = 0; i <= 31; i++){
		if(((l>>i) & 1) == 1){
			ans += bestc[i];
		}
		else if(bestc[i] < ans){
			ans = bestc[i];
		}
	}

	// for(int i = 0; i <= 31; i++){
	// 	if(pot[i] >= l){
	// 		ans = min(ans, bestc[i]);

	// 		if(i > 0){
	// 			for(int j = 0; j < n; j++){
	// 				if(pot[i-1] + pot[j] >= l){
	// 					ans = min(ans, bestc[i-1] + bestc[j]);
	// 				}
	// 			}
	// 		}
	// 	}
	// }


	// ll pot = 1;
	// ll bestpot = 1000000002;
	// bool ok = 0;
	// int i;
	// for(i = 0; i < n; i++){
	// 	if(pot >= l){
	// 		bestpot = c[i];
	// 		ok = 1;
	// 	}
	// 	pot *= 2;
	// }

	// if(ok)
	// 	ans = min(ans, bestpot);

	printf("%lld\n", ans);

	return 0;
}