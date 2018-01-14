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

const int N = 100002;
int a[N];
int b[N];
int v[N];
int n;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	bool allequals = 1;
	int maxa = -1, maxb = -1;
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			allequals = 0;
		}
		maxa = max(maxa, a[i]);
		maxb = max(maxb, b[i]);
	}

	if(allequals){
		printf("%d\n", maxa+1);
		return 0;
	}

	bool neg = 0;
	for(int i = 0; i < n; i++){
		v[i] = a[i] - b[i];

		if(v[i] < 0){
			neg = 1;
		}
	}

	if(neg){
		printf("-1\n");
		return 0;
	}

	int g = v[0];
	for(int i = 1; i < n; i++){
		g = gcd(g, v[i]);
	}

	int sqr = sqrt(g)+1;
	vi divs;
	for(int i = 1; i <= sqr; i++){
		if(g%i == 0){
			divs.pb(i);
			divs.pb(g/i);
		}
	}

	int ans = 1e9 + 5;
	for(int i = 0; i < divs.size(); i++){
		// printf("%d ", divs[i]);
		if(divs[i] < ans and divs[i] > maxb){
			ans = divs[i];
		}
	}

	if(ans != 1e9+5){
		printf("%d\n", ans);
	}
	else{
		printf("-1\n");
	}

	return 0;
}