#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 100002;
int n;
double p;
double a[N], b[N];

int main(void){
	scanf("%d%lf", &n, &p);

	int neg = 0, zero = 0, id1 = 0, id2 = 0;
	double menor = 1000000000000.0, 2menor = 1000000000000;
	For(i,0,n){
		scanf("%lf%lf", &a[i], &b[i]);
		if(p-a[i] < 0) neg = 1;
		if(p-a[i] == 0) zero = 0;
		double temp = b[i]/a[i];
		if(temp < menor){
			id2 = id1;
			id1 = i;

			2menor = menor;
			menor = temp;
		}
	}

	if(neg == 0){
		printf("-1\n");
		return 0;
	}

	

	return 0;
}

