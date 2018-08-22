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
#define MIN 0
#define MAX 1

const int N = 102;
int p, q;
int g[N][N], acc[N][N], dp[N][N][2];

int solve(int x, int y, int turn){
	if(x == 0 or y == q+1){
		return 0;
	}

	if(dp[x][y][turn] != -1){
		return dp[x][y][turn];
	}

	int ret;
	if(turn == MAX){
		ret = -INF;
		for(int i = y; i <= min(q, y+1); i++){
			ret = max(ret, solve(x, i+1, MIN) + acc[x][y]-acc[x][i+1]);
		}
	}
	else{
		ret = INF;
		for(int i = x; i >= max(1, x-1); i--){
			ret = min(ret, solve(i-1, y, MAX) - (acc[x][y]-acc[i-1][y]));
		}
	}

	return dp[x][y][turn] = ret;
}

int main(void){
	scanf("%d%d", &p, &q);

	for(int i = 1; i <= p; i++){
		int cur = i%2;
		for(int j = 1; j <= q; j++){
			if(cur == 0) g[i][j] = -1;
			else g[i][j] = 1;
			cur = !cur;
		}
	}

	for(int i = 1; i <= p; i++){
		for(int j = q; j >= 1; j--){
			acc[i][j] = g[i][j] + acc[i-1][j] + acc[i][j+1] - acc[i-1][j+1];
		}
	}

	memset(dp, -1, sizeof dp);
	int ans = solve(p, 1, MAX);
	printf("%d\n", ans);

	return 0;
}