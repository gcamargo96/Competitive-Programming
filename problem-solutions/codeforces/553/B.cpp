#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 505;
int n, m;
int a[N][N];
int need[N], can[N];
int cnt_can, cnt_need, has[N], dont[N], ans[N];

void init(){
	cnt_can = 0;
	cnt_need = n;
	for(int i = 0; i < n; i++){
		need[i] = 1;
		can[i] = 0;
		has[i] = -1;
		dont[i] = -1;
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for(int b = 0; b < 10; b++){
		init();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(((a[i][j]>>b)&1) == 1){
					can[i] = 1;
					has[i] = j+1;
				}
				else{
					need[i] = 0;
					dont[i] = j+1;
				}
			}

			if(can[i]) cnt_can++;
			if(need[i] == 0) cnt_need--;
		}

		if(cnt_need%2 == 1 or (cnt_need%2 == 0 and cnt_can-cnt_need > 0)){

			for(int i = 0; i < n; i++){
				if(need[i]) ans[i] = has[i];
				else ans[i] = dont[i];
			}

			if(cnt_need%2 == 0){
				for(int i = 0; i < n; i++){
					if(need[i] == 0 and can[i] == 1){
						ans[i] = has[i];
						break;
					}
				}
			}

			printf("TAK\n");

			for(int i = 0; i < n; i++){
				printf("%d ", ans[i]);
			}
			printf("\n");
			
			return 0;
		}
	}

	printf("NIE\n");

	return 0;
}