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

int t, n, m;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &m);

		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
		}

		printf("%d\n", n%2);
	}

	return 0;
}