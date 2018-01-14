#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INV 1

const int N = 100002;
int n;
int c[N];
string s[N], s2[N];
int ok = 0;
ll dp[N][2];

ll solve(int i, int inv){
	if(i == n-1){
		ok = 1;
		return 0;
	}
	if(dp[i][inv] != -1) return dp[i][inv];
	
	ll ret = 1000000000000000002;
	if(inv == !INV){
		if(s[i] <= s[i+1]) ret = min(ret, solve(i+1, !INV));
		if(s[i] <= s2[i+1]) ret = min(ret, solve(i+1, INV) + c[i+1]);
	}
	else{
		if(s2[i] <= s[i+1]) ret = min(ret, solve(i+1, !INV));
		if(s2[i] <= s2[i+1]) ret = min(ret, solve(i+1, INV) + c[i+1]);
	}

	return dp[i][inv] = ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
	cin >> n;
	
	For(i,0,n){
		cin >> c[i];
	}

	For(i,0,n){
		cin >> s[i];
		s2[i] = s[i];
		reverse(s2[i].begin(), s2[i].end());
	}

	memset(dp, -1, sizeof dp);
	ll res = min(solve(0,!INV), solve(0,INV)+c[0]);

	//cout << "res = " << res << endl;
	if(ok) cout << res << endl;
	else cout << "-1" << endl;

	return 0;
}
