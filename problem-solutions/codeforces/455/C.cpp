#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000000LL
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define NORMALBLOCK 0
#define NEWBLOCK 1
#define MOD 1000000007

const int N = 5002;
int n;
vector<char> v;
ll dp[N][N];

ll solve(int i, int lv){
	// cout << "i = " << i << " lv = " << lv << endl;
	if(i == n){
		return 1;
	}

	if(dp[i][lv] != -1){
		return dp[i][lv];
	}

	ll ret = 0;
	if(lv > 0 and v[i-1] == 's'){
		ret = solve(i, lv-1);
	}
	if(v[i] == 's'){
		ret += solve(i+1, lv);
	}
	if(v[i] == 'f'){
		ret += solve(i+1, lv+1);
	}

	return dp[i][lv] = ret%MOD;
}

int main(void){
	fastcin;
	cin >> n;

	char c;
	for(int i = 0; i < n; i++){
		cin >> c;
		v.pb(c);
	}

	memset(dp, -1ll, sizeof dp);
	ll ans = solve(0,0);

	cout << ans << endl;

	return 0;
}