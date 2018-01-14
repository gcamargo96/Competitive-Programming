#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

string s, t;
int cnts[28], cntt[28];

bool contem(){
	int i = 0, j = 0;
	
	while(i < t.size() and j < s.size()){
		if(t[i] == s[j]){
			i++;
		}
		j++;
	}

	if(i == t.size()) return 1;
	return 0;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s >> t;

	For(i,0,s.size()){
		cnts[s[i]-'a']++;
	}

	For(i,0,t.size()){
		cntt[t[i]-'a']++;
	}

	bool tem_todas = 1;
	For(i,0,26){
		if(cnts[i] < cntt[i]){
			tem_todas = 0;
			break;
		}
	}

	//if(tem_todas) printf("tem todas\n");

	if(tem_todas and contem()){
		//printf("automaton\n");
		cout << "automaton" << endl;
	}
	else if(tem_todas and s.size() == t.size()){
		//printf("array\n");
		cout << "array" << endl;
	}
	else if(tem_todas){
		//printf("both\n");
		cout << "both" << endl;
	}
	else{
		//printf("need tree\n");
		cout << "need tree" << endl;
	}

	return 0;
}
