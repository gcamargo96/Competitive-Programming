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

int n;
map<ll, ll> m;

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		m[x]++;
	}

	ll ans = (m[0]*(m[0]-1LL))/2LL;
	for(int i = 1; i <= 10; i++){
		ans += m[i]*(m[-i]);
	}

	cout << ans << endl;

	return 0;
}