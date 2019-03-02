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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

const int N = 5005, M = 20005;
int n, m, cur;
vi adj[N];
int d[N][N];

bool cmp(int a, int b){
	return d[cur][a] < d[cur][b];
}

void precalc(){
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			d[i][j] = j-i;
			d[j][i] = n-j + i;
		}
	}

	for(int i = 1; i <= n; i++){
		cur = i;
		sort(adj[i].begin(), adj[i].end(), cmp);
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		adj[a].pb(b);
	}

	precalc();

	for(int s = 1; s <= n; s++){
		
		int ans = 0;
		for(int u = 1; u <= n; u++){
			if(adj[u].size() == 0) continue;

			// printf("s = %d, u = %d, ans = %d\n", s, u, d[s][u] + int(adj[u].size()-1)*n + d[u][adj[u][0]]);
			// printf("d[%d][%d] = %d\n", u, adj[u][0], d[u][adj[u][0]]);

			ans = max(ans, d[s][u] + int(adj[u].size()-1)*n + d[u][adj[u][0]]);
		}

		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}