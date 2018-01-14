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

set<int> s;

int main(void){
	For(i,0,5){
		s.insert(i);
	}

	for(auto it = s.begin(); it != s.end(); it++){
		printf("%d\n", *it);
		s.erase(it);
	}

	cout << s.size() << endl;

	return 0;
}

