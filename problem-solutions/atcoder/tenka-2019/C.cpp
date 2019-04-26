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

#define INF 0x3f3f3f3f

const int N = 200005;
int n;
string s;
int dp[N][3];

int solve(int i, int flag){
	if(i == n) return 0;
	if(dp[i][flag] != -1) return dp[i][flag];

	int ret = INF;
	if(s[i] == '#'){
		if(flag == 1)
			ret = solve(i+1, 1);
		else
			ret = min(solve(i+1, 1), solve(i+1, 0) + 1);
	}
	else{ // s[i] == '.'
		if(flag == 1)
			ret = solve(i+1, 1) + 1;
		else{
			ret = min(solve(i+1, 0), solve(i+1, 1) + 1);
		}
	}

	return dp[i][flag] = ret;
}

int main(void){
	fastcin;
	cin >> n;
	cin >> s;

	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0);

	cout << ans << endl;

	return 0;
}