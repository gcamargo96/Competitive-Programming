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

const int N = 52;
int n, l;
int a[N], b[N];

int main(void){
	scanf("%d%d", &n, &l);

	For(i,0,n){
		scanf("%d", &a[i]);
	}

	For(i,0,n){
		scanf("%d", &b[i]);
	}

	vi da, db;
	For(i,0,n-1){
		da.pb(a[i+1]-a[i]);
	}
	da.pb(l-a[n-1]+a[0]);

	For(i,0,n-1){
		db.pb(b[i+1]-b[i]);
	}
	db.pb(l-b[n-1]+b[0]);

	/*For(i,0,n){
		printf("%d ", da[i]);
	}
	printf("\n");
	For(i,0,n){
		printf("%d ", db[i]);
	}
	printf("\n");
	*/

	For(j,0,n){
		bool ok = 1;
		For(i,0,n){
			if(da[i] != db[(i+j)%n]){
				ok = 0;
				break;
			}
		}
		if(ok){
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}

