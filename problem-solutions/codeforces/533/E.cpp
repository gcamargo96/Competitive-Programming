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

struct event{
	int type, id;
};

const int N = 42, M = 2000005;
int adj[N][N];
vi adj_list[N];
int n, m, cnt = 0;
int dp[M], dp2[M];
map<string, int> names;
event e[M];


void precalc(){
	int mask = 0, ans = 0, nn = n/2;
	for(mask = 1; mask < (1<<nn); mask++){

		bool is_clique = 1;

		for(int u = 0; u < nn; u++){
			int bit1 = (mask>>u) & 1;
			
			for(int v = 0; v < nn; v++){
				int bit2 = (mask>>v) & 1;

				if(bit1 and bit2 and u != v and !adj[u][v]){
					is_clique = 0;
					break;
				}
			}

			if(!is_clique) break;
		}

		if(is_clique){
			dp[mask] = __builtin_popcount(mask);
			ans = max(ans, dp[mask]);

			// printf("clique found: ");
			// for(int i = n-1; i >= 0; i--){
			// 	printf("%d", (mask>>i)&1);
			// }
			// printf("\n");
		}
	}
}

void precalc2(){
	int mask = 0, ans = 0, mid = n/2, nn = n - mid;
	for(mask = 1; mask < (1<<nn); mask++){

		bool is_clique = 1;

		for(int u = 0; u < nn; u++){
			int bit1 = (mask>>u) & 1;
			
			for(int v = 0; v < nn; v++){
				int bit2 = (mask>>v) & 1;

				if(bit1 and bit2 and u != v and !adj[u+mid][v+mid]){
					is_clique = 0;
					break;
				}
			}

			if(!is_clique) break;
		}

		if(is_clique){
			dp2[mask] = __builtin_popcount(mask);
			ans = max(ans, dp2[mask]);

			// printf("clique found: ");
			// for(int i = n-1; i >= 0; i--){
			// 	printf("%d", (mask>>i)&1);
			// }
			// printf("\n");
		}
	}
}

void calc_dp(){
	int mid = n/2;
	for(int mask = 1; mask < (1<<mid); mask++){
		if(dp[mask] == 0){
			for(int i = 0; i < mid; i++){
				if((mask>>i) & 1){
					int mask2 = mask - (1<<i);
					dp[mask] = max(dp[mask], dp[mask2]);

					// printf("dp[");
					// for(int i = n-1; i >= 0; i--){
					// 	printf("%d", (mask>>i)&1);
					// }
					// printf("] = max ");
					// printf("dp[");
					// for(int i = n-1; i >= 0; i--){
					// 	printf("%d", (mask>>i)&1);
					// }
					// printf("], dp[");
					// for(int i = n-1; i >= 0; i--){
					// 	printf("%d", (mask2>>i)&1);
					// }
					// printf("]\n");
				}
			}
		}
	}

	for(int mask = 1; mask < (1<<(n-mid)); mask++){
		if(dp2[mask] == 0){
			for(int i = 0; i < (n-mid); i++){
				if((mask>>i) & 1){
					int mask2 = mask - (1<<i);
					dp2[mask] = max(dp2[mask], dp2[mask2]);
				}
			}
		}
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
			friends |= (1<<(u-mid));
		}
	}

	return friends;
}

int main(void){
	// scanf("%d%d", &m, &n);
	fastcin;
	cin >> m >> n;

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
		printf("1\n");
		return 0;
	}

	for(int i = 1; i < m; i++){
		set<int> s;
		
		while(i < m and e[i].type == 2){
			s.insert(e[i].id);
			i++;
		}

		// creating clique
		for(int u : s){
			for(int v : s){
				if(u != v){
					adj[u][v] = 1;
					adj[v][u] = 1;
				}
			}
		}
	}

	// inverting graph
	for(int u = 0; u < n; u++){
		for(int v = 0; v < n; v++){
			if(u == v) continue;
			adj[u][v] = !adj[u][v];

			if(adj[u][v]){
				adj_list[u].pb(v);
			}
		}
	}

	int mid = n/2;
	precalc();
	precalc2();
	calc_dp();

	// for(int mask = 1; mask < (1<<n); mask++){
	// 	printf("dp[");
	// 	for(int i = n-1; i >= 0; i--){
	// 		printf("%d", (mask>>i)&1);
	// 	}
	// 	printf("] = %d\n", dp[mask]);
	// }

	int ans = 0;
	for(int mask = 1; mask < (1<<mid); mask++){
		int friends = get_friends(mask);
		
		// for(int i = n-1; i >= 0; i--){
		// 	printf("%d", (mask>>i)&1);
		// }
		// printf(" ");
		// for(int i = n-1; i >= 0; i--){
		// 	printf("%d", (friends>>i)&1);
		// }
		// printf("\n");
		// printf("%d %d\n", dp[mask], dp[friends]);

		ans = max(ans, dp[mask] + dp2[friends]);
	}

	cout << ans << endl;

	return 0;
}