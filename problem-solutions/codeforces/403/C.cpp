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

const int N = 200002;
vi adj[N];
int cor[N], vis[N];
int cnt = 1, n;
set<int> cores, aux;

void dfs(int u){
	vis[u] = 1;
	cores.erase(cor[u]);

	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(vis[v]){
			aux.insert(cor[v]);
			cores.erase(cor[v]);
		}
	}

	queue<int> q;
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]){
			cor[v] = *(cores.begin());
			aux.insert(*(cores.begin()));
			cores.erase(*(cores.begin()));
			q.push(v);
		}
	}

	cores.insert(cor[u]);
	for(int c : aux){
		cores.insert(c);
	}
	aux.clear();
	
	while(!q.empty()){
		dfs(q.front());
		q.pop();
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

	int res = 0;
	for(int i = 1; i <= n; i++){
		res = max(res, (int)adj[i].size()+1);
		cores.insert(i);
	}

	cor[1] = 1;
	dfs(1);

	printf("%d\n", res);
	for(int i = 1; i <= n; i++){
		printf("%d ", cor[i]);
	}
	printf("\n");

	return 0;
}

