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
ll h, m, s;

int main(void){
	cin >> n;

	h = n/(60LL*60LL);
	n -= h*60LL*60LL;

	m = n/60;
	n -= m*60;

	s = n;

	cout << h << ":" << m << ":" << s << endl;

	return 0;
}