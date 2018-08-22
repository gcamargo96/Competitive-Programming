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

const int N = 2005, Q = 100005;
string s, t;
int n, m, q;
int oc[N], acum[N];

int main(void){
	fastcin;
	cin >> n >> m >> q;
	cin >> s >> t;

	s = "#" + s;
	t = "#" + t;

	for(int i = 1; i <= n-m+1; i++){
		int ok = 1;
		for(int j = 1; j <= m; j++){
			if(s[i+j-1] != t[j]){
				ok = 0;
			}
		}
		oc[i] = ok;
	}

	for(int i = 1; i <= n; i++){
		// cout << oc[i] << " ";
		acum[i] = acum[i-1] + oc[i];
		// cout << acum[i] << " ";
	}
	// cout << endl;

	int l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;

		if(r-l+1 < m){
			cout << 0 << endl;
		}
		else{
			int ans = acum[r-m+1] - acum[l-1];
			cout << ans << endl;
		}
	}

	return 0;
}