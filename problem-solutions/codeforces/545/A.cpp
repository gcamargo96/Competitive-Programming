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

const int N = 100005;
int n;

int main(void){
	scanf("%d", &n);

	vector<int> v;
	int last = 0, cnt = 0, x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(x != last){
			v.pb(cnt);
			cnt = 0;
		}
		cnt++;
		last = x;
	}
	v.pb(cnt);

	int ans = 0;
	for(int i = 1; i < v.size()-1; i++){
		// printf("%d ", v[i]);
		ans = max(ans, 2*min(v[i], v[i+1]));
	}
	// printf("\n");

	printf("%d\n", ans);

	return 0;
}