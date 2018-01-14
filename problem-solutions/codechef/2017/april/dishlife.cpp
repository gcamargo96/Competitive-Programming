#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 100002;
int t, n, k;
int cnt[N];
vi islands[N];

void init(){
	memset(cnt, 0, sizeof cnt);

	For(i,0,N){
		islands[i].clear();
	}
}

int main(void){
	scanf("%d", &t);

	while(t--){
		init();
		scanf("%d%d", &n, &k);
		
		int m;
		For(i,0,n){
			scanf("%d", &m);
			int x;
			For(j,0,m){
				scanf("%d", &x);
				islands[i].pb(x);
				cnt[x]++;
			}
		}

		bool ok = 1;
		for(int i = 1; i <= k; i++){
			if(cnt[i] == 0){
				ok = 0;
				break;
			}
		}

		if(!ok){
			printf("sad\n");
			continue;
		}

		bool all = 1;
		For(i,0,n){
			ok = 1;
			For(j,0,islands[i].size()){
				int x = islands[i][j];
				if(cnt[x] == 1){
					ok = 0;
					break;
				}
			}
			if(ok){
				all = 0;
				break;
			}
		}

		if(all) printf("all\n");
		else printf("some\n");
	}

	return 0;
}
