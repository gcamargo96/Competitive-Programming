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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 5005;
int n, m;
vi adj[N];
vector<ii> trap[N];
vi corners;
bool vis[N];

int dfs(int u, int l, int r){
	if(l > r) return 0;
	if(u == n) return 1;
	vis[u] = 1;

	int ok = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		int lv = trap[u][i].fi, rv = trap[u][i].se;

		if(!vis[v] and l >= lv and r <= rv){
			ok |= dfs(v, l, r);
		}
	}

	return ok;
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v, l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d%d", &u, &v, &l, &r);
		adj[u].pb(v);
		adj[v].pb(u);
		trap[u].pb({l,r});
		trap[v].pb({l,r});
		corners.pb(l);
		corners.pb(r);
	}

	sort(corners.begin(), corners.end());
	corners.resize(unique(corners.begin(), corners.end()) - corners.begin());

	int ans = 0;
	for(int i = 0; i < corners.size(); i++){
		int lo = i, hi = corners.size()-1;
		while(lo <= hi){
			int mid = (lo+hi)/2;
			memset(vis, 0, sizeof vis);

			if(dfs(1, corners[i], corners[mid])){
				// printf("%d %d\n", corners[l], corners[mid]);
				ans = max(ans, corners[mid]-corners[i]+1);
				lo = mid+1;
			}
			else{
				hi = mid-1;
			}
		}
	}

	if(ans > 0){
		printf("%d\n", ans);
	}
	else{
		printf("Nice work, Dima!\n");
	}

	return 0;
}