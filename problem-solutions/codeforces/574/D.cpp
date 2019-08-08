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

const int N = 100005;
const ll MOD = 998244353;
int n;
string s[N];
int cnt[12];

ll add(ll a, ll b){
	return (a+b)%MOD;
}

ll mul(ll a, ll b){
	return (a*b)%MOD;
}

int main(void){
	fastcin;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
		cnt[s[i].size()]++;
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		for(int d = 1; d <= 10; d++){

			ll b = 1;
			ll sum = 0;
			for(int j = 0; j < s[i].size(); j++){
				sum = add(sum, mul(b, s[i][j]-'0'));
				if(j <= d-1) b = mul(b, 100);
				else b = mul(b, 10);
			}

			b = 10;
			for(int j = 0; j < s[i].size(); j++){
				sum = add(sum, mul(b, s[i][j]-'0'));
				if(j < d-1) b = mul(b, 100);
				else b = mul(b, 10);

			}

			// cout << "d = " << d << " sum = " << sum << endl;

			sum = mul(sum, cnt[d]);
			ans = add(ans, sum);
		}
	}

	cout << ans << endl;

	return 0;
}