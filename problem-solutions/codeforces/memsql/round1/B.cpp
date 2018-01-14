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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n, x;

int main(void){
	scanf("%lld", &n);

	x = 1;
	while(x*x < n){
		x++;
	}

	if(x*x == n){
		ll ans = 4LL*x;
		printf("%lld\n", ans);
	}
	else{
		x--;
		ll sum = x*x, ans;
		if(n-sum <= x){
			ans = 4LL*x + 2;
		}
		else{
			ans = 4LL*x + 4;
		}
		printf("%lld\n", ans);
	}

	return 0;
}