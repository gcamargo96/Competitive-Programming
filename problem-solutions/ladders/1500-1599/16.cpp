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

int a, b, c, d;
int p1, p2;

int main(void){
	cin >> a >> b >> c >> d;

	p1 = max((3*a)/10, a-(a/250)*c);
	p2 = max((3*b)/10, b-(b/250)*d);

	if(p1 > p2) cout << "Misha" << endl;
	else if(p1 < p2) cout << "Vasya" << endl;
	else cout << "Tie" << endl;

	return 0;
}

