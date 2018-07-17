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

void cpy(ll source[4][4], ll to[4][4]) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			to[i][j] = source[i][j];
		}
	}
}

void mul(ll a[4][4], ll b[4][4], ll c[4][4]) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			c[i][j] = 0;
			for(int k=0;k<4;k++) {
				c[i][j] += (a[i][k] * b[k][j]) % MOD;
				c[i][j] %= MOD;   	
			}
		}
	}
}

ll c[4][4], m[4][4], res[4][4];
void fast_pow(ll e) {
	for(int i = 0; i < 4; i++)
		res[i][i] = 1;	

	for(int i = 0; i < 4; i++){
		for(int j = i; j < 4; j++){
			m[i][j] = 1;
		}
	}

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

int ans[4][1], base[4][1];
int n;

int main () {
	base[0][0] = 4;
	base[1][0] = 3;
	base[2][0] = 2;
	base[3][0] = 1;
	cin >> n;

	if(n == 1){
		cout << 4 << endl;
		return 0;
	}

	fast_pow(n-1);

	/*For(i,0,2){
		For(j,0,2){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}*/

	for(int i=0;i<4;i++) {
		for(int j=0;j<1;j++) {
			ans[i][j] = 0;
			for(int k=0;k<4;k++) {
				ans[i][j] += (res[i][k] * base[k][j]) % MOD;
				ans[i][j] %= MOD;   	
			}
		}
	}

	// for(int i = 0; i < 4; i++){
	// 	for(int j = 0; j < 4; j++){
	// 		cout << res[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;	

	cout << ans[0][0] << endl;
}
