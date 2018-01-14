#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define enld "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f

int n;
string s;
set<char> poke;
map<char,int> sub;

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> n;
	cin >> s;
	
	For(i,0,n){
		poke.insert(s[i]);
	}

	int j = 0;
	int menor = INF, l = 0, r = 0;
	For(i,0,n){
		if(j < i) j = i;
		while(sub.size() < poke.size() and j < n){
			sub[s[j]]++;
			j++;
		}
		//menor = min(menor, j-i+1);
		if(sub.size() == poke.size() and j-i < menor){
			menor = j-i;
			l = i+1;
			r = j+1;
		}
		sub[s[i]]--;
		if(sub[s[i]] == 0) sub.erase(s[i]);
	}

	cout << menor << endl;
	//cout << l << " " << r << endl;

	return 0;
}
