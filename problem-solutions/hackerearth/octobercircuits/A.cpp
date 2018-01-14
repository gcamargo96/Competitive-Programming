#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 300002;
ll a[N], b[N];
int n, m;

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	scanf("%d", &m);

	ll maior = -1;
	for(int i = 0; i < m; i++){
		scanf("%lld", &b[i]);
		maior = max(maior, b[i]);
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] <= maior){
			ans += maior+1 - a[i];
		}
	}

	printf("%lld\n", ans);

	return 0;
}