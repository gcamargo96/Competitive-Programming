#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 102;
int g[2][N];
ll dp[N][2][2][2][2];
string s;
int n;

ll solve(int i, int a, int b, int c, int d){
	if(i == n-1){
		return 0;
	}

	ll& DP = dp[i][a][b][c][d];
	if(DP != -1) return DP;

	ll ret = solve(i+1, g[0][i+1], g[0][i+2], g[1][i+1], g[1][i+2]);

	if(a == 0 and b == 0 and c == 0){
		ret = max(ret, solve(i+1, 1, g[0][i+2], g[1][i+1], g[1][i+2]) + 1);
	}
	if(a == 0 and b == 0 and d == 0){
		ret = max(ret, solve(i+1, 1, g[0][i+2], 1, g[1][i+2]) + 1);
	}
	if(b == 0 and c == 0 and d == 0){
		ret = max(ret, solve(i+1, 1, g[0][i+2], 1, g[1][i+2]) + 1);
	}
	if(a == 0 and c == 0 and d == 0){
		ret = max(ret, solve(i+1, g[0][i+1], g[0][i+2], 1, g[1][i+2]) + 1);
	}

	return DP = ret;
}

int main(void){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'X') g[0][i] = 1;
		else g[0][i] = 0;
	}

	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'X') g[1][i] = 1;
		else g[1][i] = 0;
	}

	n = s.size();

	if(n < 2){
		cout << 0 << endl;
		return 0;
	}

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, g[0][0], g[0][1], g[1][0], g[1][1]);

	cout << ans << endl;

	return 0;
}