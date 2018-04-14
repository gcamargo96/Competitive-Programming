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

double v[10];

int id, cnt;

int main(void){
	v[1] = 4;
	v[2] = 4.5;
	v[3] = 5;
	v[4] = 2;
	v[5] = 1.5;


	cin >> id >> cnt;
	cout << "Total: R$ " << fixed << setprecision(2) << v[id]*cnt << endl;

	return 0;
}