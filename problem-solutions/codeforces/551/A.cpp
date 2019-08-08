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

#define INF 0x3f3f3f3f

int n, t;
int s, d;

int main(void){
	scanf("%d%d", &n, &t);

	int ans = 1, minute = INF;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &s, &d);

		while(s < t){
			s += d;
		}

		if(s < minute){
			ans = i;
			minute = s;
		}
	}

	printf("%d\n", ans);

	return 0;
}