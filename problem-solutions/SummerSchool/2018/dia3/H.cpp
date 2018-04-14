#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 77;
const ll INF = 100000000000LL;
ll dist[N][N];
int n, m;

void init(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i != j)
      	dist[i][j] = INF;
      else
      	dist[i][j] = 0;
    }
  }
}

void floyd_warshall(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
}

int main(void){
  init();
  scanf("%d%d", &n, &m);

  int u, v;
  ll w;
  for(int i = 0; i < m; i++){
    scanf("%d%d%lld", &u, &v, &w);
    dist[u][v] = min(dist[u][v], w);
    dist[v][u] = min(dist[v][u], w);
  }

  floyd_warshall();

  // for(int i = 1; i <= n; i++){
  // 	for(int j = 1; j <= n; j++){
  // 		printf("%lld ", dist[i][j]);
  // 	}
  // 	printf("\n");
  // }

  ll BFG = INF;
  vector<ii> e;
  for(int u = 1; u <= n; u++){
    for(int v = u+1; v <= n; v++){
      // printf("u = %d, v = %d\n", u, v);
      ll newBFG = 0;
      for(int s = 1; s <= n; s++){
        for(int t = s+1; t <= n; t++){
          ll tt = min(dist[s][t], min(dist[s][u] + dist[v][t], dist[s][v] + dist[u][t]));
          // printf("s = %d, t = %d, tt = %lld\n", s, t, tt);
          newBFG = max(newBFG, tt);
          // printf("s = %d, t = %d, newBFG = %lld\n", s, t, newBFG);
        }
      }

      if(newBFG < BFG){
        e.clear();
        e.pb(ii(u,v));
        BFG = newBFG;
      }
      else if(newBFG == BFG){
        e.pb(ii(u,v));
      }

      // printf("u = %d, v = %d, newBFG = %lld\n", u, v, newBFG);
    }
  }

  // printf("BFG = %lld\n", BFG);

  if(BFG >= INF){
  	printf("-1.00000 -1.00000\n");
  	return 0;
  }

  // for(int i = 0; i < e.size(); i++){
  // 	printf("%d %d\n", e[i].fi, e[i].se);
  // }  

  ll energy = 0;
  for(ii x : e){
    int u = x.fi, v = x.se;
    // printf("u = %d, v = %d\n", u, v);

    ll l = 0, r = INF, ans = 0;
    while(l <= r){
    	ll mid = (l+r)/2;

		ll newBFG = 0;
	    for(int s = 1; s <= n; s++){
	    	for(int t = s+1; t <= n; t++){
	        	ll tt = min(dist[s][t], min(dist[s][u] + mid + dist[v][t], dist[s][v] + mid + dist[u][t]));
	        	// printf("s = %d, t = %d, tt = %lld\n", s, t, tt);
	        	newBFG = max(newBFG, tt);
	        	// printf("s = %d, t = %d, newBFG = %lld\n", s, t, newBFG);
	        }
	    }

	    if(newBFG <= BFG){
	    	ans = mid;
	    	l = mid+1;
	    }
	    else{
	    	r = mid-1;
	    }
    }
    // printf("ans = %lld\n", ans);
    energy = max(energy, ans);
  }

  if(energy < INF){
  	printf("%lld.00000 %lld.00000\n", BFG, energy);
  }
  else{
  	printf("%lld.00000 -1.00000\n", BFG);
  }

  return 0;
}