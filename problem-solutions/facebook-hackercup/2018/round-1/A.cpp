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

#define M 1000000007
#define U 0
#define D 1
#define L 2
#define R 3

const int N = 1002;
int t, n;
ll dp[5][N][5];
char g[5][N];

ll add(ll a, ll b){
	return (a+b)%M;
}

ll mul(ll a, ll b){
	return (a*b)%M;
}

ll solve(int i, int j, int from){
	if(i == 2 and j == n) return 1;
	if(i < 0 or i >= 3 or j < 0 or j >= n or g[i][j] == '#') return 0;
	if(dp[i][j][from] != -1) return dp[i][j][from];

	ll ret = 0;
	
	if(from == U or from == D){
		ret = add(ret, solve(i, j+1, L));
	}
	if(from == L){
		ret = add(ret, solve(i+1, j, D));
		ret = add(ret, solve(i-1, j, U));
	}

	return dp[i][j][from] = ret;
}

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> n;
	
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < n; j++){
				cin >> g[i][j];
			}
		}

		memset(dp, -1, sizeof dp);
		ll ans = solve(0,0,L);
		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}