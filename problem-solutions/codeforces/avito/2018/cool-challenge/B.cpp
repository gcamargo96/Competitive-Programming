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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int n;
vi pos[N];
int v[N], cnt[N], ans[N];
int cur = 0;

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		cnt[v[i]]++;
		pos[v[i]].pb(i);
	}

	if(cnt[0] > 0){
		if(cnt[0] == n){
			printf("Possible\n");
			for(int i = 0; i < n; i++){
				printf("1 ");
			}
			printf("\n");
		}
		else{
			printf("Impossible\n");
		}
		return 0;
	}


	for(int i = 1; i <= n; i++){
		if(cnt[i] > 0 and cnt[i]%(n-i) != 0){
			printf("Impossible\n");
			return 0;
		}
	}

	printf("Possible\n");

	for(int i = 0; i < N; i++){
		// printf("%d: ", i);
		for(int j = 0; j < pos[i].size(); j++){
			// printf("%d ", pos[i][j]);
			int p = pos[i][j];
			if(j%(n-i) == 0) cur++;
			ans[p] = cur;
		}
		// printf("\n");
	}

	for(int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}