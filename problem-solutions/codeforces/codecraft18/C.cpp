#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const ll M = 1000000007;
const int N = 1002;
ll fat[N];
int steps[N];
string n;
int k;

void precalc(){
	fat[0] = 1;
	for(ll i = 1; i < N; i++){
		fat[i] = (i * fat[i-1]) % M;
	}
}

ll fastpow(ll b, ll e){
	if(e == 0)
		return 1;

	ll x = fastpow(b, e/2) % M;
	if(e%2 == 0)
		return (x * x) % M;
	else
		return (((x * x) % M) * b) % M;
}

ll ncr(ll n, ll k){
	// cout << "ncr " << n << " " << k << endl;

	if(k > n)
		return 0;

	ll num = fat[n];
	ll den = (fat[k] * fat[n-k]) % M;
	ll res = (num * fastpow(den, M-2)) % M;
	return res;
}

int main(void){
	fastcin;
	precalc();
	cin >> n >> k;

	if(k == 0){
		cout << 1 << endl;
		return 0;
	}

	steps[1] = 0;
	for(int i = 2; i < N; i++){
		int b = __builtin_popcount(i);
		steps[i] = steps[b]+1;
	}

	int b = 0;
	for(int i = 0; i < n.size(); i++){
		if(n[i] == '1')
			b++;
	}

	ll ans = 0;
	if(steps[b] == k-1)
		ans++;

	int max_dig = max(b, int(n.size())-1);

	vector<int> reduce_to;
	for(int i = 1; i < N; i++){
		if(i > max_dig){
			break;
		}

		if(steps[i] == k-1){
			reduce_to.pb(i);
		}
	}

	// fix first bit as 1
	for(int i = 0; i < reduce_to.size(); i++){
		// cout << reduce_to[i] << " ";
		int ones = 0;
		for(int j = int(n.size()-1); j >= 1; j--){
			int pos = int(n.size()-1) - j;
			if(n[j] == '1'){
				ones++;
				if(b-ones <= reduce_to[i]){
					// cout << "j = " << j << endl; 
					ans += ncr(pos, reduce_to[i] - (b-ones));
					ans %= M;
				}
			}
		}
	}
	// cout << endl;

	// fix first bit as 0
	for(int i = 0; i < reduce_to.size(); i++){
		ans += ncr(int(n.size()-1), reduce_to[i]);
		ans %= M;
	}

	ans = (ans + M) % M;

	cout << ans << endl;

	return 0;
}