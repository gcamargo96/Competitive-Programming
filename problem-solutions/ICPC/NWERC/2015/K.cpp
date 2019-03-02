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

#define INF 1000000000000000000LL

const int N = 1005;
int r, s, m, d, n;
int b[N];
vi starter[30], maindish[30], dessert[30];
int incomp[90][90];

ull mult(ull a, ull b){
	if(a == 0) return 0;
	ll x = a*b;
	if((a*b)/a != b or (a*b)/b != a or a*b > INF){
		printf("too many\n");
		exit(0);
	}
	return a*b;
}

int main(void){
	scanf("%d%d%d%d%d", &r, &s, &m, &d, &n);

	for(int i = 0; i < r; i++){
		scanf("%d", &b[i]);
	}

	int k, x;
	for(int i = 0; i < s; i++){
		scanf("%d", &k);
		
		for(int j = 0; j < k; j++){
			scanf("%d", &x);
			starter[i].pb(x);
		}
	}

	for(int i = 0; i < m; i++){
		scanf("%d", &k);
		
		for(int j = 0; j < k; j++){
			scanf("%d", &x);
			maindish[i].pb(x);
		}
	}

	for(int i = 0; i < d; i++){
		scanf("%d", &k);
		
		for(int j = 0; j < k; j++){
			scanf("%d", &x);
			dessert[i].pb(x);
		}
	}

	int y;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &x, &y);
		x--, y--;
		
		incomp[x][y] = 1;
		incomp[y][x] = 1;
	}

	ll ans = 0;
	for(int i = 0; i < s; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < d; k++){
				if(incomp[i][s+j] or incomp[i][s+m+k] or incomp[s+j][s+m+k]){
					// printf("incomp %d %d %d\n", i, s+j, s+m+k);
					continue;
				}

				set<int> used;

				for(int l = 0; l < starter[i].size(); l++)
					used.insert(starter[i][l]);

				for(int l = 0; l < maindish[j].size(); l++)
					used.insert(maindish[j][l]);

				for(int l = 0; l < dessert[k].size(); l++)
					used.insert(dessert[k][l]);

				ll mul = 1;
				// printf("%d %d %d:\n", i, s+j, s+m+k);
				for(int x : used){
					// printf("mul %d, %d\n", x, b[x-1]);
					mul = mult(mul, b[x-1]); //mul *= b[x-1];
				}
				// printf("\n");

				ans += mul;
				if(ans > INF){
					printf("too many\n");
					exit(0);
				}
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}