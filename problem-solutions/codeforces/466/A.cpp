#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int n, d;
vector<int> v;;

int main(void){
	scanf("%d%d", &n, &d);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		v.pb(x);
	}

	sort(v.begin(), v.end());
	// v.resize(unique(v.begin(), v.end()) - v.begin());

	int ans = v.size();
	for(int i = 0; i < v.size(); i++){
		for(int j = i; j < v.size(); j++){
			if(v[j] - v[i] <= d){
				int aux = i + int(v.size())-j-1;
				ans = min(ans, aux);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}