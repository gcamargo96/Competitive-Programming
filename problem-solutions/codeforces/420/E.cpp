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

ll c[16][16], m[16][16], res[16][16];
ll ans[16][1], base[16][1];
ll k;
int n;

void init(){
	ans[0][0] = base[0][0] = 1;
	for(int i = 0; i < 16; i++){
		res[i][i] = 1;
	}
}

void cpy(ll source[16][16], ll to[16][16]) {
	for(int i=0;i<16;i++) {
		for(int j=0;j<16;j++) {
			to[i][j] = source[i][j];
		}
	}
}

void mul(ll a[16][16], ll b[16][16], ll c[16][16]) {
	for(int i=0;i<16;i++) {
		for(int j=0;j<16;j++) {
			c[i][j] = 0;
			for(int k=0;k<16;k++) {
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

void calc_ans(){
	for(int i=0;i<16;i++) {
		for(int j=0;j<1;j++) {
			ans[i][j] = 0;
			for(int k=0;k<16;k++) {
				ans[i][j] += (res[i][k] * base[k][j]) % MOD;
				ans[i][j] %= MOD;   	
			}
		}
	}
}

void update_base(int c){
	for(int i = 0; i <= c; i++){
		base[i][0] = ans[i][0];
	}
	for(int i = c+1; i < 16; i++){
		base[i][0] = 0;
	}
}

void update_matrix(int c){
	memset(m, 0, sizeof m);
	memset(res, 0, sizeof res);
	for(int i = 0; i < 16; i++){
		res[i][i] = 1;

		if(i <= c) m[i][i] = 1;
		if(i-1 >= 0 and i <= c) m[i][i-1] = 1;
		if(i+1 <= c) m[i][i+1] = 1;
	}
}

int main () {
	scanf("%d%lld", &n, &k);

	init();
	ll a, b, c;
	for(int i = 0; i < n; i++){
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a >= k) continue;

		update_matrix(c);
		update_base(c);
		fast_pow(min(b,k)-a);
		calc_ans();
	}

	cout << ans[0][0] << endl;
}

