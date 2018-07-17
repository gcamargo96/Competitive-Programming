#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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
int n, ans = 0;
vi adj[N];

int dfs(int u, int p){
	int tot = 1;
	for(int v : adj[u]){
		if(v == p) continue;

		int sz = dfs(v, u);
		tot += sz;
		if(sz%2 == 0){
			ans++;
		}
	}

	return tot;
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0);

	if(n%2 == 1){
		printf("-1\n");
	}
	else{
		printf("%d\n", ans);
	}

	return 0;
}