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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n;
vector<int> adj[N];
bool vis[N];
double ans = 0;

void dfs(int u, int dist, double prob){
	vis[u] = 1;

	int ways = (int)adj[u].size();
	if(u != 1) ways--;
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]){
			dfs(v, dist+1, prob*(1.0/(double)ways));
		}
	}

	if(ways == 0){
		ans += ((double)dist)*prob;
	}
}

int main(void){
	scanf("%d", &n);

	int u, v;
	For(i,0,n-1){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0, 1.0);

	printf("%lf\n", ans);

	return 0;
}