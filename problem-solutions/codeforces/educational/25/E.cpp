#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second

const int N = 100002;
int n, m, cnt = 1;
vector<int> adj[N];
int in[N], label[N], nxt[N], vis[N];

void toposort(){
	priority_queue<ii, vector<ii>, greater<ii> > pq;

	for(int i = 1; i <= n; i++){
		if(in[i] == 0){
			pq.push(ii(nxt[i], i));
		}
	}

	while(!pq.empty()){
		int u = pq.top().se;
		int nxtu = pq.top().fi;
		// printf("node = %d / nxt = %d\n", u, nxtu);
		pq.pop();

		label[u] = cnt++;

		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			int nxtv = nxt[v];
			in[v]--;
			if(in[v] == 0) pq.push(ii(nxtv, v));
		}
	}
}

int dfs(int u){
	vis[u] = 1;
	nxt[u] = u;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			nxt[u] = min(nxt[u], dfs(v)); 
		}
		else{
			nxt[u] = min(nxt[u], nxt[v]);
		}
	}

	return nxt[u];
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		in[v]++;
	}

	for(int u = 1; u <= n; u++){
		if(in[u] == 0 and !vis[u]) nxt[u] = dfs(u);
	}

	toposort();

	for(int i = 1; i <= n; i++){
		printf("%d ", label[i]);
	}
	printf("\n");

	return 0;
}