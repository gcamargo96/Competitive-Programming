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

const int N = 50005;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	int sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		sum += v[i];
	}

	sort(v, v+n);

	int ans = sum;
	for(int i = 2; i*i <= v[0]; i++){
		if(v[0]%i == 0){
			int j = v[0]/i;
			ans = min(ans, sum - v[0] - v[1] + v[0]/i + v[1]*i);
			ans = min(ans, sum - v[0] - v[1] + v[0]/j + v[1]*j);
		}
	}

	for(int i = 1; i < n; i++){
		for(int d = 2; d*d <= v[i]; d++){
			if(v[i]%d == 0){
				int a = d, b = v[i]/d;
				ans = min(ans, sum - v[0] - v[i] + v[i]/a + v[0]*a);
				ans = min(ans, sum - v[0] - v[i] + v[i]/b + v[0]*b);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}