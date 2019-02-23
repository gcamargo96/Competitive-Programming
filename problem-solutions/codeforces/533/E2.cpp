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

struct event{
	int type, id;
};

const int N = 42, M = 2000005;
int adj[N][N], adj11[M], adj12[M], adj21[M], adj22[M];
int n, m, mid, cnt = 0;
int dp[M], dp2[M];
map<string, int> names;
event e[M];

bool can_add_to_clique(int mask, int v){
	// printf("tentando adicionar ");
	// for(int i = n-1; i >= 0; i--){
	// 	printf("%d", ((1<<v)>>i)&1);
	// }
	// printf(" a ");
	// for(int i = n-1; i >= 0; i--){
	// 	printf("%d", (mask>>i)&1);
	// }
	// printf("\n");
	// for(int i = n-1; i >= 0; i--){
	// 	printf("%d", (adj11[1<<v]>>i)&1);
	// }
	// printf("\n");

	return (((mask>>v) & 1) == 0 and (mask & adj11[1<<v]) == mask);
}

bool can_add_to_clique2(int mask, int v){
	return (((mask>>v) & 1) == 0 and (mask & adj22[1<<v]) == mask);
}

void add_adj(int mask, int v){
	int new_mask = mask | (1<<v);
	adj12[new_mask] = adj12[mask] & adj12[1<<v];
}

void dfs(int mask){
	if(dp[mask]) return;
	dp[mask] = __builtin_popcount(mask);

	for(int v = 0; v < mid; v++){
		if(can_add_to_clique(mask, v)){
			int new_mask = mask | (1<<v);
			add_adj(mask, v);
			dfs(new_mask);
		}
	}
}

void dfs2(int mask){
	if(dp2[mask]) return;
	dp2[mask] = __builtin_popcount(mask);

	for(int v = 0; v < n-mid; v++){
		if(can_add_to_clique2(mask, v)){
			int new_mask = mask | (1<<v);
			dfs2(new_mask);
		}
	}
}

void calc_dp(){
	for(int mask = 1; mask < (1<<mid); mask++){
		if(dp[mask]) continue;

		for(int i = 0; i < mid; i++){
			if((mask>>i)&1){
				dp[mask] = max(dp[mask], dp[mask^(1<<i)]);
			}
		}
	}

	for(int mask = 1; mask < (1<<(n-mid)); mask++){
		if(dp2[mask]) continue;

		for(int i = 0; i < n-mid; i++){
			if((mask>>i)&1){
				dp2[mask] = max(dp2[mask], dp2[mask^(1<<i)]);
			}
		}
	}
}

int merge(){
	int ans = 0;

	for(int mask = 1; mask < (1<<mid); mask++){
		ans = max(ans, dp[mask] + dp2[adj12[mask]]);
	}

	for(int mask = 1; mask < (1<<(n-mid)); mask++){
		ans = max(ans, dp2[mask]);
	}
	
	return ans;
}

int main(void){
	fastcin;
	cin >> m >> n;
	mid = n/2;

	string name;
	for(int i = 0; i < m; i++){
		cin >> e[i].type;
		
		if(e[i].type == 2){
			cin >> name;
			if(!names.count(name)){
				names[name] = cnt++;
			}
			e[i].id = names[name];
		}
	}

	if(n == 1){
		// printf("1\n");
		cout << 1 << endl;
		return 0;
	}

	// processing input
	for(int i = 1; i < m; i++){
		set<int> s;
		
		while(i < m and e[i].type == 2){
			s.insert(e[i].id);
			i++;
		}

		// creating clique
		for(int u : s){
			for(int v : s){
				if(u == v) continue;

				adj[u][v] = 1;
				adj[v][u] = 1;
				// if(u != v){
				// 	if(u < mid and v < mid){
				// 		adj11[1<<u] |= (1<<v);
				// 	}
				// 	else if(u < mid and v >= mid){
				// 		adj12[1<<u] |= (1<<v);
				// 	}
				// 	else if(u >= mid and v < mid){
				// 		adj21[1<<u] |= (1<<v);
				// 	}
				// 	else{ // u >= mid and v >= mid
				// 		adj22[1<<u] |= (1<<v);
				// 	}
				// }
			}
		}
	}

	for(int u = 0; u < n; u++){
		for(int v = 0; v < n; v++){
			if(u != v and !adj[u][v]){
				if(u < mid and v < mid){
					adj11[1<<u] |= (1<<v);
				}
				else if(u < mid and v >= mid){
					int vv = v-mid;
					adj12[1<<u] |= (1<<vv);
				}
				else if(u >= mid and v < mid){
					int uu = u-mid;
					adj21[1<<uu] |= (1<<v);
				}
				else{ // u >= mid and v >= mid
					int uu = u-mid, vv =v-mid;
					adj22[1<<uu] |= (1<<vv);
				}
			}
		}
	}

	// for(int mask = 0; mask < (1<<mid); mask++){
	// 	printf("adj11[");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (mask>>i)&1);
	// 	}
	// 	printf("] = ");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (adj11[mask]>>i)&1);
	// 	}
	// 	printf("\n");
	// }

	// dp initial state
	for(int u = 0; u < mid; u++){
		int mask = (1<<u);
		dfs(mask);
	}
	for(int u = 0; u < n-mid; u++){
		int mask = (1<<u);
		dfs2(mask);
	}

	// for(int mask = 1; mask < (1<<n); mask++){
	// 	printf("adj11[");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (mask>>i)&1);
	// 	}
	// 	printf("] = ");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (adj11[mask]>>i)&1);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	// for(int mask = 1; mask < (1<<n); mask++){
	// 	printf("adj22[");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (mask>>i)&1);
	// 	}
	// 	printf("] = ");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (adj22[mask]>>i)&1);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	// for(int mask = 0; mask < (1<<n); mask++){
	// 	printf("dp[");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (mask>>i)&1);
	// 	}
	// 	printf("] = %d\n", dp[mask]);
	// }
	// printf("\n");

	// for(int mask = 1; mask < (1<<n); mask++){
	// 	printf("dp2[");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (mask>>i)&1);
	// 	}
	// 	printf("] = %d\n", dp2[mask]);
	// }
	// printf("\n");

	// for(int mask = 1; mask < (1<<n); mask++){
	// 	printf("adj12[");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (mask>>i)&1);
	// 	}
	// 	printf("] = ");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (adj12[mask]>>i)&1);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	calc_dp();
	int ans = merge();
	cout << ans << endl;

	return 0;
}