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

const int N = 2002;
int n;
int v[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void){
	scanf("%d", &n);

	int not1 = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		if(v[i] != 1) not1++;
	}

	if(n == 1){
		if(v[0] == 1){
			printf("0\n");
		}
		else{
			printf("-1\n");
		}
		return 0;
	}

	int g = v[0];
	for(int i = 1; i < n; i++){
		g = gcd(g, v[i]);
	}

	if(g != 1){
		printf("-1\n");
	}
	else{
		int mindist = 100000;
		for(int i = 0; i < n; i++){
			g = v[i];
			for(int j = i+1; j < n; j++){
				g = gcd(g, v[j]);
				if(g == 1){
					mindist = min(mindist, j-i);
				}
			}
		}

		int ans = mindist + not1-1;
		printf("%d\n", ans);
	}

	return 0;
}