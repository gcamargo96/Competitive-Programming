#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
int n;
set<int> s;

int main(void){
	scanf("%d", &n);

	int a;
	For(i,0,n){
		scanf("%d", &a);
		s.insert(a);
	}

	if(s.size() <= 2){
		printf("YES\n");
	}
	else if(s.size() == 3){
		int d1, d2;
		auto it = s.begin();
		auto it1 = it;
		auto it2 = ++it;
		auto it3 = ++it;

		d1 = *it2 - *it1;
		d2 = *it3 - *it2;

		if(d1 == d2) printf("YES\n");
		else printf("NO\n");
	}
	else printf("NO\n");

	return 0;
}
