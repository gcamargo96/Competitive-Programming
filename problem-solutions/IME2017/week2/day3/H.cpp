#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ii pair<int,int>

const int N = 500002;
int n, m, k;
vi adj[N];
int q[N], in[N], out[N], vis[N];
set<ii> s;
int tempo = 1, borda = 0;

void dfs(int u){
	vis[u] = 1;
	in[u] = tempo++;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			dfs(v);
		}
	}

	out[u] = tempo++;
}

bool cmp_in(int a, int b){
	return in[a] < in[b];
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
		scanf("%d", &k);
		for(int i = 0; i < k; i++){
			scanf("%d", &q[i]);
		}

		if(k == 1){
			printf("0\n");
			continue;
		}

		sort(q, q+k, cmp_in);
	
		/*printf("sort = ");
		for(int i = 0; i < k; i++){
			printf("%d ", q[i]);
		}
		printf("\n");
		*/

		for(int i = 0; i < adj[q[0]].size(); i++){
			int u = adj[q[0]][i];
			if(in[u] < in[q[0]]) continue;

			int cnt = 0;
			for(int j = 1; j < k; j++){
				int v = q[j];
				if(in[v] >= in[u] and out[v] <= out[u]){
					// printf("u = %d / v = %d\n", u, v);
					cnt++;
				}
			}
			if(cnt == k-1){
				// printf("aqui\n");
				borda++;
				break;
			}
		}

		for(int i = 1; i < k; i++){
			int u = q[i];
			if(in[u]+1 == out[u]){
				borda++;
			}
		}

		// printf("borda = %d\n", borda);
		printf("%d\n", (borda+1)/2);
		borda = 0;
	}

	return 0;
}