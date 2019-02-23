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

#define M 1000000007

const int N = 10005;
int t, n, k;
int v[N];

ll mul(ll a, ll b){
	return (a*b)%M;
}

ll f(ll a){
	return (mul(a,a) - a + M)%M;
}

ll calc(){
	ll ans = 1;
	for(int i = 1; i <= k; i++){
		ans = mul(ans, f(v[i]));
		// printf("%d ", v[i]);
	}
	// printf("\n");
	return ans;
}

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &k);

		if(k == 1){
			printf("%d\n", n);
			continue;
		}

		int sum = 0;
		for(int i = 1; i < k; i++){
			v[i] = i;
			sum += i;
		}

		if(n-sum < k){
			printf("-1\n");
			continue;
		}

		v[k] = n-sum;
		sum = n;

		ll ans = calc();

		// int acc = 0;
		// while(v[k]-(k-1) > v[k-1]+1){
		// 	acc++;
		// 	v[k] -= k-1;
		// 	v[k-1]++;
		// }

		// for(int i = 1; i < k-1; i++){
		// 	v[i] += acc;
		// }
		// ans = calc();

		while(v[k]-v[k-1] > 2){
			for(int i = k-1; i >= 1 and v[k] > v[k-1]+1; i--){
				v[i]++;
				v[k]--;
			}

			if(v[k] > v[k-1]){
				ans = max(ans, calc());
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}