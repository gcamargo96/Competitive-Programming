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

const int N = 50002;
string s, t;
int p[2*N]; 

// prefix function will be 1-based
void prefix_function(string& s){
	int n = s.size();
	for(int i = 2; i <= n; i++){
		p[i] = p[i-1];
		while(p[i] > 0 and s[p[i]] != s[i-1])
			p[i] = p[p[i]];
		if(s[p[i]] == s[i-1])
			p[i]++;
	}
}

void kmp(string& s, string& t){
	int n = t.size(), k = 0;
	for(int i = 0; i < n; i++){
		if(k == s.size()){
			cout << "matching on position " << i << endl;
		}
		while(k > 0 and s[k] != t[i])
			k = p[k];
		if(s[k] == t[i])
			k++;
	}
}

int main(void){
	cin >> s >> t;

	prefix_function(s);
	kmp(s, t);

	return 0;
}