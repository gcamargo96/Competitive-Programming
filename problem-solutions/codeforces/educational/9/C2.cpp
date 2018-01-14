#include <bits/stdc++.h>
using namespace std;

const int N = 50004;
int n;
string s[N];

int cmp(string s1, string s2){
	string a = s1 + s2;
	string b = s2 + s1;

	return a < b;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> s[i];
	}

	sort(s, s+n, cmp);

	for(int i = 0; i < n; i++){
		cout << s[i];
	}
	cout << endl;

	return 0;
}
