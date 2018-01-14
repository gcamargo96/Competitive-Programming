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

int n, a, b;

int main(void){
	scanf("%d%d%d", &n, &a, &b);

	int ans = -1;
	for(int i = 1; i < n; i++){
		int pa = i;
		int pb = n-i;

		ans = max(ans, min(a/pa, b/pb));
	}

	printf("%d\n", ans);

	return 0;
}