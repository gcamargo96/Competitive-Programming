#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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
int t, n, k, m, s;
ll x;
vi adj[N];
vector<ll> peso[N];
ll dist[N];
priority_queue<pair<ll, int> > pq;

void init(){
	For(i,0,N){
		dist[i] = 1000000000000000LL;
		adj[i].clear();
		peso[i].clear();
	}
	while(!pq.empty()) pq.pop();
}

void dijkstra(int x){
	//dist[x] = 0;
	pq.push(mp(-dist[x],x));

	while(!pq.empty()){
		int u = pq.top().se;
		ll d = -pq.top().fi;
		pq.pop();

		For(i,0,adj[u].size()){
			int v = adj[u][i];
			ll w = peso[u][i];

			if(d + w < dist[v]){
				dist[v] = d+w;
				pq.push(mp(-dist[v],v));
			}
		}
	}
}

int main(void){
	scanf("%d", &t);

	while(t--){
		init();
		scanf("%d%d%lld%d%d", &n, &k, &x, &m, &s);
		
		int u, v;
		ll w;
		For(i,0,m){
			scanf("%d%d%lld", &u, &v, &w);
			adj[u].pb(v);
			adj[v].pb(u);
			peso[u].pb(w);
			peso[v].pb(w);
		}

		dist[s] = 0;
		dijkstra(s);

		ll mindist = 1000000000000000LL;
		for(int i = 1; i <= k; i++){
			mindist = min(mindist, dist[i]);
		}
		for(int i = 1; i <= k; i++){
			dist[i] = min(dist[i], mindist+x);
		}
		for(int i = 1; i <= k; i++){
			dijkstra(i);
		}

		for(int i = 1; i <= n; i++){
			printf("%lld ", dist[i]);
		}
		printf("\n");
	}

	return 0;
}

