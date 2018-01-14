#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int v1, v2, v3, vm;
int c1, c2, c3, cm;

bool test(int v, int c){
	if(c >= v and c <= 2*v){
		return 1;
	}
	else{
		return 0;
	}
}

int main(void){
	scanf("%d%d%d%d", &v1, &v2, &v3, &vm);

	int c3 = max(v3, vm);
	bool ok = test(v3, c3) && test(vm, c3);
	if(!ok){
		printf("-1\n");
		return 0;
	}

	int c2 = max(2*vm+1, max(v2, c3+1));
	ok = test(v2, c2);
	if(!ok){
		printf("-1\n");
		return 0;
	}

	int c1 = max(2*vm+1, max(v1, c2+1));
	ok = test(v3, c3);
	if(!ok){
		printf("-1\n");
		return 0;
	}

	printf("%d\n%d\n%d\n", c1, c2, c3);

	return 0;
}