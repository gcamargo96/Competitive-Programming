#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define int ll

const int N = 200002;
int n;
int a[N], res[N];
vector<ll> adj[N], peso[N];
vector<ll> acum, nodes;
int memo[N], pai[N];

int dfs(int u){
	nodes.pb(u);
	int l = 0, r = acum.size()-1, ans = 0;
	int sum = acum[r];
	
	//printf("atual = %d\n", u); 
	while(l < r){
		//printf("%d %d\n", l, r);
		int mid = (l+r)/2;
		ans = mid;
		if(sum - acum[mid] <= a[u]){
			r = mid;
		}
		else{
			l = mid+1;
		}
		//ans = (l+r)/2;
	}
	ans = l;
	//printf("%d %d\n", l, r);

	/*For(i,0,acum.size()){
		printf("%d ", acum[i]);
	}
	printf("\n");
	*/

	/*printf("nodes: "); 
	For(i,0,acum.size()){
		printf("%d ", nodes[i]);
	}
	printf("\n");
	*/
	//printf("busca binaria = %d\n", ans);
	//if(sum - acum[ans-1] <= a[u]) ans--;
	//if(sum - acum[ans-1] > a[u]) ans++;

	int last = nodes[/*nodes.size()-1-*/ans/*-1*/];
	//printf("ans = %d / last = %d / acum[%d] = %d / sum = %d\n", ans, last, ans, acum[ans], sum);
	//printf("%d %d\n", l, r);
	memo[pai[last]]++;
	
	//printf("ans = %d /atual = %d / last = %d / pai[%d] = %d\n", ans, u, last, last, pai[last]);

	For(i,0,adj[u].size()){
		int v = adj[u][i];
		int w = peso[u][i];
		acum.pb(acum[acum.size()-1] + w);
		res[u] += dfs(v);
		acum.pop_back();
	}

	res[u] -= memo[u];
	nodes.pop_back();
	if(adj[u].size() == 0){
		return 1;
	}
	else{
		return res[u] /*- memo[u]*/ + 1;
	}
}

 main(void){
	scanf("%lld", &n);

	For(i,1,n+1){
		scanf("%lld", &a[i]);
	}

	int p, w;
	For(i,1,n){
		scanf("%lld%lld", &p, &w);
		adj[p].pb(i+1);
		peso[p].pb(w);
		pai[i+1] = p;
	}

	pai[1] = 0;
	acum.pb(0);
	//nodes.pb(0);
	dfs(1);

	for(int i = 1; i <= n; i++){
		printf("%lld ", res[i]);
	}
	printf("\n");

	return 0;
}
