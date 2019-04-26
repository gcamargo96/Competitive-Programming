#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

const int N = 100005, P = 130;
int n, m, s, t, ini, fim;
int price[P];
vi adj[N], peso[N];
ll dist[N], dist_postos[P][P];
int cnt = 1;
unordered_map<int,int> postos;
bool vis[P][P];

void init(){
	for(int i = 0; i < N; i++){
		adj[i].clear();
		peso[i].clear();
	}
	memset(price, 0, sizeof price);
	memset(dist, 0, sizeof dist);
	memset(dist_postos, 0, sizeof dist_postos);
	postos.clear();
	memset(vis, 0, sizeof vis);
	cnt = 1;
}

void dijkstra1(){
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;

	for(auto it : postos){
		int x = it.fi;

		if(x == fim) continue;

		memset(dist, INF, sizeof dist);
		dist[x] = 0;
		pq.push({0LL, x});

		while(!pq.empty()){
			int u = pq.top().se;
			ll d = pq.top().fi;
			pq.pop();

			// printf("u = %d, d = %lld\n", u, d);

			if(dist[u] < d) continue;

			for(int i = 0; i < adj[u].size(); i++){
				int v = adj[u][i];
				ll w = d + peso[u][i];

				if(w < dist[v]){
					dist[v] = w;
					pq.push({w, v});

					if(v == fim or price[v] > 0){
						dist_postos[it.se][postos[v]] = w;
					}
				}
			}
		}
	}
}

ll dijkstra2(){
	priority_queue<tuple<ll,ll,int>, vector<tuple<ll,ll,int> >, greater<tuple<ll,ll,int> > > pq;
	memset(vis, 0, sizeof vis);
	pq.push({0,0,postos[ini]});

	ll ans = 1000000000000000LL;

	while(!pq.empty()){
		int u = get<2>(pq.top());
		ll spent = get<0>(pq.top());
		ll tank = get<1>(pq.top());
		pq.pop();

		// printf("u = %d, spent = %lld, tank = %lld\n", u, spent, tank);

		if(u == postos[fim]){
			return spent;
			// ans = min(ans, spent);
			// continue;
		}
		if(vis[u][tank]) continue;
		vis[u][tank] = 1;

		for(int v = 1; v <= s+1; v++){
			if(u == v) continue;
			
			// if(tank >= dist_postos[u][v]){ // tem o suficiente no tanque
			// 	pq.push({spent, tank-dist_postos[u][v], v});
			// }
			/*else */if(t >= dist_postos[u][v]){
				// coloca o minimo necessario
				ll falta = dist_postos[u][v]-tank;
				if(falta >= 0)
					pq.push({spent + falta*price[u], 0, v});

				// enche o tanque
				falta = t-tank;
				pq.push({spent + falta*price[u], t-dist_postos[u][v], v});				
			}
		}
	}

	return ans;
}

int main(void){
	int tests;
	scanf("%d", &tests);

	while(tests--){
		init();

		scanf("%d%d%d", &n, &m, &s);
		scanf("%d", &t);

		int u, v, w;
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &w);
			adj[u].pb(v);
			adj[v].pb(u);
			peso[u].pb(w);
			peso[v].pb(w);
		}

		int x, p;
		for(int i = 0; i < s; i++){
			scanf("%d%d", &x, &p);
			postos[x] = cnt++;
			price[postos[x]] = p;
		}

		scanf("%d%d", &ini, &fim);
		if(!postos.count(fim)) postos[fim] = cnt++;

		dijkstra1();

		// for(int i = 1; i <= s+1; i++){
		// 	for(int j = 1; j <= s+1; j++){
		// 		printf("%lld ", dist_postos[i][j]);
		// 	}
		// 	printf("\n");
		// }

		ll ans = dijkstra2();

		printf("%lld\n", ans);
	}

	return 0;
}