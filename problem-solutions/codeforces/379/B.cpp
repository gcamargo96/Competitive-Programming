#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int k2, k3, k5, k6;
int c32, c256;

int main(void){
	scanf("%d%d%d%d", &k2, &k3, &k5, &k6);

	c256 = min(k2, min(k5, k6));
	k2 -= c256;
	k5 -= c256;
	k6 -= c256;

	c32 = min(k2, k3);

	printf("%d\n", c32*32+c256*256);

	return 0;
}

