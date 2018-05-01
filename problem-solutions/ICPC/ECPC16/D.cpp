#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 22;
int t;
ll n, m;
ll fat[N];

void precalc(){
	fat[0] = 1;
	for(ll i = 1; i < N; i++){
		fat[i] = fat[i-1] * i;
	}
}

int main(void){
	freopen("popcorn.in", "r", stdin);

	precalc();
	scanf("%d", &t);

	while(t--){
		scanf("%lld%lld", &n, &m);
	
		ll num = fat[n];
		ll den = fat[m] * fat[n-m];
		ll ans = num/den;

		printf("%lld\n", ans);
	}

	return 0;
}