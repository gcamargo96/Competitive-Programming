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
int n;
double s;
int deg[N];

int main(void){
	scanf("%d%lf\n", &n, &s);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
	}

	int leafs = 0;
	for(int i = 1; i <= n; i++){
		if(deg[i] == 1) leafs++;
	}

	double ans = (2.0*s)/(double(leafs));
	printf("%.10lf\n", ans);

	return 0;
}