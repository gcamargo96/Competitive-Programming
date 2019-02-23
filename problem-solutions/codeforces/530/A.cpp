#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 105;
int stones[N], weights[N];
int w, h, u, d;

int main(void){
	scanf("%d%d", &w, &h);
	
	scanf("%d%d", &u, &d);
	stones[d] = u;

	scanf("%d%d", &u, &d);
	stones[d] = u;

	int cur = w;
	for(int i = h; i >= 0; i--){
		cur += i;
		cur -= stones[i];
		cur = max(cur, 0);
	}

	printf("%d\n", cur);

	return 0;
}