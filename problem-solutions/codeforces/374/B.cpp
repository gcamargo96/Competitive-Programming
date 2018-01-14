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
//string s[N];
string s;
string pw;
int tam[N];
int n, k;

bool cmp(string a, string b){
	return a.size() < b.size();
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	For(i,0,n){
		cin >> s;
		tam[i] = s.size();
	}
	cin >> pw;

	sort(tam, tam+n);

	int menor = lower_bound(tam, tam+n, pw.size()) - tam + 1;
	int maior = upper_bound(tam, tam+n, pw.size()) - tam;

	int res1 = menor + 5*(menor/k);
	if(menor%k == 0) res1 -= 5;

	int res2 = maior + 5*(maior/k);
	if(maior%k == 0) res2 -= 5;

	cout << res1 << " " << res2 << endl;

	return 0;
}

