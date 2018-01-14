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

const int N = 100005;
int k;
int a[N];

int main(void){
	scanf("%d", &k);

	for(int i = 0; i < k; i++){
		scanf("%d", &a[i]);
	}

	reverse(a, a+k);

	ll l = 2, r = 2;
	for(int i = 0; i < k; i++){
		// printf("l = %lld, r = %lld\n", l, r);
		if(r < a[i]){
			printf("-1\n");
			return 0;
		}

		ll nl = l - l%a[i];
		if(nl < l) nl += a[i];
		if(!(nl >= l and nl <= r)){
			printf("-1\n");
			return 0;
		}

		ll nr = r - r%a[i];// + (a[i]-1);
		if(!(nr >= l and nr <= r)){
			printf("-1\n");
			return 0;
		}
		nr += (a[i]-1);

		if(nl > nr){
			printf("-1\n");
			return 0;
		}

		l = nl, r = nr;
	}

	printf("%lld %lld\n", l, r);	


	return 0;
}