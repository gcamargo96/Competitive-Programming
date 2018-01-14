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

struct s{
	int fi, se, th;
};

const int N = 200002;
int n;
s a[N], b[N];

bool cmp1(s a, s b){
	return a.fi < b.fi;
}

bool cmp2(s a, s b){
	return a.th < b.th;
}

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}

	For(i,0,n){
		scanf("%d", &b[i].fi);
		b[i].se = i;
	}

	sort(a, a+n, cmp1);
	sort(b, b+n, cmp1);
	reverse(b, b+n);

	For(i,0,n){
		a[i].th = b[i].se; 
	}

	sort(a, a+n, cmp2);

	For(i,0,n){
		printf("%d ", a[i].fi);
	}
	printf("\n");

	return 0;
}