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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, m, r, k;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
priority_queue<pair<double, ii> > pq;
set<ii> vis;

double calc(ii cur){
	int i = cur.fi, j = cur.se;
	double a = min(min(i+1, n-i), min(r, n-r+1));
	double b = min(min(j+1, m-j), min(r, m-r+1));
	return a*b;
}

bool check(ii cur){
	int i = cur.fi, j = cur.se;
	if(i >= 0 and i <= n-1 and j >= 0 and j <= m-1);
		return 1;
	return 0;
}

int main(void){
	scanf("%d%d%d%d", &n, &m, &r, &k);

	ii cur;
	cur.fi = (n-1)/2;
	cur.se = (m-1)/2;
	pq.push(mp(calc(cur), cur));

	double sum = 0;
	while(k--){
		double val = pq.top().fi;
		ii cur = pq.top().se;
		sum += val;
		vis.insert(cur);
		pq.pop();

		for(int i = 0; i < 4; i++){
			ii nxt;
			nxt.fi = cur.fi + dir[i][0];
			nxt.se = cur.se + dir[i][1];

			if(check(nxt) and !vis.count(nxt)){
				pq.push(mp(calc(nxt), nxt));
				vis.insert(nxt);
			}
		}
	}

	double prob = double(n-r+1) * double(m-r+1);
	double ans = sum/prob;

	printf("%.10lf\n", ans);

	return 0;
}