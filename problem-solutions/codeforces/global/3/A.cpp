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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int a, b, c;

int main(void){
	cin >> a >> b >> c;

	int ans1 = 2*c + 2*min(a,b) + (a > b ? 1 : 0);
	int ans2 = 2*c + (b > a ? 1 : 0) + 2*min(a,b);

	cout << min(ans1, ans2) << endl;

	return 0;
}