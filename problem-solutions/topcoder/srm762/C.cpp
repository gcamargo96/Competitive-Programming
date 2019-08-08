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

class Strawberry{
public:
	vector<int> a, b;
	int zero = 205;
	ll dp[105][205+105];
	int n, k;
	ll pA[205], pB[205];
	const ll MOD = 1000000007;

	ll add(ll a, ll b){
		return (a+b)%MOD;
	}

	ll mul(ll a, ll b){
		return (a*b)%MOD;
	}

	ll fastpow(ll b, ll e){
		if(e == 0) return 1;

		ll x = fastpow(b, e/2);
		if(e%2 == 0){
			return mul(x, x);
		}
		else{
			return mul(b, mul(x,x));
		}
	}

	void precalc(){
		ll sumA = 0, sumB = 0;
		for(int i = 0; i < 2*k+1; i++){
			sumA = add(sumA, a[i]);
			sumB = add(sumB, b[i]);
		}

		ll invA = fastpow(sumA, MOD-2);
		ll invB = fastpow(sumB, MOD-2);

		for(int i = 0; i < 2*k+1; i++){
			pA[i] = mul(a[i], invA);
			pB[i] = mul(b[i], invB);
		}
	}

	ll solve(int round, int diff){
		if(diff < zero-k or diff > zero+k){
			// printf("chegou aqui, round = %d, diff = %d\n", round, diff-zero);
			return 0;
		}
		if(round == n){
			if(diff >= zero-k and diff <= zero+k) return 1;
			return 0;
		}
		if(dp[round][diff] != -1) return dp[round][diff];
	
		ll ret = 0;
		for(int i = 0; i <= 2*k; i++){
			if(round%2 == 0){
				// printf("somou %d no round %d\n", i, round);
				ret = add(ret, mul(pA[i], solve(round+1, diff+i)));
			}
			else{
				// printf("subtraiu %d no round %d\n", i, round);
				ret = add(ret, mul(pB[i], solve(round+1, diff-i)));
			}
		}

		return dp[round][diff] = ret;
	}

	int competitive(int n, int k, vector <int> A, vector <int> B){
		a = A, b = B;
		this->n = n;
		this->k = k;

		memset(dp, -1, sizeof dp);
		precalc();
		ll ans = solve(0, zero);

		return ans;
	}

};

int main(void){
	int n, k;
	vi a, b;

	scanf("%d%d", &n, &k);

	int x;
	for(int i = 0; i <= 2*k; i++){
		scanf("%d", &x);
		a.pb(x);
	}
	for(int i = 0; i <= 2*k; i++){
		scanf("%d", &x);
		b.pb(x);
	}

	Strawberry s;
	cout << s.competitive(n, k, a, b) << endl;

	return 0;
}