#include <bits/stdc++.h>
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define endl "\n"
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define ii pair<int,int>
#define ll long long
#define For(i,x,y) for(int i=x; i<y; i++)
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define MOD 1000000007
#define PI acos(-1.0)
#define debug printf
using namespace std;
const double eps = 1e-9;
#define N 105

ll c[N][N], m[N][N], res[N][N];
ll ans[N][1], base[N][1];
ll n, x;

void cpy(ll source[N][N], ll to[N][N]) {
	for(int i=0;i<x;i++) {
		for(int j=0;j<x;j++) {
			to[i][j] = source[i][j];
		}
	}
}

void mul(ll a[N][N], ll b[N][N], ll c[N][N]) {
	for(int i=0;i<x;i++) {
		for(int j=0;j<x;j++) {
			c[i][j] = 0;
			for(int k=0;k<x;k++) {
				c[i][j] += (a[i][k] * b[k][j]) % MOD;
				c[i][j] %= MOD;   	
			}
		}
	}
}

void fast_pow(ll e) {
	while(e > 0LL) {
		if(e & 1LL) {
			mul(res,m,c);
			cpy(c,res);
		}
		mul(m,m,c);
		cpy(c,m);
		e >>= 1;
	}
}

void init(){
	base[0][0] = 2;
	for(int i = 1; i < x; i++){
		base[i][0] = 1;
	}

	for(int i = 0; i < x; i++){
		res[i][i] = 1;
	}

	m[0][0] = m[0][x-1] = 1;
	for(int i = 1; i < x; i++){
		m[i][i-1] = 1;
	}
}


int main () {
	cin >> n >> x;

	if(n < x){
		cout << 1 << endl;
		return 0;
	}

	init();
	fast_pow(n-x);

	// For(i,0,x){
	// 	For(j,0,x){
	// 		cout << res[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// For(i,0,x){
	// 	cout << base[i][0] << endl;
	// }

	for(int i=0;i<x;i++) {
		for(int j=0;j<1;j++) {
			ans[i][j] = 0;
			for(int k=0;k<x;k++) {
				ans[i][j] += (res[i][k] * base[k][j]) % MOD;
				ans[i][j] %= MOD;   	
			}
		}
	}

	// cout << ans[0][0] << endl;
	// cout << ans[0][1] << endl;
	cout << ans[0][0] << endl;
}

