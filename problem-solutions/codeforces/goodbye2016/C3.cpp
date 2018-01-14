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

const int N = 200002;
int n;
int d[N], c[N];

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d%d", &c[i], &d[i]);
	}

	int lo = -INF, hi = INF;
	bool ok = 1;
	For(i,0,n){
		if(lo > hi){	
			printf("Impossible\n");
			return 0;
		}
		if(d[i] == 1 and hi < 1900){
			printf("Impossible\n");
			return 0;
		}
		if(d[i] == 2 and lo >= 1900){
			printf("Impossible\n");
			return 0;
		}

		if(d[i] == 2) hi = min(hi, 1899);
		else lo = max(lo, 1900);

		lo += c[i];
		hi += c[i];
	}

	if(hi > 1e8){
		printf("Infinity\n");
	}
	else{
		printf("%d\n", hi);
	}

	return 0;
}

