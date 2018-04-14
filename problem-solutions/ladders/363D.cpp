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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n, m, a;
int b[N], p[N];
ll acumb[N], sobrou = 0;
ll bank, gasto;

bool ok(int x){
	if(x == 0)
		return 1;

	bank = a;
	gasto = 0;
	int j = x-1;
	for(int i = 0; i < x; i++){
		if(b[i] >= p[j]){
			gasto += p[j];
		}
		else if(b[i] + bank >= p[j]){
			bank -= p[j]-b[i];
			gasto += b[i];
		}
		else{
			return 0;
		}
		j--;
	}

	return 1;
}

int main(void){
	scanf("%d%d%d", &n, &m, &a);

	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	for(int i = 0; i < m; i++){
		scanf("%d", &p[i]);
	}

	sort(b, b+n, greater<int>());
	sort(p, p+m);

	acumb[0] = b[0];
	for(int i = 1; i < n; i++){
		acumb[i] = b[i] + acumb[i-1];
	}

	int l = 0, r = min(n,m);
	pair<ll,ll> ans(0,0);
	while(l <= r){
		int mid = (l+r)/2;
		if(ok(mid)){
			ans.fi = mid;
			// printf("mid = %d, gasto = %lld, bank = %lld\n", mid, gasto, bank);
			ans.se = max(0LL, gasto-bank);
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}

	printf("%lld %lld\n", ans.fi, ans.se);

	return 0;
}