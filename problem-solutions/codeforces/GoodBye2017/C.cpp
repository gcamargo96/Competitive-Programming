#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 1002;
int n, r;
int X[N];
double Y[N];

int main(void){
	scanf("%d%d", &n, &r);

	for(int i = 0; i < n; i++){
		scanf("%d", &X[i]);
	}

	for(int i = 0; i < n; i++){
		double H = r;

		for(int j = 0; j < i; j++){
			if(abs(X[i]-X[j]) < 2*r){
				double h = sqrt(4*r*r - (X[i]-X[j])*(X[i]-X[j]));
				H = max(H, Y[j] + h);
			}
			if(abs(X[i]-X[j]) == 2*r){
				H = max(H, Y[j]);
			}
		}

		Y[i] = H;
	}

	for(int i = 0; i < n; i++){
		printf("%.10lf ", Y[i]);
	}
	printf("\n");

	return 0;
}