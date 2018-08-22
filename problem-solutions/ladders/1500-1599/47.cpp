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

int r, g, b;

int main(void){
	scanf("%d%d%d", &r, &g, &b);

	int res = 0;
	int ri, gi, bi;

	if(r > 0 and g > 0 and b > 0){
		res = max(res, 1 + (r-1)/3 + (g-1)/3 + (b-1)/3);
	}
	if(r > 1  and g > 1 and b > 1){
		res = max(res, 2 + (r-2)/3 + (g-2)/3 + (b-2)/3);
	}
	res = max(res, r/3 + g/3 + b/3);

	printf("%d\n", res);

	return 0;
}

