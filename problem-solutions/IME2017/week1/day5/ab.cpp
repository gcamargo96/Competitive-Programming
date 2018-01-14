#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define M 1000000009

const int N = 1002;
string s;
ll dp[N][2*N];

ll solve(int i, int dif){
	if(i == s.size()) return (dif == 1000); // ababa
	if(dp[i][dif] != -1) return dp[i][dif];
	
	ll ans = (dif == 1000);

	ans = (ans + solve(i+1, dif))%M;
	if(s[i] == 'a'){
		ans = (ans + solve(i+1, dif+1))%M;
	}
	else{
		ans = (ans + solve(i+1, dif-1))%M;
	}

	return dp[i][dif] = ans;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;

	memset(dp, -1, sizeof dp);
	ll ans = solve(0,1000);

	cout << ans << endl;

	return 0;
}