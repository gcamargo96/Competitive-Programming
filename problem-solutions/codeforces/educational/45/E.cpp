#include <bits/stdc++.h>
using namespace std;
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

const int N = 2000005;
int n, m, k;
int a[N], v[N], c[N], nxt[N];
vi costs;

void precalc(){
	int last = 0;
	for(int i = 0; i <= n; i++){
		if(v[i] == 0){
			nxt[i] = i;
			last = i;
		}
		else{
			nxt[i] = last;
		}
	}

	for(int i = n+1; i <= 2*n+2; i++){
		nxt[i] = i;
	}
}

ll calc(int k){
	int i = 0;
	ll ret = 0;
	while(i < n){
		if(nxt[i+k] == i){
			return -1;
		}

		ret += c[k];
		i = nxt[i+k];
	}

	return ret;
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	int x;
	for(int i = 1; i <= m; i++){
		scanf("%d", &x);
		v[x] = 1;
	}

	for(int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
	}

	if(v[0] == 1){
		printf("-1\n");
		return 0;
	}

	precalc();
	
	ll ans = 1000000000000000000LL;
	for(int i = 1; i <= k; i++){
		ll aux = calc(i);
		if(aux != -1){
			ans = min(ans, aux);
		}
	}

	if(ans != 1000000000000000000LL){
		printf("%lld\n", ans);
	}
	else{
		printf("-1\n");
	}

	return 0;
}