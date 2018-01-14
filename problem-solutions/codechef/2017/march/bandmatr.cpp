#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 502;
int t, n;
int g[N][N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		int cnt = 0;
		For(i,0,n){
			For(j,0,n){
				scanf("%d", &g[i][j]);
				if(g[i][j] == 1) cnt++;
			}
		}

		int cur = n;
		cnt -= min(cnt, cur);
		cur--;
		int res = 0;
		while(cnt > 0){
			res++;
			cnt -= min(cnt, 2*cur);
			cur--;
		}

		printf("%d\n", res);
	}

	return 0;
}

