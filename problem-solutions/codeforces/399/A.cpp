#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
set<int> s;
int v[N], n;

int main(void){
	scanf("%d", &n);

	int x;
	For(i,0,n){
		scanf("%d", &v[i]);
		s.insert(v[i]);
	}

	int res = 0;
	For(i,0,n){
		auto it = s.lower_bound(v[i]);
		//if(it != s.begin()) it--;
		//else continue;
		if(it != s.begin() and it != s.end()){
			it++;
			if(it != s.end())
				res++;
		}
	}

	cout << res<< endl;

	return 0;
}

