#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

int n;
ll p, q, b;

ll gcd(ll a, ll b) {
    return b == 0LL ? a : gcd(b, a % b);
}

int main(void){
	scanf("%d", &n);

	while(n--){
		scanf("%lld%lld%lld", &p, &q, &b);

		ll g = gcd(p, q);
		p /= g;
		q /= g;

		bool ok = 1;
		while(q > 1){
			g = gcd(q, b);
			if(g == 1){
				ok = 0;
				break;
			}
			while(q%g == 0){
				q /= g;
			}
		}

		if(ok){
			printf("Finite\n");
		}
		else{
			printf("Infinite\n");
		}
	}

	return 0;
}