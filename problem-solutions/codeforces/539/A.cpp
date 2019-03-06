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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, v;

int main(void){
	scanf("%d%d", &n, &v);

	int tank = 0, ans = 0;
	for(int i = 1; i < n; i++){
		if(tank >= n-i) break;
		int add = min(v-tank, n-i);
		ans += i*add;
		tank += add;
		tank--;
	}

	printf("%d\n", ans);

	return 0;
}