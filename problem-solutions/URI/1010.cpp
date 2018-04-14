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

int c1, c2, q1, q2;
double p1, p2;

int main(void){
	cin >> c1 >> q1 >> p1;
	cin >> c2 >> q2 >> p2;

	double ans1 = q1*p1;
	double ans2 = q2*p2;

	cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << ans1 + ans2 << endl;

	return 0;
}