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

const int N = 105;
int n, m, k;
int p[N], s[N];
vector<ii> school[N];

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}

	for(int i = 1; i <= n; i++){
		scanf("%d", &s[i]);
	}

	for(int i = 1; i <= n; i++){
		school[s[i]].pb(ii(p[i], i));
	}

	for(int i = 1; i <= m; i++){
		sort(school[i].begin(), school[i].end());
	}

	int id, ans = 0;
	for(int i = 0; i < k; i++){
		scanf("%d", &id);
		int x = s[id];
		if(school[x][school[x].size()-1].se != id){
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}