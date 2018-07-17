#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 2002;
int n, m;
char g[N][N];
int cnt[N];

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &g[i][j]);
		}
	}

	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(g[i][j] == '1'){
				cnt[j]++;
			}
		}
	}

	bool ans = 0;
	for(int i = 0; i < n; i++){
		bool ok = 1;
		for(int j = 0; j < m; j++){
			if(g[i][j] == '1' and cnt[j] == 1){
				ok = 0;
			}
		}
		if(ok){
			ans = 1;
			break;
		}
	}

	if(ans){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}