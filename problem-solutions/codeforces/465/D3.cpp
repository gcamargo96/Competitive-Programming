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

const int N = 100005;
const ll M = 1000000007;
int n, m;
ll p[N], a[N], b[N];
ll inv2, invm, inv2m;

ll fastpow(ll b, ll e){
	if(e == 0)
		return 1;

	ll x = fastpow(b, e/2);
	if(e%2 == 0){
		return (x*x)%M;
	}
	else{
		return ((x*x)%M * b)%M;
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%lld", &b[i]);
	}

	inv2 = fastpow(2, M-2);
	invm = fastpow(m, M-2);
	inv2m = fastpow(2LL*m, M-2);

	p[n] = 0;
	for(int i = n-1; i >= 0; i--){
		if(a[i] > 0 and b[i] > 0){
			if(a[i] == b[i]){
				p[i] = p[i+1];
			}
			else if(a[i] > b[i]){
				p[i] = 1;
			}
			else if(a[i] < b[i]){
				p[i] = 0;
			}
		}
		else if(a[i] == 0 and b[i] > 0){
			p[i] = ((m-b[i]) * invm)%M;
			p[i] += (p[i+1] * invm)%M;
			p[i] %= M;
		}
		else if(a[i] > 0 and b[i] == 0){
			p[i] = ((a[i]-1) * invm)%M;
			p[i] += (p[i+1] * invm)%M;
			p[i] %= M;
		}
		else if(a[i] == 0 and b[i] == 0){
			p[i] = ((m-1) * inv2m)%M;
			p[i] += (p[i+1] * invm)%M;
			p[i] %= M;
		}
	}

	printf("%lld\n", p[0]);

	return 0;
}