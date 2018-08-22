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

const int N = 18;
int n;
int v[N];

int main(void){
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v, v+n);

	int turn = 0;
	int ans[2] = {0,0};
	for(int i = n-1; i >= 0; i--){
		ans[turn] += v[i];
		turn = !turn;
	}

	cout << ans[0] << " " << ans[1] << endl;

	return 0;
}