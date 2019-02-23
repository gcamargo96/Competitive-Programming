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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int n, a, b, q;
double seg[4*N];

void init(){
	for(int i = 0; i < N; i++){
		seg[i] = 0;
	}
}

double query(int r, int i, int j){
	if(b < i or a > j) return 0;
	if(a <= i and j <= b) return seg[r];
	int mid = (i+j)/2;	
	double L = query(2*r, i, mid);
	double R = query(2*r+1, mid+1, j);
	return L+R;
}

void update(int r, double x, int i, int j){
	if(b < i or a > j) return;
	if(a <= i and b >= j){
		seg[r] = x;
		return;
	}
	int mid = (i+j)/2;
	update(r*2, x, i, mid);
	update(r*2+1, x, mid+1, j);
	seg[r] = seg[2*r] + seg[2*r+1];
}

int main(void){
	init();
	scanf("%d", &n);

	double x;
	for(int i = 1; i <= n; i++){
		scanf("%lf", &x);
		a = b = i;
		update(1, x, 1, n);
	}

	scanf("%d", &q);

	int t, e, l, r;
	double val;
	while(q--){
		scanf("%d", &t);

		// for(int i = 1; i <= n; i++){
		// 	a = b = i;
		// 	printf("%lf ", query(1, 1, n));
		// }
		// printf("\n");

		if(t == 1){
			scanf("%d%lf", &e, &val);
			a = b = e;
			update(1, val, 1, n);
		}
		else{
			scanf("%d%d", &l, &r);
			a = l, b = r;
			double sum = query(1, 1, n);
			// printf("sum = %lf\n", sum);
			printf("%lf\n", sum/double(r-l+1));
		}
	}

	return 0;
}