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

int n;

int main(void){
	scanf("%d", &n);

	int ans = 0;
	for(int l = 1; l < n; l++){
		if((n-l)%l == 0 and (n-l)/l > 0){
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}