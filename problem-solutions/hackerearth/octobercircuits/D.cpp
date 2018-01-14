#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 300002;
int n, q, a, b;
ll seg[4*N];
vector<pair<ll,ll> > pred;
vector<ll> predx;

ll query(int r, int i, int j){
	if(b < i || a > j) return -1000000005;
	if(a <= i && j <= b) return seg[r];
	
	int mid = (i+j)/2;
	ll L = query(2*r, i, mid);
	ll R = query(2*r+1, mid+1, j);
	return max(L,R);
}

void update(int r, ll x, int i, int j){
	if(b < i || a > j) return;
	if(a <= i && j <= b){
		seg[r] = x;
		return;
	}
	int mid = (i+j)/2;
	update(r*2, x, i, mid);
	update(r*2+1, x, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

int main(void){
	scanf("%d%d", &n, &q);

	ll x, y;
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &x, &y);
		pred.pb(mp(x,y));
	}

	sort(pred.begin(), pred.end());
		
	for(int i = 0; i < n; i++){
		a = b = i+1;
		update(1, pred[i].se, 1, N);
	}

	for(int i = 0; i < n; i++){
		predx.pb(pred[i].fi);
	}


	// for(int i = 1; i <= n; i++){
	// 	a = b = i;
	// 	printf("%lld ", query(1,1,N));
	// }
	// printf("\n");

	ll sx, sy, fx, fy;
	for(int i = 0; i < q; i++){
		scanf("%lld%lld%lld%lld", &sx, &sy, &fx, &fy);

		if(sx > fx){
			swap(sx, fx);
			swap(sy, fy);
		}

		a = upper_bound(predx.begin(), predx.end(), sx) - predx.begin();
		b = lower_bound(predx.begin(), predx.end(), fx) - predx.begin() - 1;
		
		// printf("a = %d, b = %d\n", a, b);

		ll ans = 0, dx = 0, dy = 0;
		if(a > b){ // nao tem predios entre os pontos
			ans = fx-sx + abs(sy-fy);
		}
		else{ // tem predio(s) entre os pontos
			a++, b++;
			dx = fx-sx;
			// printf("a = %d, b = %d\n", a, b);
			ll py = query(1, 1, N);
			// printf("py = %lld\n", py);
			// dy = max((ll)abs(fy-sy), py-min());
			if(sy > py or fy > py){
				ans = dx + abs(sy-fy);
			}
			else{
				ans = py-sy+1;
				ans += dx;
				ans += py-fy+1;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}