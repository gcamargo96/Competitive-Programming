#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 200005;
int n, q;
ll a[N], k[N];
ll acum[N], dmg = 0;

int main(void){
	scanf("%d%d", &n, &q);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i < q; i++){
		scanf("%lld", &k[i]);
	}

	acum[0] = a[0];
	for(int i = 1; i < n; i++){
		acum[i] = acum[i-1] + a[i];
	}

	for(int i = 0; i < q; i++){
		int j = upper_bound(acum, acum+n, dmg+k[i]) - acum;

		if(j == n){
			dmg = 0;
			printf("%d\n", n);
		}
		else{
			dmg += k[i];
			printf("%d\n", n-j);
		}
	}

	return 0;
}