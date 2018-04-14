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

double a, b, c;

int main(void){
	cin >> a >> b >> c;

	double delta = b*b - 4*a*c;

	if(delta < 0){
		cout << "Impossivel calcular" << endl;
	}
	else if(a == 0){
		cout << "Impossivel calcular" << endl;
	}
	else{
		double x1 = (-b - sqrt(delta))/(2.0*a);
		double x2 = (-b + sqrt(delta))/(2.0*a);
	
		cout << fixed << setprecision(5) << "R1 = " << x2 << endl;
		cout << fixed << setprecision(5) << "R2 = " << x1 << endl;
	}

	return 0;
}