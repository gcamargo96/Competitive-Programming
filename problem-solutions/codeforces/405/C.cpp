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

const int N = 52;
int n, k;
bool ok[N];
vector<string> bib;
int res[N];

void gera(){
	For(i,0,26){
		string aux;
		aux += (char)(i+'A');
		bib.pb(aux);
	}

	For(i,0,26){
		For(j,0,26){
			string aux;
			aux += (char)(i+'A');
			aux += (char(j+'a'));
			bib.pb(aux);
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	gera();
	memset(res, -1, sizeof res);
	
	cin >> n >> k;

	string s;
	for(int i = 1; i <= n-k+1; i++){
		cin >> s;
		if(s == "YES") ok[i] = 1;
		else ok[i] = 0;
	}

	int cur = 0;
	for(int i = 1; i <= n-k+1; i++){
		if(ok[i] == 0){
			if(res[i] == -1){
				res[i] = cur;
				res[i+k-1] = cur;
				cur++;
			}
			else{
				res[i+k-1] = res[i];
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(res[i] == -1) res[i] = cur++;
	}

	for(int i = 1; i <= n; i++){
		cout << bib[res[i]] << " ";
	}
	cout << endl;

	return 0;
}

