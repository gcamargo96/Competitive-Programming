#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int n, d;
int v[N];

int main(void){
	fastcin;
	cin >> n >> d;

	set<int> s;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		s.insert(v[i]-d);
		s.insert(v[i]+d);
	}


	int ans = 0;
	for(int x : s){
		int mindist = INT_MAX;
		for(int i = 0; i < n; i++){
			mindist = min(mindist, abs(x-v[i]));
		}
		if(mindist == d){
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}