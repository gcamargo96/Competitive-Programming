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

const int N = 102;
int t;
int n, m, k;
int a, b;
int s, d;
ll cost[N][N];
ii family[5002];
ll pd[5002][N][3];
ll g;

void init(){
	//memset(cost, INF, sizeof cost);
	For(i,0,N){
		For(j,0,N){
			cost[i][j] = INF;
		}
	}
	For(i,0,N){
		cost[i][i] = 0LL;
	}

	For(i,0,5002){
		For(j,0,N){
			For(k,0,3){
				pd[i][j][k] = -1;
			}
		}
	}
}

void floyd_warshall(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(cost[i][j]>cost[i][k]+cost[k][j])
                    cost[i][j]=cost[i][k]+cost[k][j];
}

ll solve(int i, int j, int c){
	if(i == k and c == 1) return cost[j][family[i-1].se];
	if(i == k and c == 2){
		return cost[j][family[i-2].se] + cost[family[i-2].se][family[i-1].se];
	}
	ll& dp = pd[i][j][c];
	if(dp != -1) return dp;
	
	ll ret = INF;
	if(c > 0){
		ret = min(ret, cost[j][family[i-c].se] + solve(i, family[i-c].se, c-1));	
	}
	if(c < 2){
		ret = min(ret, cost[j][family[i].fi] + solve(i+1, family[i].fi, c+1));
	}

	return dp = ret;
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d%d%d", &n, &m, &k);

		For(i,0,m){
			scanf("%d%d%lld", &a, &b, &g);
			cost[a][b] = min(cost[a][b], g);
			cost[b][a] = min(cost[b][a], g);
		}

		For(i,0,k){
			scanf("%d%d", &family[i].fi, &family[i].se);
		}

		floyd_warshall();

		ll res = solve(0, 1, 0);

		if(res < INF) printf("Case #%d: %lld\n", caso, res);
		else printf("Case #%d: -1\n", caso);
	}
	
	return 0;
}

