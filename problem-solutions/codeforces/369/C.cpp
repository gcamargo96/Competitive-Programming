#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 102;
int n, m, k;
int v[N];
int cost[N][N];
bool ok = 0;
ll dp[N][N][N];

ll solve(int id, int cnt, int ant){
	if(id == n){
		if(cnt == k){
			ok = 1;	
			return 0;
		}
		return 1000000002;
	}


	ll& DP = dp[id][cnt][ant];
	//if(DP != -1) return DP;

	if(v[id] != 0){
		if(v[id] == ant and id > 0) return solve(id+1, cnt, v[id]);
		else return solve(id+1, cnt+1, v[id]);
	}

	ll ret = 1000000000000000000LL;
	For(i,0,m){
		if(i == ant) ret = min(ret, solve(id+1, cnt, v[id]) + cost[id][i]);
		else ret = min(ret, solve(id+1, cnt+1, v[id]) + cost[id][i]);
	}

	return DP = ret;
}

int main(void){
	memset(dp, -1, sizeof dp);
	scanf("%d%d%d", &n, &m, &k);

	For(i,0,n){
		scanf("%d", &v[i]);
	}

	For(i,0,n){
		For(j,0,m){
			scanf("%d", &cost[i][j]);
		}
	}

	ll res = solve(0, 0, -1);

	if(ok) printf("%lld\n", res);
	else printf("-1\n");

	return 0;
}
