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

const int N = 100005;
ll n, k, m;
int v[N];
ll sum[N];

int main(void){
	scanf("%lld%lld%lld", &n, &k, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	sort(v, v+n);

	for(int i = n-1; i >= 0; i--){
		sum[i] = sum[i+1] + v[i];
	}

	double ans = 0;
	for(int i = 0; i < n and m-i >= 0; i++){
		ans = max(ans, (sum[i] + min(k*(n-i), m-i))/double(n-i));
	}

	printf("%.10lf\n", ans);

	// if(m >= n){
	// 	int cnt = m-(n-1);
	// 	int avg = v[n-1] + min(k, cnt);
	// 	printf("%d\n", avg);
	// }
	// else{
	// 	for(int i = 0; i < n-1 and m-i > 0; i++){
	// 		double avg1 = double(sum[i] + m-i)/double(n-i); // keeps current value
	// 		double avg2 = double(sum[i+1] + m-i-1)/double(n-i-1); // remove current value
		
	// 		if(avg1 > avg2){
	// 			printf("%.10lf\n", avg1);
	// 			return 0;
	// 		}

	// 		if(m-i == 0){
	// 			printf("%.10lf\n", avg2);
	// 			return 0;
	// 		}
	// 	}
	// }

	return 0;
}