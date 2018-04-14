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
int n, m;
vector<ll> buckets[N];
ll t[N], b[N];

void print_buckets(){
	for(int i = 0; i <= n; i++){
		for(int x : buckets[i]){
			printf("%d ", x);
		}
		printf("\n");
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	t[0] = -INF;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &t[i]);
	}
	t[n+1] = INF;

	int j = 0;
	ll x;
	for(int i = 0; i < m; i++){
		scanf("%lld", &x);
		while(x >= t[j+1]){
			j++;
		}
		if(x != t[j])
			buckets[j].pb(x);
	}

	// print_buckets();

	ll ans = 0;
	if(buckets[0].size() > 0){
		ans += 2LL*(t[1]-buckets[0][0]);
	}

	for(int i = 1; i < n; i++){
		if(buckets[i].size() == 0)
			continue;

		ll a1 = t[i+1] - t[i]; // atravessar direto
		ll a2 = 2LL*(buckets[i][buckets[i].size()-1] - t[i]); // sair do portal da esquerda, pegar tudo e voltar
		ll a3 = 2LL*(t[i+1] - buckets[i][0]); // sair do portal da direita, pegar tudo e voltar
		ll a4 = INF;
		for(int j = 0; j < int(buckets[i].size())-1; j++){
			a4 = min(a4, 2LL*(t[i+1]-t[i] - (buckets[i][j+1]-buckets[i][j])));
		}
		ll cur = min(min(a1, a2), min(a3, a4));
		// printf("cur %d = %lld\n", i, cur);
		ans += cur;
	}


	if(buckets[n].size() > 0){
		ans += 2LL*(buckets[n][buckets[n].size()-1] - t[n]);
	}

	printf("%lld\n", ans);

	return 0;
}