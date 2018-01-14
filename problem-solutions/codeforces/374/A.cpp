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

const int N = 102;
int n;
string s;
int v[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;

	int cnt = 0;
	int tam = 0;
	bool black = 0;

	For(i,0,n){
		if(s[i] == 'B'){
			tam++;
		}
		
		if(s[i] == 'B') black = 1;
		else{
			if(black) v[cnt++] = tam;
			black = 0;
			tam = 0;
		}
	}
	if(s[n-1] == 'B') v[cnt++] = tam;

	cout << cnt << endl;

	/*if(cnt == 0){
		cout << tam << endl;
		return 0;
	}*/

	For(i,0,cnt){
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}

