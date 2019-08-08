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

const int N = 1000005;
ll dp[N][5];
string s;
int n;

ll solve(int i, int e){
	if(i >= n) return 0;
	if(dp[i][e] != -1) return dp[i][e];

	ll ret = solve(i+1, e);
	if(e == 1){
		if(i <= n-2 and s[i] == 'v' and s[i+1] == 'v'){
			ret += solve(i+2, 2);
		}
	}
	if(e == 2){
		if(s[i] == 'o'){
			ret += solve(i+1, 3);
		}
	}
	if(e == 3){
		if(i <= n-2 and s[i] == 'v' and s[i+1] == 'v'){
			ret++;
		}
	}

	return dp[i][e] = ret;
}

int main(void){
	fastcin;
	cin >> s;
	n = s.size();

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, 1);
	cout << ans << endl;

	return 0;
}