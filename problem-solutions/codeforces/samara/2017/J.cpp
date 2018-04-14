#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 200002;
vi adj[N];
int label[N];
int n;

int precalc(int u, int p){
	bool ret = (adj[u].size() > 2);
	for(int v : adj[u]){
		if(v == p)
			continue;

		ret |= precalc(v, u);
	}

	label[u] = ret;
	return ret;
}

bool dfs(int u, int p, int flag){
	int cnt = 0;
	for(int v : adj[u]){
		if(v == p)
			continue;

		if(label[v] == 1)
			cnt++;
	}

	if(cnt > 2 or (cnt == 2 and flag))
		return 0;

	if(cnt > 1 or adj[u].size() >= 3)
		flag = 1;

	bool ret = 1;
	for(int v : adj[u]){
		if(v == p)
			continue;

		ret &= dfs(v, u, flag);
	}

	return ret;
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	precalc(1, 0);

	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", label[i]);
	// }
	// printf("\n");

	bool ok = dfs(1, 0, 0);

	if(ok)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}