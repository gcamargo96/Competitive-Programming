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

#define INF 0x3f3f3f3f

const int N = 1000005;
int t, n;
int vis[N];
int a[N];

void crivo(int x){
	if(vis[x] != INF) return;
	
	for(int i = x; i < N; i += x){
		vis[i] = min(vis[i], x);
	}
}

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		memset(vis, INF, sizeof vis);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}

		sort(a, a+n);

		for(int i = 0; i < n; i++){
			crivo(a[i]);
		}

		ll ans = 0;
		for(int i = 0; i < n; i++){
			a[i] = vis[a[i]];
			ans += ll(a[i]);
			// printf("%d ", a[i]);
		}

		printf("%lld\n", ans);
	}

	return 0;
}