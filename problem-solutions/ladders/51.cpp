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

const int N = 30002;
int n, d;
int pd[N][2*250];
int treasures[N];

int solve(int i, int l){
	if(i > 30000) return 0;
	//cout << "call" << endl;

	int ll = l-d+246;
	int& dp = pd[i][ll];
	if(dp != -1) return dp;
	
	int r1 = 0, r2 = 0, r3 = 0;
	if(l-1 > 0) r1 = solve(i+l-1, l-1);
	if(l > 0) r2 = solve(i+l, l);
	r3 = solve(i+l+1, l+1);

	//if(treasures[i]) cout << "achou em " << i << endl;
	return dp = treasures[i] + max(r1, max(r2, r3));
}

int main(void){
	scanf("%d%d", &n, &d);

	int x;
	For(i,0,n){
		scanf("%d", &x);
		treasures[x]++;
	}

	memset(pd, -1, sizeof pd);
	int res = solve(d, d);

	printf("%d\n", res);

	return 0;
}

