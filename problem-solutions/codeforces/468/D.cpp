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

const int N = 100002;
int n;
ii p[N];
int lv[N], cnt[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		scanf("%d", &p[i].fi);
		p[i].se = i+2;
	}

	sort(p, p+n-1);

	lv[1] = 1, cnt[1] = 1;
	for(int i = 0; i < n-1; i++){
		lv[p[i].se] = lv[p[i].fi]+1;
		cnt[lv[p[i].se]]++;
	}

	int ans = 0;
	for(int i = 1; i <= 100000; i++){
		// printf("%d\n", cnt[i]);
		if(cnt[i]%2 == 1){
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}