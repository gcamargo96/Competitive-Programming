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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n, a, b;

int main(void){
	scanf("%lld%lld%lld", &n, &a, &b);

	for(ll i = 0; i*a <= n; i++){
		ll resto = n - i*a;
		
		if(resto == 0){
			printf("YES\n");
			printf("%lld 0\n", i);
			return 0;
		}

		if(resto%b == 0){
			printf("YES\n");
			printf("%lld %lld\n", i, resto/b);
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}