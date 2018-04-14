#include <bits/stdc++.h>
using namespace std;
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

const int K = 100002;
ll n, k;
ll v0[K], v1[K];

bool solve0(ll *v, ll n, ll& dif){
	for(int i = 0; i < k; i += 2){
		if(n > 0){
			v[i] = 1;
			n--;
		}
	}

	ll x = n/k;
	for(int i = 0; i < k; i++){
		v[i] += x;
	}

	n %= k;
	for(int i = 0; i < k; i += 2){
		if(n > 0){
			v[i]++;
			n--;
		}
	}

	for(int i = 1; i < k; i += 2){
		if(n > 0){
			v[i]++;
			n--;
		}
	}

	bool ok = 1;
	for(int i = 0; i < k-1; i++){
		dif = max(dif, abs(v[i]-v[i+1]));
		if(v[i] < 1 or v[i+1] < 1 or v[i] == v[i+1]){
			ok = 0;
		}
	}

	return ok;
}

bool solve1(ll *v, ll n, ll& dif){
	for(int i = 1; i < k; i += 2){
		if(n > 0){
			v[i] = 1;
			n--;
		}
	}

	ll x = n/k;
	for(int i = 0; i < k; i++){
		v[i] += x;
	}

	n %= k;
	for(int i = 1; i < k; i += 2){
		if(n > 0){
			v[i]++;
			n--;
		}
	}

	for(int i = 0; i < k; i += 2){
		if(n > 0){
			v[i]++;
			n--;
		}
	}

	bool ok = 1;
	for(int i = 0; i < k-1; i++){
		dif = max(dif, abs(v[i]-v[i+1]));
		if(v[i] < 1 or v[i+1] < 1 or v[i] == v[i+1]){
			ok = 0;
		}
	}
	
	return ok;

}

int main(void){
	scanf("%lld%lld", &n, &k);

	if(n < k){
		printf("-1\n");
		return 0;
	}

	ll diff0 = 0, diff1 = 0;
	bool ok0 = solve0(v0, n, diff0);
	bool ok1 = solve1(v1, n, diff1);

	if(ok0 and ok1){
		if(diff0 < diff1){
			for(int i = 0; i < k; i++){
				printf("%lld ", v0[i]);
			}
			printf("\n");			
		}
		else{
			for(int i = 0; i < k; i++){
				printf("%lld ", v1[i]);
			}
			printf("\n");
		}
	}
	else if(ok0 and !ok1){
		for(int i = 0; i < k; i++){
			printf("%lld ", v0[i]);
		}
		printf("\n");
	}
	else if(!ok0 and ok1){
		for(int i = 0; i < k; i++){
			printf("%lld ", v1[i]);
		}
		printf("\n");		
	}
	else{
		printf("-1\n");
	}

	return 0;
}