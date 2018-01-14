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

int n;
string s;
int A, D;

int main(void){
	cin >> n;
	cin >> s;

	For(i,0,n){
		if(s[i] == 'A') A++;
		if(s[i] == 'D') D++;
	}

	if(A > D){
		cout << "Anton" << endl;
	}
	else if(A < D){
		cout << "Danik" << endl;
	}
	else cout << "Friendship" << endl;

	return 0;
}

