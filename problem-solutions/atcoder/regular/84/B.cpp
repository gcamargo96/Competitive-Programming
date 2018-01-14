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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;
#define fastcin ios_base::sync_with_stdio(false)

int k;

int main(void){
	//fastcin;
	scanf("%d", &k);

	int ans = 1000000000;
	for(ll i = 1; i <= 100000; i++){
		int sum = 0;
		ll aux = k*i;
		while(aux > 0){
			sum += aux%10;
			aux /= 10;
		}
		// printf("%d ", k*i);
		ans = min(ans, sum);
	}
	// printf("\n");

	printf("%d\n", ans);

	return 0;
}