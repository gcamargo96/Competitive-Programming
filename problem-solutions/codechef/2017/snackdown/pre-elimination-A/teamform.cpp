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

int t, n, m;

int main(void){
	scanf("%d", &t);

	int u, v;
	while(t--){
		scanf("%d%d", &n, &m);
		
		For(i,0,m){
			scanf("%d%d", &u, &v);
		}

		if(n%2 == 0){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}

	return 0;
}

