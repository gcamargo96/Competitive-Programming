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

void init(){
	For(i,0,N){
		dist[i] = 100000000000000000LL;
		peso[i].clear();
		adj[i].clear();
	}
}

void dijkstra(int beg){
	dist[beg] = 0;
	priority_queue<pair<ll,int> > pq;
	pq.push(pair<ll,int>(0,beg));

	while(!pq.empty()){
		int u = pq.top().se;
		ll d = -pq.top().fi;
		pq.pop();

		For(i,0,adj[u].size()){
			int v = adj[u][i];
			ll w = peso[u][i];

			if(d + w < dist[v]){
				dist[v] = d+w;
				pq.push(pair<ll,int>(-dist[v], v));
			}
		}

		/*if(u >= 1 and u <= k){
			for(int v = 1; v <= k; v++){
				if(v != u){
					if(d + x < dist[v]){
						dist[v] = d+x;
						pq.push(ii(-dist[v],v));
					}
				}
			}
		}*/
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

		for(int i = 1; i <= k; i++){
			for(int j = i+1; j <= k; j++){
				if(i != j){
					adj[i].pb(j);
					adj[j].pb(i);
					peso[i].pb(x);
					peso[j].pb(x);
				}
			}
		}

		dijkstra(s);

		for(int i = 1; i <= n; i++){
			printf("%lld ", dist[i]);
		}
		printf("\n");
	}

	return 0;
}
