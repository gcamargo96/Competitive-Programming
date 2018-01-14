#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 1000000000

const int N = 52;
vector<int> tudo, peso, pos, ciclo;
vector<int> adj[N];
bool vis[N];
int cnt = 0;

void dfs(int u){
	ciclo.pb(u);
	vis[u] = 1;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]) dfs(v);
	}
}

int main(void){
	int x;
	while(cin >> x){
		tudo.pb(x);
	}

	for(int i = 0; i < tudo.size()/2; i++){
		peso.pb(tudo[i]);
	}
	for(int i = tudo.size()/2; i < tudo.size(); i++){
		pos.pb(tudo[i]);
	}

	int menor_global = INF, pos_menor_global = 0;
	for(int i = 0; i < pos.size(); i++){
		adj[i].pb(pos[i]);
		if(peso[i] < menor_global){
			menor_global = peso[i];
			pos_menor_global = i;
		}
	}

	int ans = 0;
	for(int i = 0; i < pos.size(); i++){
		if(!vis[i]){
			dfs(i);
			
			int menor_local = INF, pos_menor_local = 0;
			for(int j = 0; j < ciclo.size(); j++){
				int u = ciclo[j];
				if(peso[u] < menor_local){
					menor_local = peso[u];
					pos_menor_local = u;
				}
			}

			int aux1 = ((int)ciclo.size()-1) * menor_local;

			int sum = 0;
			for(int j = 0; j < ciclo.size(); j++){
				int u = ciclo[j];
				if(u != pos_menor_local){
					sum += peso[u];
				}
			}
			aux1 += sum;

			int aux2 = 2*(menor_local + menor_global) + ((int)ciclo.size()-1)*menor_global + sum;

			ans += min(aux1, aux2);

			ciclo.clear();
		}
	}

	printf("%d\n", ans);

	return 0;
}