#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 302;
int t, n, m;
ll pd[N][N];
ll g[N][N], sum[N][N];

ll solve(int i, int bought){
	if(bought < i) return 10000000000000000LL;
	if(i >= n and bought < n) return 10000000000000000LL;
	if(i >= n or bought >= n) return 0LL;
	ll& dp = pd[i][bought];
	if(dp != -1LL) return dp;

	ll ret = 10000000000000000LL;
	For(j,0,m){
		if(bought + j+1 >= i+1) ret = min(ret, sum[i][j] + (j+1)*(j+1) + solve(i+1, bought+j+1));
	}
	if(bought >= i+1) ret = min(ret, solve(i+1, bought));

	return dp = ret;
}

void init(){
	For(i,0,N){
		For(j,0,N){
			pd[i][j] = -1LL;
			sum[i][j] = 0LL;
		}
	}
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d", &n, &m);
		init();

		For(i,0,n){
			For(j,0,m){
				scanf("%lld", &g[i][j]);
			}
		}

		For(i,0,n){
			sort(g[i], g[i]+m);
			sum[i][0] = g[i][0];
		}

		For(i,0,n){
			For(j,1,m){
				sum[i][j] = sum[i][j-1] + g[i][j];
			}
		}

		ll res = solve(0,0);
		
		printf("Case #%d: %lld\n", caso, res);
	}

	return 0;
}

