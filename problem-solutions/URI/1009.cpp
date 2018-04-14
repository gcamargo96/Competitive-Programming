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

string nome;
double sal, mon;

int main(void){
	getline(cin, nome);
	cin >> sal >> mon;

	double tot = sal + 0.15*mon;
	cout << "TOTAL = R$ " << fixed << setprecision(2) << tot << endl;

	return 0;
}