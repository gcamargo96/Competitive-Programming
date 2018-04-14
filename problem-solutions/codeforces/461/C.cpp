#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
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

ll n, k;
set<ll> s;

int main(void){
	scanf("%lld%lld", &n, &k);

	if(n%2 == 0 and k > 1){
		printf("No\n");
		return 0;
	}

	for(ll i = 1; i <= k; i++){
		ll x = n%i;
		if(s.count(x)){
			printf("No\n");
			return 0;
		}
		s.insert(x);
	}

	printf("Yes\n");

	return 0;
}