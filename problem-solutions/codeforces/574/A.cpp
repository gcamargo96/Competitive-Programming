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

const int N = 1005;
int n, k;
int cnt[N];

int main(void){
	scanf("%d%d", &n, &k);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		cnt[x]++;
	}

	int ans = 0;
	for(int i = 1; i <= k; i++){
		if(cnt[i]%2 == 0){
			ans += cnt[i];
			cnt[i] = 0;
		}
	}

	// for(int i = 1; i <= k; i++){
	// 	printf("%d ", cnt[i]);
	// }
	// printf("\n");

	int r = 0;
	for(int i = 1; i <= k; i++){
		x = min(cnt[i], r);
		cnt[i] -= x;
		r -= x;

		if(cnt[i]%2 == 0){
			ans += cnt[i];
		}
		else if(cnt[i] > 0){
			ans += cnt[i];
			r++;
		}
	}	

	printf("%d\n", ans);

	return 0;
}