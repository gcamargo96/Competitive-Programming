#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 10002;
ll x, d;
ll pot[70];
ll ans[N];
int n = 1;

void precalc(){
	pot[0] = 1;
	for(int i = 1; i <= 60; i++){
		pot[i] = pot[i-1]*2LL;
	}
}

int main(void){
	precalc();
	scanf("%lld%lld", &x, &d);

	ll sum = 1;
	int j = 1;
	ans[0] = -d, ans[1] = 1;
	for(int i = 2; i <= 10000 and sum < x; i++){
		if(sum + pot[j] > x){
			j = 0;
		}

		// printf("j = %d, pot[j] = %lld\n", j, pot[j]);

		// ans[i] = max(ans[i-j-1]+d, ans[i-1]+1);
		if(j > 0){
			ans[i] = ans[i-1];
		}
		else{
			ans[i] = ans[i-1]+d;
		}
		sum += pot[j];
		j++;
		n++;

		if(ans[i] >= 1000000000000000000LL){
			printf("-1\n");
			return 0;
		}
	}
	ans[1] = 1;

	// printf("sum = %lld\n", sum);

	if(sum == x){
		printf("%d\n", n);
		for(int i = 1; i <= n; i++){
			printf("%lld ", ans[i]);
		}
		printf("\n");
	}
	else{
		printf("-1\n");
	}

	return 0;
}