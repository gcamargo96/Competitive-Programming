#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 505;
int dp[N][N];
string s;
int n;

int solve(int i, int j){
	if(i == j) return 1;
	if(i > j) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	int ret = solve(i+1, j) + 1;
	for(int k = i+1; k <= j; k++){
		if(s[i] == s[k]){
			ret = min(ret, solve(i, k-1) + solve(k+1, j));
		}
	}

	return dp[i][j] = ret;
}

int main(void){
	fastcin;
	cin >> n >> s;

	memset(dp, -1, sizeof dp);
	int ans = solve(0, n-1);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << ans << endl;

	return 0;
}