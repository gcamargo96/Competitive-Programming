#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 200002;
int n;
ll k;
ll v[N], acum[N];
map<ll, ll> m;

int main(void){
	scanf("%d%lld", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
		acum[i] = acum[i-1] + v[i];
		m[acum[i]]++;
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ll aux = k + acum[i-1];
		if(m.count(aux)){
			ans += m[aux];
		}
		m[acum[i]]--;
	}

	printf("%lld\n", ans);

	return 0;
}