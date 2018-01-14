#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

const int N = 500002;
int n, m, k, temp = 0;
set<int> t;
vi adj[N];
int in[N], out[N], q[N];
bool vis[N];

void dfs(int u){
	vis[u] = 1;
	in[u] = ++temp;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			dfs(v);
		}
	}

	out[u] = ++temp;
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i = 1; i <= n; i++){
		if(adj[i].size() == 1){
			dfs(i);
			break;
		}
	}

	scanf("%d", &m);

	while(m--){
		t.clear();
		scanf("%d", &k);
		
		int primeiro = -1, menor = 1000000000;
		for(int i = 0; i < k; i++){
			scanf("%d", &q[i]);
			if(in[q[i]] < menor){
				menor = in[q[i]];
				primeiro = q[i];
			}
			t.insert(in[q[i]]);
		}

		if(k == 1){
			printf("0\n");
			continue;
		}

		int borda = 0;
		for(int i = 0; i < k; i++){
			u = q[i];
			auto it = t.upper_bound(in[u]);
			if(it == t.end()){
				borda++;
				// printf("aqui\n");
			}
			else if(*it > out[u]){
				borda++;
				// printf("aqui\n");
			}
		}

		int cnt = 0;
		for(int i = 0; i < adj[primeiro].size(); i++){
			v = adj[primeiro][i];
			if(in[v] < in[primeiro]) continue;

			bool tem = 0;
			if(t.count(in[v])) tem = 1;
			auto it = t.upper_bound(in[v]);
			if(it != t.end() and *it < out[u]) tem = 1;
			if(tem) cnt++;
		}
		auto it = t.upper_bound(out[primeiro]);
		if(it != t.end()) cnt++;
		if(cnt == 1){
			borda++;
			// printf("aqui\n");
		}

		// printf("borda = %d\n", borda);
		printf("%d\n", (borda+1)/2);
	}

	return 0;
}