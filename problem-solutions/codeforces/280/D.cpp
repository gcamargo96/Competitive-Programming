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

#define VANYA 0
#define VOVA 1
#define BOTH 2

const int N = 100002;
vi res;
int n;
ll x, y;

int main(void){
	scanf("%d%lld%lld", &n, &x, &y);
	
	ll cntx = 0, cnty = 0;
	For(i,0,x+y){
		if((cntx+1)*y > (cnty+1)*x){
			res.pb(VOVA);
			cnty++;
		}
		else if((cntx+1)*y < (cnty+1)*x){
			res.pb(VANYA);
			cntx++;
		}
		else{
			res.pb(BOTH);
			res.pb(BOTH);
			cntx++;
			cnty++;
		}
	}

	int m;
	For(i,0,n){
		scanf("%d", &m);
		if(res[(m-1)%(x+y)] == VANYA){
			printf("Vanya\n");
		}
		else if(res[(m-1)%(x+y)] == VOVA){
			printf("Vova\n");
		}
		else{
			printf("Both\n");
		}
	}

	return 0;
}

