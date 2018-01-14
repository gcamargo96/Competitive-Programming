#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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
int n, m, q;
int c[N];

int main(void){
	scanf("%d%d%d", &n, &m, &q);

	int cnt;
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &c[i], &cnt);
		int u;
		for(int j = 0; j < cnt; j++){
			scanf("%d", &u);
		}
	}

	int a, b;
	for(int i = 0; i < q; i++){
		scanf("%d%d", &a, &b);
	}

	printf("%d\n", m);
	for(int i = 1; i <= m; i++){
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}