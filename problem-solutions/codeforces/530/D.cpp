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

const int N = 100005;
int p[N];
ll s[N];
vi adj[N];
int n;

bool check(int u){
	if(s[u] < s[p[u]]) return 0;

	bool ret = 1;
	for(int v : adj[u]){
		ret &= check(v);
	}

	return ret;
}

int main(void){
	scanf("%d", &n);

	for(int u = 2; u <= n; u++){
		scanf("%d", &p[u]);
		adj[p[u]].pb(u);
	}

	for(int i = 1; i <= n; i++){
		scanf("%lld", &s[i]);
	}

	for(int u = 1; u <= n; u++){
		if(s[u] == -1){
			s[u] = s[p[u]];

			ll mn = INF;
			for(int v : adj[u]){
				mn = min(mn, s[v]);
			}
			if(mn != INF){
				s[u] = mn;
			}
		}
	}

	if(!check(1)){
		printf("-1\n");
		return 0;
	}

	ll ans = s[1];
	for(int u = 2; u <= n; u++){
		ans += s[u]-s[p[u]];
	}
	printf("%lld\n", ans);

	return 0;
}