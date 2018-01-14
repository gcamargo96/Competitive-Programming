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

int n, x;
set<int> s;

int main(void){
	scanf("%d%d", &n, &x);

	int y;
	for(int i = 0; i < n; i++){
		scanf("%d", &y);
		s.insert(y);
	}

	int cnt = 0;
	for(int i = 0; i < x; i++){
		if(!s.count(i)){
			cnt++;
		}
	}

	// cout << cnt << endl;

	if(s.count(x)) cnt++;

	printf("%d\n", cnt);

	return 0;
}