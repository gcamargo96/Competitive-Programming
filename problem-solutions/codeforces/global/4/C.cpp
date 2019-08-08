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

const ll MOD = 998244353;
ll w, h;

ll mul(ll a, ll b){
	return (a*b)%MOD;
}

int main(void){
	fastcin;
	cin >> w >> h;

	ll ans = 4;

	for(int i = 0; i < w-1; i++){
		ans = mul(ans, 2);
	}
	for(int i = 0; i < h-1; i++){
		ans = mul(ans, 2);
	}

	cout << ans << endl;

	return 0;
}