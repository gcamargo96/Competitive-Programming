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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

const int N = 100005;
int first[N], last[N];
int n, k;

int main(void){
	scanf("%d%d", &n, &k);

	memset(first, INF, sizeof first);
	memset(last, -1, sizeof last);

	int pos;
	for(int i = 1; i <= k; i++){
		scanf("%d", &pos);

		first[pos] = min(first[pos], i);
		last[pos] = i;
	}

	// for(int i = 1; i <= n; i++){
		// printf("%d ", last[i]);
	// }
	// printf("\n");

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(last[i] == -1){
			ans++;
		}
	}

	// printf("init ans = %d\n", ans);

	for(int i = 1; i < n; i++){
		if(first[i] >= last[i+1]){
			ans++;
		}
	}

	// printf("ans 2 = %d\n", ans);

	for(int i = n; i > 1; i--){
		if(first[i] >= last[i-1]){
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}