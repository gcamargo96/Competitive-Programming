#include <bits/stdc++.h>
using namespace std;
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

int t;
ll x, n, m;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%lld", &x);
		
		if(x == 0){
			printf("1 1\n");
			continue;
		}
		if(x == 1){
			printf("-1\n");
			continue;
		}

		pair<ll,ll> ans(-1, -1);
		for(n = 1; n <= 100000; n++){
			if(n*n > x){
				ll s = sqrt(n*n-x);
				m = n/s;
				if(n*n - (n/m)*(n/m) == x){
					ans.fi = n;
					ans.se = m;
					break;
				}
			}
		}

		if(ans.fi != -1 and ans.se != -1){
			printf("%lld %lld\n", ans.fi, ans.se);
		}
		else{
			printf("-1\n");
		}
	}

	return 0;
}