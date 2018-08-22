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

set<ll> ans, s;
int n;

int main(void){
	scanf("%d", &n);

	ll x;
	scanf("%lld", &x);
	ans.insert(x), s.insert(x);

	for(int i = 1; i < n; i++){
		scanf("%lld", &x);
		
		set<ll> ss;
		ss.insert(x), ans.insert(x);

		for(ll y : s){
			ss.insert(__gcd(x, y));
			ans.insert(__gcd(x,y));
		}

		s = ss;
	}

	printf("%d\n", int(ans.size()));

	return 0;
}