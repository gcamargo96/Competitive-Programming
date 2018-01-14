#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 102;
int n, k;
double v[N];

int main(void){
	scanf("%d%d", &n, &k);

	double sum; int cnt = n;
	For(i,0,n){
		scanf("%lf", &v[i]);
		sum += v[i];
	}

	int add = 0;
	while(round(sum/(double)cnt) < k){
		int i = 1;
		for(i = 1; i < k and round((sum+i)/(double)(cnt+1)) < k; i++){
			
		}
		cnt++;
		add++;
		sum += i;
	}

	printf("%d\n", add);

	return 0;
}

