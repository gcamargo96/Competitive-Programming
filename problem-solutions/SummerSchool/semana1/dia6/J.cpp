#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define MOD 1000000007

const int N = 100002;
int v[N];
ll fat[N];
int n;

void precalc(){
	fat[0] = 1LL;
	for(int i = 1; i < N; i++){
		fat[i] = (i*fat[i-1])%MOD;
	}
}

ll fastpow(ll b, ll e){
	if(e == 0) return 1LL;

	ll x = fastpow(b, e/2)%MOD;
	if(e%2 == 0) return (x*x)%MOD;
	else return (((x*x)%MOD)*b)%MOD;
}

int main(void){
	precalc();
	scanf("%d", &n);

	int sum = 0, duplas = 0;
	For(i,0,n){
		scanf("%d", &v[i]);
		sum += v[i];
		if(v[i] == 3) duplas++;
	}

	if(sum != 2*(n-1)){
		printf("0\n");
		return 0;
	}

	ll den = fastpow(2, duplas);
	ll res = (fat[n-2] * fastpow(den, MOD-2))%MOD;

	printf("%lld\n", res);

	return 0;
}

