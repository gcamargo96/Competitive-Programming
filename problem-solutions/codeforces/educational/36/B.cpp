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

int n, pos, l, r;

int main(void){
	fastcin;
	cin >> n >> pos >> l >> r;

	if(l == 1 and r == n){
		cout << 0 << endl;
		return 0;
	}

	int a = 1, b = n;

	if(l == a){
		cout << abs(r-pos)+1 << endl;
	}
	else if(r == b){
		cout << abs(pos-l)+1 << endl;
	}
	else{
		int ans1 = 0, ans2 = 0;
		ans1 = abs(r-pos)+1 + abs(r-l)+1;
		ans2 = abs(pos-l)+1 + abs(r-l)+1;

		cout << min(ans1, ans2) << endl;
	}

	return 0;
}