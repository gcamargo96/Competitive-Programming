#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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
	
struct edge{
	ll u, v, w;

	edge() {}

	edge(ll _u, ll _v, ll _w){
		u = _u;
		v = _v;
		w = _w;
	}
};

const int N = 100002;
int t, n, q, m;
vector<ll> ciclos[N], acum[N], acum2;
vector<edge> e;

void init(){
	for(int i = 0; i < N; i++){
		ciclos[i].clear();
		acum[i].clear();
	}
	acum2.clear();
	e.clear();
}

int main(void){
	scanf("%d", &t);

	while(t--){
		init();

		scanf("%d%d", &n, &q);
		
		for(int i = 1; i <= n; i++){
			scanf("%d", &m);
			
			ll w;
			ciclos[i].pb(0);
			acum[i].pb(0);
			for(int j = 1; j <= m; j++){
				scanf("%lld", &w);
				ciclos[i].pb(w);
				acum[i].pb(acum[i][j-1] + w);
			}
		}

		ll u, v, w;
		e.pb(edge(0,0,0));
		for(int i = 1; i <= n; i++){
			scanf("%lld%lld%lld", &u, &v, &w);
			e.pb(edge(u,v,w));
			if(i == n){
				e[0].v = v;
			}
		}

		acum2.pb(0);
		for(int i = 1; i <= n; i++){
			int u = e[i-1].v; //(i == 1 ? e[n].v : e[i-1].v);
			int v = e[i].u;
			ll x = abs(acum[i][v-1] - acum[i][u-1]); // ll x = acum[i][v-1] - acum[1][u-1];
			x = min(x, acum[i][acum[i].size()-1] - x); // x = min(x, acum[1][acum[1].size()-1] - x);
			x += e[i].w;
			acum2.pb(acum2[i-1] + x);
		}

		/*for(int i = 1; i <= n; i++){
			printf("%d ", acum2[i]);
		}
		printf("\n");
		*/

		int v1, c1, v2, c2;
		for(int i = 0; i < q; i++){
			scanf("%d%d%d%d", &v1, &c1, &v2, &c2);
			
			if(c1 == c2){
				ll x = abs(acum[c1][v2-1] - acum[c1][v1-1]);
				ll ans = min(x, acum[c1][acum[c1].size()-1] - x);
				printf("%lld\n", ans);
				continue;
			}

			if(c1 > c2){
				swap(c1, c2);
				swap(v1, v2);
			}


			// de v1 ate a saida do ciclo c1
			ll x = abs(acum[c1][e[c1].u-1] - acum[c1][v1-1]);
			ll ans = min(x, acum[c1][acum[c1].size()-1] - x);

			// printf("dentro de c1: %lld\n", ans);

			// aresta saindo de c1
			ans += e[c1].w;
			// ciclos intermediarios entre c1 e c2 e arestas entre ciclos
			ans += acum2[c2-1] - acum2[c1];

			// printf("sem contar com c2: %lld\n", ans);

			// da entrada de c2 ate v2
			x = abs(acum[c2][v2-1] - acum[c2][e[c2-1].v-1]);
			ans += min(x, acum[c2][acum[c2].size()-1] - x);
			// printf("x = %lld\n", x);

			// CAMINHO REVERSO
			// de v2 ate a a saida do ciclo c2
			x = abs(acum[c2][v2-1] - acum[c2][e[c2].u-1]);
			ll ans2 = min(x, acum[c2][acum[c2].size()-1] - x);

			// printf("dentro de c2: %lld\n", ans2);

			// aresta saindo de c2
			ans2 += e[c2].w;

			// ciclos intermediarios entre c2 e cf e arestas entre ciclos
			ans2 += acum2[n] - acum2[c2];

			// aresta entre cf e ci
			// if(c2 != n) ans2 += e[n].w;

			// ciclos intermediarios entre ci e c1 e arestas entre ciclos
			ans2 += acum2[c1-1];

			// printf("sem contar com c1: %lld\n", ans2);

			// de entrada de c1 a v1
			x = abs(acum[c1][e[c1-1].v-1] - acum[c1][v1-1]);
			ans2 += min(x, acum[c1][acum[c1].size()-1] - x);

			// printf("%lld %lld\n", ans, ans2);
			ans = min(ans, ans2);

			printf("%lld\n",ans);
		}
	}

	return 0;
}