#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

const int N = 500005;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	if(n == 1){
		printf("%d\n", v[0]);
		return 0;
	}

	int mn = INF, idmn = -1;
	for(int i = 0; i < n; i++){
		if(v[i] < mn){
			mn = v[i];
			idmn = i;
		}
	}

	int mx = -INF, idmx = -1;
	for(int i = 0; i < n; i++){
		if(v[i] > mx and i != idmn){
			mx = v[i];
			idmx = i;
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(i == idmn){
			ans -= v[i];
		}
		else if(i == idmx){
			ans += v[i];
		}
		else if(v[i] >= 0){
			ans += v[i];
		}
		else{
			ans -= v[i];
		}
	}

	printf("%lld\n", ans);

	return 0;
}