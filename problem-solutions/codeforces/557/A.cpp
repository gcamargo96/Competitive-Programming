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

#define INF 0x3f3f3f3f

const int N = 55;
ll n, h, m;
ll house[N];

void set_max(int l, int r, ll x){
	for(int i = l; i <= r; i++){
		house[i] = min(house[i], x);
	}
}

int main(void){
	cin >> n >> h >> m;

	memset(house, INF, sizeof house);

	set_max(1, n, h);

	int l, r;
	ll x;
	for(int i = 0; i < m; i++){
		cin >> l >> r >> x;

		set_max(l, r, x);
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		// cout << house[i] << " ";
		ans += house[i]*house[i];
	}
	// cout << endl;

	cout << ans << endl;

	return 0;
}