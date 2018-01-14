#include <bits/stdc++.h>
using namespace std;
#define INF 1000000005
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
ii chessL, chessR, progL, progR;

int main(void){
	chessL.se = INF;
	progL.se = INF;

	scanf("%d", &n);

	int l , r;
	For(i,0,n){
		scanf("%d%d", &l, &r);
		ii aux = ii(l,r);
		if(aux.se < chessL.se){
			chessL = aux;
		}
		chessR = max(chessR, aux);
	}

	scanf("%d", &m);

	For(i,0,m){
		scanf("%d%d", &l, &r);
		ii aux = ii(l,r);
		if(aux.se < progL.se){
			progL = aux;
		}
		progR = max(progR, aux);
	}

	//printf("%d %d\n", chessL.se, progR.fi);
	//printf("%d %d\n", progL.se, chessR.fi);

	int res = max(progR.fi - chessL.se, chessR.fi - progL.se);
	if(res < 0) res = 0;

	printf("%d\n", res);
	
	return 0;
}

