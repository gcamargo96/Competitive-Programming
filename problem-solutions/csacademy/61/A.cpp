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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

double C;

int main(void){
	scanf("%lf", &C);

	double F = C * (9.0/5.0) + 32;

	// printf("F = %lf\n", F);
	
	int ans;
	if(F >= 0){
		ans = (int) floor(F);
	}
	else{
		ans = (int) ceil(F);
	}

	printf("%d\n", ans);

	return 0;
}