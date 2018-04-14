#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
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

int a, b;
int holes[12];

int main(void){
	memset(holes, 0, sizeof holes);
	holes[0] = holes[6] = holes[9] = 1;
	holes[8] = 2;
	scanf("%d%d", &a, &b);

	ii ans(-1,-1);

	if(a == 0)
		ans = ii(0,1);

	for(int i = a; i <= b; i++){
		int aux = i, cnt = 0;
		while(aux > 0){
			int d = aux%10;
			cnt += holes[d];
			aux /= 10;
		}

		if(cnt > ans.se){
			ans.fi = i;
			ans.se = cnt;
		}
	}

	printf("%d\n", ans.fi);

	return 0;
}