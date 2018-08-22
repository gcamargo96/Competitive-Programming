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

const int N = 100005, K = 260;
int n, k;
int v[N];
int label[K], cnt[K];

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	memset(label, -1, sizeof label);

	for(int i = 0; i < n; i++){
		int x = v[i];

		if(label[x] != -1){
			printf("%d ", label[x]);
			continue;
		}

		// checa se tem algum label até a distancia k
		for(int y = x-1; y >= max(x-k+1, 0); y--){
			if(label[y] != -1){
				// printf("i = %d, cnt[%d] = %d\n", i, label[y], cnt[label[y]]);
				if(cnt[label[y]] + (x-y) <= k){
					for(int l = y+1; l <= x; l++){
						label[l] = label[y];
						cnt[label[y]]++;
					}
				}
				else{
					for(int j = y+1; j <= x; j++){
						label[j] = y+1;
						cnt[y+1]++;
					}
				}
				break;
			}
		}

		if(label[x] == -1){
			// printf("i = %d\n", i);
			int y = max(0, x-k+1);
			for(int j = y; j <= x; j++){
				label[j] = y;
				cnt[y]++;
			}
		}

		// for(int i = 0; i < 15; i++){
		// 	printf("%d ", label[i]);
		// }
		// printf("\n");

		printf("%d ", label[x]);
	}
	printf("\n");

	// for(int i = 0; i < 15; i++){
	// 	printf("%d ", label[i]);
	// }
	// printf("\n");

	return 0;
}