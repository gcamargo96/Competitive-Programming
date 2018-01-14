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

const int N = 370;
int n;
int suml[N], sumr[N];

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		v.pb(x);
	}

	for(int i = 0; i < n; i++){
		v.pb(v[i]);
	}

	for(int i = 0; i < n; i++){
		suml[0] v[i];
		for(int j = i+1; j < i+n; j++){
			suml[j-i] = suml[j-i-1] + v[j];
		}
		sumr[n] = 0;
		for(int j = i+n-1; j >= i; j--){
			sumr[j-i] = sumr[j-i-1] + v[j];
		}

		for(int j = i; j < i+n; j++){
			
		}
	}

	return 0;
}