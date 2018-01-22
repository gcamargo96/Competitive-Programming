#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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

const int N = 1002;
ll n;

int main(void){
	scanf("%lld", &n);

	ll x, ans = -1;
	for(int i = 0; i < n; i++){
		scanf("%lld", &x);
		
		bool perf = 0;
		int sqr = sqrt(x) + 1;
		for(ll j = 1; j < x; j++){
			if(j*j == x){
				perf = 1;
				break;
			}
		}

		if(!perf){
			ans = max(ans, x);
		}
		// ll s = sqrt(x);
		// if(s*s != x){
		// 	ans = max(ans, x);
		// }
	}

	printf("%lld\n", ans);

	return 0;
}