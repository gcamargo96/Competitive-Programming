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

const int N = 100002;
int n, m;
vector<ii> adj[N];
int deg[N];
bool vis[N];
int ans[2*N][2];

void dfs(int u){
	vis[u] = 1;

	For(i,0,adj[u].size()){
		int v = adj[u][i].fi;
		if(!vis[v]) dfs(v);
	}
}

void euler(int u){
	For(i,0,adj[u].size()){
		int v = adj[u][i].fi;
		int e = adj[u][i].se;

		if(ans[e][0] == ans[e][1]){
			ans[e][0] = u;
			ans[e][1] = v;
			euler(v);
		}
	}
}

void euler2(int u)
{
	stack<int> s;
	s.push(u);
	while(!s.empty())
	{
		u = s.top();
		s.pop();
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].fi;
			int e = adj[u][i].se;
			if (ans[e][0] == ans[e][1])
			{
				ans[e][0] = u;
				ans[e][1] = v;
				s.push(v);
			}
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v;
	For(i,0,m){
		scanf("%d%d", &u, &v);
		adj[u].pb(mp(v,i));
		adj[v].pb(mp(u,i));
		deg[u]++;
		deg[v]++;
	}
	
	int start = -1;
	for(int i = 1; i <= n; i++){
		if(deg[i]%2 == 1){
			printf("NO\n");
			return 0;
		}
		if(!vis[i]){
			if(start == -1){
				dfs(i);
				start = i;
			}
			else{
				printf("NO\n");
				return 0;
			}
		}
	}

	euler2(start);

	printf("YES\n");
	For(i,0,m){
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}

	return 0;
}

