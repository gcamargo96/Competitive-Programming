#include <bits/stdc++.h>
using namespace std;
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

int main(void){
	scanf("%d%d", &a, &b);

	int d = abs(a-b);

	int cur = 1, ans = 0;
	for(int i = 1; i <= d/2; i++){
		ans += 2*cur;
		cur++;
	}
	if(d%2 == 1){
		ans += cur;
	}

	printf("%d\n", ans);

	return 0;
}