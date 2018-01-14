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

const int N = 705;
int t, n;
int a[N][N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &a[i][j]);
			}
		}

		int last = 1000000002;
		ll sum = 0;
		bool ok = 1;
		for(int i = n-1; i >= 0; i--){
			int best = -1;
			for(int j = 0; j < n; j++){
				if(a[i][j] > best and a[i][j] < last){
					best = a[i][j];
				}
			}

			if(best == -1){
				ok = 0;
				break;
			}

			sum += ll(best);
			last = best;
		}

		if(ok){
			printf("%lld\n", sum);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}