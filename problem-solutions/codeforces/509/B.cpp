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

ll a, b, x, y;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void){
	fastcin;
	cin >> a >> b >> x >> y;

	ll g = gcd(x, y);
	ll xi = x/g;
	ll yi = y/g;

	if(xi > a or yi > b){
		cout << 0 << endl;
		return 0;
	}

	ll ans = 1;
	ans += min((a-xi)/xi, (b-yi)/yi);

	cout << ans << endl;

	return 0;
}