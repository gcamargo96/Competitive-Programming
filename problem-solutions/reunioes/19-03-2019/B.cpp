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

const int N = 100005;
int n, m, s, t, c, d;
int p[N];
vi adj[N], peso[N];
ll dist[N];
int closest[N];

int main(void){
	scanf("%d%d%d", &n, &m, &s);
	scanf("%d", &t);

	int u, v, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		adj[u].pb(v);
		adj[v].pb(u);
		peso[u].pb(v);
		peso[v].pb(u);
	}

	priority_queue<pair<ll,int> , vector<pair<ll,int> >, greater<pair<ll,int> > > pq;

	int x, pp;
	for(int i = 0; i < s; i++){
		scanf("%d%d", &x, &pp);
		p[x] = pp;
		closest[x] = x;
		pq.push(ii(0, x));
	}

	scanf("%d%d", &c, &d);
	pq.push(ii(0, d));

	for(int i = 0; i < N; i++){
		dist[i] = INF;
	}

	while(!pq.empty()){
		int u = pq.top().se;
		ll d = pq.top().fi;
		pq.pop();

		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			ll w = peso[u][i];

			if(d+w < dist[v]){
				dist[v] = d+w;
				closest[v] = closest[u];
				pq.push(mp(dist[v], v));
			}
			else if(d+w)
		}
	}

	return 0;
}