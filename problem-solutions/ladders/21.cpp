#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 1002;
int n, m, u, v;
int p[N];

int main(void){
	scanf("%d%d", &n, &m);

	For(i,0,n){
		scanf("%d", &p[i]);
	}

	int res = 0;
	For(i,0,m){
		scanf("%d%d", &u, &v);
		res += min(p[u-1], p[v-1]);
	}

	printf("%d\n", res);

	return 0;
}

