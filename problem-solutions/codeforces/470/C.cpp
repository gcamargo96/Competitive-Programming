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

const int N = 100005;
int n;
int a, b;
ll v[N], t[N];
ll acum[N], cnt[N], extra[N];

int my_upper_bound(ll x, int beg){
	if(acum[n] - acum[beg-1] < x){
		return n+1;
	}

	int l = beg, r = n;
	ll sub = acum[beg-1];
	while(l < r){
		int mid = (l+r)/2;

		if(acum[mid]-sub <= x){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}

	return l;
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
	}

	for(int i = 1; i <= n; i++){
		scanf("%lld", &t[i]);
	}

	for(int i = 1; i <= n; i++){
		acum[i] = acum[i-1] + ll(t[i]);
	}

	for(int i = 1; i <= n; i++){
		int p = my_upper_bound(v[i], i);
		// printf("p = %d\n", p);

		if(p > n){
			cnt[i]++;
			cnt[n+1]--;
			continue;
		}

		if(p > i){
			cnt[i]++;
			cnt[p]--;
			extra[p] += v[i] - (acum[p-1]-acum[i-1]);
		}
		else{
			extra[p] += v[i] - (acum[p-1]-acum[i-1]);
		}
	}

	for(int i = 1; i <= n; i++){
		cnt[i] += cnt[i-1];
	}

	// for(int i = 1; i <= n; i++){
	// 	a = b = i;
	// 	ll q = query(1, 1, n);
	// 	printf("%lld ", q);
	// }
	// printf("\n");

	// for(int i = 1; i <= n; i++){
	// 	printf("%lld ", extra[i]);
	// }
	// printf("\n");


	for(int i = 1; i <= n; i++){
		ll ans = cnt[i]*t[i] + extra[i];
		printf("%lld ", ans);
	}
	printf("\n");

	return 0;
}