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

const int N = 100002;
int n, c;
int v[N], p[N];
ll dp[N];

ll solve(int i){
	if(i >= n)
		return 0;

	if(dp[i] != -1)
		return dp[i];

	ll a = solve(i+1);
	ll b = solve(i+c) + p[i];

	return dp[i] = max(a, b);
}

int main(void){
	scanf("%d%d", &n, &c);

	ll sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		sum += v[i];
	}

	multiset<int> s;
	for(int i = 0; i < c; i++){
		s.insert(v[i]);
	}
	p[0] = *(s.begin());

	for(int i = 1; i < n-c+1; i++){
		s.erase(s.find(v[i-1]));
		s.insert(v[i+c-1]);
		p[i] = *(s.begin());
	}

	memset(dp, -1, sizeof dp);
	ll ans = sum - solve(0);
	printf("%lld\n", ans);

	return 0;
}