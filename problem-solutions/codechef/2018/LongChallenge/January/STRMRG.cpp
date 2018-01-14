#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

#define A 0
#define B 1

const int N = 5002;
int t, n, m;
string a, b;
int dp[N][N][2], op[N][N][2];

int solve(int i, int j, int last){
	if(i > n or j > m)
		return  500000000;

	if(i == n and j == m)
		return 1;

	if(dp[i][j][last] != -1)
		return dp[i][j][last];

	int retA = 1000000002, retB = 1000000002;
	if(i < n){
		retA = solve(i+1, j, A);
		if(last == A)
			retA += (a[i-1] != a[i]);
		else
			retA += (b[j-1] != a[i]);
	}

	if(j < m){
		retB = solve(i, j+1, B);
		if(last == A)
			retB += (a[i-1] != b[j]);
		else
			retB += (b[j-1] != b[j]);
	}

	if(retA <= retB)
		op[i][j][last] = A;
	else
		op[i][j][last] = B;

	return dp[i][j][last] = min(retA, retB);
}

string path;

void get_path(int i, int j, int last){
	if(i > n or j > m)
		return;

	if(i == n and j == m)
		return;

	if(op[i][j][last] == A){
		path += a[i];
		get_path(i+1, j, A);
	}
	else{
		path += b[j];
		get_path(i, j+1, B);
	}
}

int main(void){
	fastcin;
	cin >> t;

	while(t--){
		cin >> n >> m >> a >> b;
		a += '#';
		b += '#';

		memset(dp, -1, sizeof dp);
		int ans = solve(1, 0, A);
		ans = min(ans, solve(0, 1, B));

		// path += a[0];
		// get_path(1, 0, A);
		// cout << path << endl;

		// path.clear();
		// path += b[0];
		// get_path(0, 1, B);
		// cout << path << endl;

		cout << ans << endl;
	}

	return 0;
}