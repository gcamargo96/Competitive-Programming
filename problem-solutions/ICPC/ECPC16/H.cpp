#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 12;
int t, n;
int g[N][N][N], dp[N][N][N];

int solve(int f, int y, int x){
	if(f == 0)
		return 0;

	int& DP = dp[f][y][x];
	if(DP != -1)
		return DP;

	int ret = solve(f-1, y, x);
	if(x < 10)
		ret = max(ret, solve(f, y, x+1));
	if(y < 10)
		ret = max(ret, solve(f, y+1, x));

	int H = g[f][y][x];
	return DP = ret + H;
}

int main(void){
	freopen("commandos.in", "r", stdin);
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		int h, f, y, x;
		memset(g, 0, sizeof g);
		for(int i = 0; i < n; i++){
			scanf("%d%d%d%d", &f, &y, &x, &h);
			g[f][y][x] = h;
		}

		memset(dp, -1, sizeof dp);
		int ans = solve(10, 1, 1);
		
		printf("%d\n", ans);
	}

	return 0;
}