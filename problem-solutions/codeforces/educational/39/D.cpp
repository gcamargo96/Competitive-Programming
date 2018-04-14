#include <bits/stdc++.h>
using namespace std;
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
#define INF 0x3f3f3f3f

const int N = 502;
int n, m, k;
vi v[N];
int mn[N][N], dp[N][N];

int solve(int i, int j){
	if(i == n){
		return 0;
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int ret = INF;
	for(int k = 0; k <= min(j, int(v[i].size())); k++){ // number of skips in the i-th day
		ret = min(ret, solve(i+1, j-k) + mn[i][int(v[i].size())-k]);
	}

	return dp[i][j] = ret;
}

int main(void){
	fastcin;
	cin >> n >> m >> k;

	string s;
	memset(mn, INF, sizeof mn);
	for(int i = 0; i < n; i++){
		cin >> s;

		for(int j = 0; j < m; j++){
			if(s[j] == '1')
				v[i].pb(j);
		}

		mn[i][0] = 0;
		for(int l = 0; l < v[i].size(); l++){
			for(int r = int(v[i].size())-1; r >= l; r--){
				int k = r-l+1;
				mn[i][k] = min(mn[i][k], v[i][r]-v[i][l]+1);
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << "i = " << i << endl;
	// 	for(int j = 0; j < v[i].size(); j++){
	// 		cout << mn[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	memset(dp, -1, sizeof dp);
	int ans = solve(0, k);

	cout << ans << endl;

	return 0;
}