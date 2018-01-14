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

const int N = 20002;
int t, n;
int a[N], b[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		For(i,0,n){
			scanf("%d", &a[i]);
		}
		For(i,0,n){
			scanf("%d", &b[i]);
		}

		bool vez = 0;
		ll r1 = 0, r2 = 0;
		For(i,0,n){
			if(vez){
				r1 += a[i];
			}
			else{
				r1 += b[i];
			}
			vez = !vez;
		}

		vez = 1;
		For(i,0,n){
			if(vez){
				r2 += a[i];
			}
			else{
				r2 += b[i];
			}
			vez = !vez;
		}

		printf("%lld\n", min(r1, r2));
	}

	return 0;
}

