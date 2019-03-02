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

int n;
int a, b, c, d;

int main(void){
	scanf("%d", &n);

	a = b = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &c, &d);

		ans+=max(0,min(c,d)-max(a,b)+1);
		a=c;
		b=d;
		if (a==b){
			a++;
			b++;
		}
	}

	printf("%d\n", ans);

	return 0;
}	