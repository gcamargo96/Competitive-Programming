#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

string s;
int n;

bool cmp(char a, char b){
	return a > b;
}

int main(void){
	fastcin;
	cin >> s;
	n = s.size();

	for(int i = 0; i < n;){
		if(s[i] == '2'){
			i++;
			continue;
		}

		int j = i;
		while(j < n and (s[j] == '0' or s[j] == '1')){
			j++;
		}
		sort(s.begin()+i, s.begin()+j, cmp);
		i = j;
	}

	for(int i = 0; i < n;){
		if(s[i] == '0'){
			i++;
			continue;
		}

		int j = i;
		while(j < n and (s[j] == '1' or s[j] == '2')){
			j++;
		}
		sort(s.begin()+i, s.begin()+j);
		i = j;
	}

	for(int i = 0; i < n;){
		if(s[i] == '2'){
			i++;
			continue;
		}

		int j = i;
		while(j < n and (s[j] == '0' or s[j] == '1')){
			j++;
		}
		sort(s.begin()+i, s.begin()+j);
		i = j;
	}

	cout << s << endl;

	return 0;
}