#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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
int n, k;
int a[N], t[N], acum[N];

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 1; i <= n; i++){
		scanf("%d", &t[i]);
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		acum[i] = acum[i-1];
		if(t[i] == 0){
			acum[i] += a[i];
		}
		else{
			ans += a[i];
		}
	}

	int best = 0;
	for(int i = 1; i <= n-k+1; i++){
		best = max(best, acum[i+k-1]-acum[i-1]);
	}
	// cout << "best = " << best << endl;
	ans += best;

	printf("%d\n", ans);

	return 0;
}