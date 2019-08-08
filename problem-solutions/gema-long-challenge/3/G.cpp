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

#define INF 0x3f3f3f3f

const int N = 300005;
int n;
int v[N], pos[N], nxt[N], ans[N];

int main(void){
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		v[i]--;
		pos[v[i]] = i;
	}

	for(int i = 0; i < n; i++){
		nxt[i] = pos[v[i]+1];
		if(v[i] == n-1) nxt[i] = -INF;
	}

	int id = -1, cnt = 0;
	for(int i = 0; i < n-1; i++){
		if(nxt[i] > nxt[i+1]){
			id = i+1;
			cnt++;
		}
	}

	// printf("cnt = %d\n", cnt);

	if(cnt > 1){
		printf("Error\n");
		return 0;
	}

	if(cnt == 1){
		for(int i = id; i < n; i++){
			ans[v[i]] = 1;
		}
	}

	for(int i = 0; i < n; i++){
		printf("%d", ans[i]);
	}
	printf("\n");

	return 0;
}