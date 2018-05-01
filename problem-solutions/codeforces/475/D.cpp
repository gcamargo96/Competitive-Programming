#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 200005;
int n;
vi adj[N];
bool cut[N];

void destroy(int u, int p){
	cut[u] = 1;
	printf("%d\n", u);

	for(int v : adj[u]){
		if(v != p and !cut[v])
			destroy(v, u);
	}
}

void dfs(int u, int p){
	for(int v : adj[u]){
		if(v != p and !cut[v])
			dfs(v, u);
	}

	int deg = 0;
	for(int v : adj[u]){
		if(!cut[v])
			deg++;
	}

	if(deg%2 == 0)
		destroy(u, p);
}

int main(void){
	scanf("%d", &n);

	int p;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p);
		if(p != 0){
			adj[i].pb(p);
			adj[p].pb(i);
		}
	}

	if(n%2 == 0){
		printf("NO\n");
		return 0;
	}

	int  beg = 0;
	for(int i = 1; i <= n; i++){
		if(adj[i].size()%2 == 0){
			beg = i;
		}
	}

	printf("YES\n");
	dfs(beg, 0);

	return 0;
}