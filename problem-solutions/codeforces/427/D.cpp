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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 5002;
string s;
int dp[N][N], cnt[N];
int n;

int main(void){
	cin >> s;
	n = s.size();

	for(int i = 0; i < n; i++){
		dp[i][i] = 1;
	}
	cnt[1] = n;

	for(int i = 0; i < n-1; i++){
		if(s[i] == s[i+1]){
			dp[i][i+1] = 2;
			cnt[2]++;
		}
	}

	for(int i = 3; i <= n; i++){
		for(int l = 0; l <= n-i; l++){
			int r = l+i-1;
			int m = (r-l+1)/2;

			if(s[l] == s[r] and dp[l+1][r-1] > 0){
				dp[l][r] = dp[l][l+m-1]+1;
				// printf("dp[%d][%d] = %d\n", l, r, dp[l][r]);
			}

			cnt[dp[l][r]]++;
		}
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			cnt[i] += cnt[j];
		}
	}

	for(int i = 1; i <= n; i++){
		cout << cnt[i] << " ";
	}
	cout << endl;

	return 0;
}