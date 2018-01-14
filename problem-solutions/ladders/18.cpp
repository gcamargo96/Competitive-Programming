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

const int N = 52;
int v[N];
int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	For(i,0,m){
		scanf("%d", &v[i]);
	}

	sort(v, v+m);

	int dif = v[n-1]-v[0];
	for(int i = 1; i+n-1 < m; i++){
		dif = min(dif, v[i+n-1]-v[i]);
	}

	printf("%d\n", dif);

	return 0;
}
