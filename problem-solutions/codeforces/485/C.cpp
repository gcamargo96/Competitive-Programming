#include <bits/stdc++.h>
using namespace std;
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

const int INF = 1000000000;
const int N = 3002;
int s[N], c[N];
int dp[N][N][4];
int n;

int solve(int i, int last, int cnt){
	if(i > n){
		if(cnt == 3)
			return 0;
		return INF;
	}
	int& DP = dp[i][last][cnt];
	if(DP != -1)
		return DP;

	int ret = solve(i+1, last, cnt);
	if(cnt < 3 and s[i] > s[last]){
		ret = min(ret, solve(i+1, i, cnt+1) + c[i]);
	}

	return DP = ret;
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}

	memset(dp, -1, sizeof dp);
	int ans = solve(1, 0, 0);

	if(ans < INF)
		printf("%d\n", ans);
	else
		printf("-1\n");

	return 0;
}