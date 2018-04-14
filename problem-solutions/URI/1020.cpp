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

ll n;
ll a, m, d;

int main(void){
	cin >> n;

	a = n/365LL;
	n -= a*365LL;

	m = n/30LL;
	n -= m*30LL;

	d = n;

	cout << a << " ano(s)" << endl;
	cout << m << " mes(es)" << endl;
	cout << d << " dia(s)" << endl;

	return 0;
}