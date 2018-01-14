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

const int N = 52;
double s;
int q, k;
double p[N];

int main(void){
	scanf("%lf %d %d", &s, &q, &k);

	for(int i = 0; i < q; i++){
		scanf("%lf", &p[i]);
		p[i] /= 100.0;
	}

	sort(p, p+q);

	for(int i = 0; i < q; i++){
		if(s+k >= s + s*p[i]){
			s += k;
		}
		else{
			s += s*p[i];
		}
	}

	printf("%lf\n", s);

	return 0;
}