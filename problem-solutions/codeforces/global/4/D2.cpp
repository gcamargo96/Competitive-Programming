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

const int N = 1000005;
int vis[N];
vi p;
int adj[1005][1005];
int deg[1005];
int n;

void sieve(){
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			p.pb(i);
			
			for(int j = i+i; j < N; j += i){
				vis[j] = 1;
			}
		}
	}
}

int main(void){
	sieve();
	scanf("%d", &n);

	adj[1][n] = 1;
	adj[n][1] = 1;

	for(int u = 1; u < n; u++){
		adj[u][u+1] = 1;
		adj[u+1][u] = 1;
	}

	for(int u = 1; u <= n; u++){
		deg[u] = 2;
	}

	int e = n;

	for(int u = 1; u <= n; u++){
		if(vis[e] == 0) break;
		for(int v = u+1; v <= n; v++){
			if(vis[e] == 0) break;

			if(deg[u] == 2 and deg[v] == 2 and adj[u][v] == 0 and adj[v][u] == 0){
				deg[u]++;
				deg[v]++;
				adj[u][v] = 1;
				adj[v][u] = 1;
				e++;
			}
		}
	}

	printf("%d\n", e);

	for(int u = 1; u <= n; u++){
		for(int v = u+1; v <= n; v++){
			if(adj[u][v] == 1){
				printf("%d %d\n", u, v);
			}
		}
	}

	return 0;
}