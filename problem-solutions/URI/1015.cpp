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
#define fastcin ios_base::sYnc_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

double X1, Y1, X2, Y2;

int main(void){
	cin >> X1 >> Y1 >> X2 >> Y2;

	double ans = sqrt((X2-X1)*(X2-X1) + (Y2-Y1)*(Y2-Y1));
	cout << fixed << setprecision(4) << ans << endl;

	return 0;
}