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

#define INF 0x3f3f3f3f

const int N = 5005;
int n, q;
int acc1[N], acc2[N];
int tot[N];
ii seg[N];

void add(int l, int r){
	for(int i = l; i <= r; i++){
		tot[i]++;
	}
}

int main(void){
	scanf("%d%d", &n, &q);

	int l, r;
	for(int i = 0; i < q; i++){ // n^2
		scanf("%d%d", &l, &r);
		seg[i].fi = l, seg[i].se = r;
		add(l,r);
	}

	for(int i = 1; i <= n; i++){
		acc1[i] = acc1[i-1];
		acc1[i] += (tot[i] == 1);
	}

	for(int i = 1; i <= n; i++){
		acc2[i] = acc2[i-1];
		acc2[i] += (tot[i] == 2);
	}

	int uncovered = 0;
	for(int i = 1; i <= n; i++){
		if(tot[i] == 0) uncovered++;
	}

	int ans = INF;
	for(int i = 0; i < q; i++){
		for(int j = i+1; j < q; j++){
			ii a = seg[i];
			ii b = seg[j];

			if(a.fi > b.fi) swap(a,b);

			if(a == b){
				ans = min(ans, uncovered + acc2[a.se]-acc2[a.fi-1]);
			}
			else if(a.se >= b.se){ // contained
				ans = min(ans, uncovered + acc1[b.fi-1]-acc1[a.fi-1] + acc2[b.se]-acc2[b.fi-1] + acc1[a.se]-acc1[b.se]);
			}
			else if(a.se < b.fi){ // dont intersect
				ans = min(ans, uncovered + acc1[a.se]-acc1[a.fi-1] + acc1[b.se]-acc1[b.fi-1]);
			}
			else{ // intersect
				ans = min(ans, uncovered + acc1[b.fi-1]-acc1[a.fi-1] + acc1[b.se]-acc1[a.se] + acc2[a.se]-acc2[b.fi-1]);
			}
		}
	}

	printf("%d\n", n-ans);

	return 0;
}