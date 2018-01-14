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

int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	int l, r;
	int res = INF;
	For(i,0,m){
		scanf("%d%d", &l, &r);
		res = min(res, r-l+1);
	}


	printf("%d\n", res);
	For(i,0,n){
		printf("%d ", i%res);
	}
	printf("\n");

	return 0;
}

