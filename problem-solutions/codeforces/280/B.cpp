#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 1002;
int n, l;
double v[N];


int main(void){
	scanf("%d%d", &n, &l);

	For(i,0,n){
		scanf("%lf", &v[i]);
	}

	sort(v, v+n);
	/*For(i,0,n){
		printf("%lf ", v[i]);
	}
	cout << endl;
	*/
	double res = v[0];

	For(i,0,n-1){
		res = max(res, (v[i+1] - v[i])/2.0);
	}

	res = max(res, (double)l - v[n-1]);

	printf("%.9lf\n", res);

	return 0;
}

