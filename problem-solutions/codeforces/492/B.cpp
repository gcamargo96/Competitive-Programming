#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100005;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	int minvoltas = 0x3f3f3f3f, ans = 1;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);

		int voltas = (v[i]-i + n-1)/n;
		if(voltas < 0) voltas = 0;

		if(voltas < minvoltas){
			minvoltas = voltas;
			ans = i+1;
		}
	}

	printf("%d\n", ans);

	return 0;
}