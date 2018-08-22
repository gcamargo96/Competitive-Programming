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

#define MAXBIT 30

const int N = 100005;
int n, m;
int l[N], r[N], q[N], v[N];
int seg[4*N];
int a, b;
int s[32][N];

void build(int r, int i, int j){
	// printf("r = %d\n", r);
	if(i == j){
		seg[r] = v[i];
	}
	else{
		int mid = (i+j)/2;
		build(2*r, i, mid);
		build(2*r+1, mid+1, j);
		seg[r] = (seg[2*r] & seg[2*r+1]);
	}
}

int query(int r, int i, int j){
	if(i >= a and j <= b){
		return seg[r];
	}
	if(j < a or i > b){
		return (1<<MAXBIT)-1;
	}
	int mid = (i+j)/2;
	int L = query(2*r, i, mid);
	int R = query(2*r+1, mid+1, j);
	return (L & R);
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &l[i], &r[i], &q[i]);
	}

	for(int i = 0; i < MAXBIT; i++){
		for(int j = 0; j < m; j++){
			if((q[j]>>i) & 1){
				s[i][l[j]]++;
				s[i][r[j]+1]--;
			}
		}

		for(int j = 1; j <= n; j++){
			s[i][j] += s[i][j-1];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < MAXBIT; j++){
			if(s[j][i] > 0){
				v[i] |= (1<<j);
			}
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", v[i]);
	// }
	// printf("\n");

	// return 0;

	build(1, 1, n);

	// for(int i = 1; i <= n; i++){
	// 	a = b = i;
	// 	printf("%d ", query(1,1,n));
	// }
	// printf("\n");

	// return 0;

	for(int i = 0; i < m; i++){
		a = l[i], b = r[i];
		int ans = query(1, 1, n);
		
		if(ans != q[i]){
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for(int i = 1; i <= n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}