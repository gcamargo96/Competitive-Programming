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

const int N = 205;
int n;
vi v[N], inv[N];
int a[N], ans[N];

void no(){
	printf("NO\n");
	exit(0);
}

int main(void){
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);

	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		a[i] = i;
	}

	int x;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			scanf("%d", &x);
			v[i].pb(x);
			inv[i].pb(x);
		}
		reverse(inv[i].begin(), inv[i].end());
	}

	for(int i = n-1; i >= 1; i--){
		for(int j = i; j <= n-1; j++){
			if(v[j].back() == 1){
				// printf("swaped %d %d\n", j, j+1);
				swap(a[j], a[j+1]);
			}
			v[j].pop_back();
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");


	for(int i = 1; i <= n; i++){
		ans[i] = a[i];
	}

	for(int i = 1; i <= n-1; i++){
		for(int j = n-1; j >= i; j--){
			if(inv[j].back() == 1){
				if(a[j] > a[j+1]){
					swap(a[j], a[j+1]);
				}
				else{
					no();
				}
			}
			else if(a[j] > a[j+1]){
				no();
			}
			inv[j].pop_back();
		}
	}

	for(int i = 1; i <= n; i++){
		if(a[i] != i){
			no();
		}
	}

	printf("YES\n");

	for(int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}
