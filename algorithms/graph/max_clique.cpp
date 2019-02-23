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

const int N = 42;
int adj[N][N];
vi adj_list[N];
int n, m;
int dp[N];

void precalc(int n, int shift){
	int mask = 0, ans = 0;
	for(mask = 0; mask < (1<<n); mask++){

		// for(int i = n-1; i >= 0; i--){
		// 	printf("%d", (mask>>i)&1);
		// }
		// printf("\n");

		bool is_clique = 1;
		int MASK = (mask<<shift);

		for(int u = 0; u < n; u++){
			int bit1 = (MASK>>u) & 1;
			
			for(int v = 0; v < n; v++){
				int bit2 = (MASK>>v) & 1;

				if(bit1 and bit2 and u!= v and !adj[u][v]){
					is_clique = 0;
					break;
				}
			}

			if(!is_clique) break;
		}

		if(is_clique){
			dp[MASK] = __builtin_popcount(MASK);
			ans = max(ans, dp[MASK]);
		}
	}

	for(mask = 0; mask < (1<<n); mask++){

		int MASK = (mask<<shift);
		if(dp[MASK] == 0){
			for(int i = 0; i < n; i++){
				if((MASK>>i) & 1){
					int MASK2 = MASK - (1<<i);
					dp[MASK] = max(dp[MASK], dp[MASK2]);
				}
			}
		}

		// printf("dp[");
		// for(int i = n-1; i >= 0; i--){
		// 	printf("%d", (mask>>i)&1);
		// }
		// printf("] = %d\n", dp[MASK]);
	}
}

int get_friends(int mask){
	int friends = 0, mid = n/2;
	int cnt[N];
	memset(cnt, 0, sizeof cnt);

	for(int u = 0; u < n; u++){
		if((mask>>u) & 1){
			for(int v : adj_list[u]){
				if(v >= mid){
					cnt[v]++;
				}
			}
		}
	}

	for(int u = mid; u < n; u++){
		if(cnt[u] == __builtin_popcount(mask)){
			friends |= (1<<u);
		}
	}

	return friends;
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		adj[u][v] = 1;
		adj[v][u] = 1;

		adj_list[u].pb(v);
		adj_list[v].pb(u);
	}

	int mid = n/2;
	precalc(mid, 0);
	precalc(n - mid, mid);

	int ans = 0;
	for(int mask = 0; mask < (1<<mid); mask++){
		int friends = get_friends(mask);
		for(int i = n-1; i >= 0; i--){
			printf("%d", (mask>>i)&1);
		}
		printf(" ");
		for(int i = n-1; i >= 0; i--){
			printf("%d", (friends>>i)&1);
		}
		printf("\n");
		printf("%d %d\n", dp[mask], dp[friends]);

		ans = max(ans, dp[mask] + dp[friends]);
	}

	printf("%d\n", ans);

	return 0;
}

void old(){
		// int mask = 0, ans = 0;
	// for(mask = 0; mask < (1<<n); mask++){
		
	// 	bool is_clique = 1;
	// 	for(int u = 0; u < n; u++){
	// 		int bit1 = (mask>>u) & 1;
			
	// 		for(int v = 0; v < n; v++){
	// 			int bit2 = (mask>>v) & 1;

	// 			if(bit1 and bit2 and u!= v and !adj[u][v]){
	// 				is_clique = 0;
	// 				break;
	// 			}
	// 		}

	// 		if(!is_clique) break;
	// 	}

	// 	if(is_clique){
	// 		dp[mask] = __builtin_popcount(mask);
	// 		ans = max(ans, dp[mask]);

	// 		// printf("dp[%d] = %d\n", mask, dp[mask]);

	// 		// printf("clique: ");
	// 		// for(int i = n-1; i >= 0; i--){
	// 		// 	printf("%d", (mask>>i)&1);
	// 		// }
	// 		// printf("\n");
	// 	}
	// }

	// for(mask = 0; mask < (1<<n); mask++){

	// 	if(dp[mask] == 0){
	// 		for(int i = 0; i < n; i++){
	// 			if((mask>>i) & 1){
	// 				int mask2 = mask - (1<<i);
	// 				dp[mask] = max(dp[mask], dp[mask2]);
	// 			}
	// 		}
	// 	}

	// 	// printf("dp[");
	// 	// for(int i = n-1; i >= 0; i--){
	// 	// 	printf("%d", (mask>>i)&1);
	// 	// }
	// 	// printf("] = %d\n", dp[mask]);
	// }
}