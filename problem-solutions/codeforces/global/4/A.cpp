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

const int N = 205;
int n;
int v[N];
int total = 0, coa = 0;

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		total += v[i];
	}

	coa = v[1];

	vi ans;
	ans.pb(1);

	for(int i = 2; i <= n; i++){
		if(2*v[i] <= v[1]){
			coa += v[i];
			ans.pb(i);
		}
	}

	if(coa > total-coa){
		printf("%d\n", (int)ans.size());
		for(int i = 0; i < ans.size(); i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else{
		printf("0\n");
	}

	return 0;
}