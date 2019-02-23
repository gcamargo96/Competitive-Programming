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

double n, r;

int main(void){
	scanf("%lf%lf", &n, &r);

	double ang = PI/n;
	double sn = sin(ang);
	double R = (r*sn)/(1.0-sn);

	printf("%.10lf\n", abs(R));

	return 0;
}