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
#define N 100100

void cpy(ll source[2][2], ll to[2][2]) {
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			to[i][j] = source[i][j];
		}
	}
}

void mul(ll a[2][2], ll b[2][2], ll c[2][2]) {
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			c[i][j] = 0;
			for(int k=0;k<2;k++) {
				c[i][j] += (a[i][k] * b[k][j]) % MOD;
				c[i][j] %= MOD;   	
			}
		}
	}
}

ll c[2][2], m[2][2], res[2][2];
void fast_pow(ll e) {
	res[1][1] = res[0][0] = 1;
	res[0][1] = res[1][0] = 0;
	m[0][0] = m[0][1] = 1;
	m[1][0] = 1;
	m[1][1] = 0;
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

int ans[2][1], base[2][1];
int x;

int main () {
	base[0][0] = 0;
   	base[0][1] = 1;
	cin >> x;

	fast_pow(x);

	/*For(i,0,2){
		For(j,0,2){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}*/

	for(int i=0;i<2;i++) {
		for(int j=0;j<1;j++) {
			ans[i][j] = 0;
			for(int k=0;k<2;k++) {
				ans[i][j] += (res[i][k] * base[k][j]) % MOD;
				ans[i][j] %= MOD;   	
			}
		}
	}

	cout << ans[0][0] << endl;
	cout << ans[0][1] << endl;
}


