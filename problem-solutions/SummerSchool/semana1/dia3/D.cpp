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
int n, k, l;
int x;
priority_queue<ii> pq;
vi adj[N];
vi peso[N];
int dist[N], pai[N];

void dijkstra(){
	while(!pq.empty()){
		int u = pq.top().se;
		int d = -pq.top().fi;
		pq.pop();

		For(i,0,adj[u].size()){
			int v = adj[u][i];
			if(dist[v] > d + peso[u][i]){
				pai[v] = pai[u];
				dist[v] = d + peso[u][i];
				pq.push(mp(-dist[v], v));
			}
		}
	}
}

int main(void){
	memset(dist, INF, sizeof dist);
	
	scanf("%d%d%d", &n, &k, &l);
	for(int i = 1; i <= k; i++){
		pai[i] = i;
	}

	For(i,0,n){
		scanf("%d", &x);
	
		if(dist[x] == 0){
			printf("0\n");
			return 0;
		}

		pq.push(mp(0,x));
		dist[x] = 0;
	}

	int u, v, w;
	For(i,0,l){
		scanf("%d%d%d", &u, &v, &w);
		adj[u].pb(v);
		peso[u].pb(w);

		adj[v].pb(u);
		peso[v].pb(w);
	}

	dijkstra();

	/*for(int i = 1; i <= k; i++){
		printf("dist[%d] = %d\n", i, dist[i]);
	}*/

	int menor = INF;
	for(int u = 1; u <= k; u++){
		For(i,0,adj[u].size()){
			int v = adj[u][i];
			int d = dist[u] + dist[v] + peso[u][i];
			if(pai[u] != pai[v]){
				menor = min(menor, d);
			}
		}
	}

	printf("%d\n", 3*menor);

	return 0;
}

