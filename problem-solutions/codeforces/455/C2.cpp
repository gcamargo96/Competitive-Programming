#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000000LL
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define NORMALBLOCK 0
#define NEWBLOCK 1
#define MOD 1000000007

const int N = 5002;
int n;
vector<char> v;
ll bit[N][N];

void update(int i, int id, ll x){
	while(id < N){
		bit[i][id] += x;
		bit[i][id] %= MOD;
		id += (id & -id);
	}
}

ll query(int i, int id){
	ll sum = 0;
	while(id > 0){
		sum += bit[i][id];
		sum %= MOD;
		id -= (id & -id);
	}

	return sum;
}

int main(void){
	fastcin;
	cin >> n;

	char c;
	v.pb('#');
	for(int i = 1; i <= n; i++){
		cin >> c;
		v.pb(c);
	}

	// for each lv
	for(int i = 1; i <= n; i++){
		// dp[n-1][i] = 1;
		update(n, i, 1);
	}
	
	// for each statement
	for(int i = n-1; i >= 1; i--){
		// for each lv
		for(int j = 1; j <= n; j++){
			if(v[i] == 's'){
				// dp[i][j] = dp[i+1][j];
				ll x = query(i+1, j) - query(i+1, j-1);
				x = (x + MOD)%MOD;
				update(i, j, x);
				if(v[i-1] != 'f'){
					// dp[i][j] += dp[i][j-1];
					x = query(i, j-1) - query(i, j-2);
					x = (x + MOD)%MOD;
					update(i, j, x);
				}
			}
			if(v[i] == 'f'){
				// dp[i][j] = dp[i+1][j+1];
				ll x = query(i+1, j+1) - query(i+1, j);
				x = (x + MOD)%MOD;
				update(i, j, x);
				if(v[i-1] != 'f'){
					// dp[i][j] += dp[i][j-1];
					x = query(i, j-1) - query(i, j-2);
					x = (x + MOD)%MOD;
					update(i, j, x);
				}
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << query(i, j) - query(i, j-1) << " ";
		}
		cout << endl;
	}

	ll ans = query(1, 1)%MOD;
	ans = (ans + MOD)%MOD;
	cout << ans << endl;

	return 0;
}