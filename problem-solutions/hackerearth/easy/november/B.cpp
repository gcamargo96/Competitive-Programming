#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 200002, M = 10000;
ll cnt[M];
int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		cnt[x%m]++;
	}

	ll ans = 0;
	// 3 restos diferentes
	for(int i = 0; i < m; i++){
		for(int j = i+1; j < m; j++){
			if(cnt[i] > 0 and cnt[j] > 0){
				int k = (m-i-j + m)%m;
				if(k > j and cnt[k] > 0){
					// printf("%d %d %d\n", i, j, k);
					ans += cnt[i]*cnt[j]*cnt[k];
				}
			}
		}
	}

	// printf("%lld\n", ans);

	// 2 restos iguais
	for(int i = 0; i < m; i++){
		int k = (m-i-i + m)%m;
		if(k != i and cnt[i] >= 2 and cnt[k] > 0){
			// printf("%d %d %d\n", i, i, k);
			ans += cnt[i]*(cnt[i]-1)/2LL * cnt[k];
		}
	}

	// printf("%lld\n", ans);

	// 3 restos iguais
	for(int i = 0; i < m; i++){
		if((i+i+i)%m == 0 and cnt[i] >= 3){
			// printf("%d %d %d\n", i, i, i);
			ans += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6LL;
		}
	}

	printf("%lld\n", ans);

	return 0;
}