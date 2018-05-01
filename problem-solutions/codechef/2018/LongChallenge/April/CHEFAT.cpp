#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
double seg[4*N], lazy[4*N];
int a, b;
int n, q;

void prop(int r, int i, int j){
	double t = lazy[r];
	seg[r] *= pow(lazy[r], (j-i+1));
	lazy[r] = 1;
	if(i != j){
		lazy[2*r] *= t;
		lazy[2*r+1] *= t;
	}
}

double query(int r, int i, int j){
	prop(r, i, j);
	if(b < i or a > j) return 1;
	if(a <= i and j <= b) return seg[r];
	int mid = (i+j)/2;	
	double L = query(2*r, i, mid);
	double R = query(2*r+1, mid+1, j);
	return L*R;
}

void update(int r, double x, int i, int j){
	prop(r, i, j);
	if(b < i or a > j) return;
	if(a <= i and b >= j){
		seg[r] *= x;
		if(i != j){
			lazy[2*r] *= x;
			lazy[2*r+1] *= x;
		}
		return;
	}
	int mid = (i+j)/2;
	update(r*2, x, i, mid);
	update(r*2+1, x, mid+1, j);
	seg[r] = seg[2*r] * seg[2*r+1];
}

int main(void){
	memset(seg, 1, sizeof seg);
	memset(lazy, 1, sizeof lazy);

	scanf("%d%d", &n, &q);

	double p;
	for(int i = 1; i <= n; i++){
		scanf("%lf", &p);
		a = b = i;
		update(1, p, 1, n);
	}

	for(int i = 1; i <= n; i++){
		a = b = i;
		printf("%lf ", query(1, 1, n));
	}
	printf("\n");

	int tipo;
	double t;
	while(q--){
		scanf("%d", &tipo);
		
		if(tipo == 0){
			scanf("%d%d", &a, &b);
			double ans = 1.0 - query(1, 1, n);
			printf("%lf\n", ans);
		}
		else{
			scanf("%d%d%lf", &a, &b, &t);
			update(1, t, 1, n);
		}
	}

	return 0;
}