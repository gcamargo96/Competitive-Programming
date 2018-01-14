#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 102;
int n, d;

int main(void){
	scanf("%d%d", &n, &d);

	int sum = 0, tem = 0;
	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		tem += x;
		int add = min(tem, 8);
		tem -= add;
		sum += add;
		if(sum >= d){
			printf("%d\n", i);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}