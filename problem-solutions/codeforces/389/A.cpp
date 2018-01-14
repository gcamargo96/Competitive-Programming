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

const int N = 10002;
int n, m, k;

int main(void){
	scanf("%d%d%d", &n, &m, &k);
	k--;

	int cad_por_lane = 2 * m;
	int col = k/cad_por_lane;
	int d = (k-col*cad_por_lane)/2;

	col++, d++;

	printf("%d %d ", col, d);
	if(k%2 == 0) printf("L\n");
	else printf("R\n");

	return 0;
}

