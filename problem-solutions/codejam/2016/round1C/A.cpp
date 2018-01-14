#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int t, n;
map<int,char> m;

bool valid(){
	map<int, char>::iterator it1 = m.end();
	it1--;
	int hi = it1->first;
   	int cnt = 0;
	
	for(map<int,char>::iterator it = m.begin(); it != m.end(); it++){
		if(it->first == hi) cnt++;
		printf("%c -> %d\n", it->first, it->second);
	}

	if(cnt > 1) return 1;
	return 0;
}

void solve(){
	int cnt = 0;
	map<int, char>::iterator it = m.end();
	it--;
	while(cnt < 2 and it != m.begin()){
		if(cnt == 1 and valid()) break;
		printf("%c ", it->second);
		it->first--;
		if(it->first == 0) m.erase(it);
		cnt++;
		it--;
	}
}

/*void solve(){
	map<char,int> aux = m;
	(aux.end() - 2)->second--;
	(aux.end() - 1)->second--;
	if(valid(aux)){
		printf("%c %c\n", (m.end()- 2 )->first, (m.end() - 1)->first);
		(m.end() - 2)->second--;
		(m.end() - 1)->second--;
	}
	else{
		printf("%c %c\n", (m.end() - 1)->first);
		(m.end() - 1)->second--;
	}

	for(map<char,int>::iterator it = m.begin(); it != it.end(); it++){
		if(it->second == 0){
			m.erase(it);
		}
	}
}*/

int main(void){
	scanf("%d", &t);

	for(int k = 1; k <= t; k++){
		m.clear();
		scanf("%d", &n);

		int val;
		char letra = 'A';
		for(int i = 0; i < n; i++){
			scanf("%d", &val);
			m[val] = letra;
			letra++;
		}

		printf("Case #%d: ", k);
		solve();
	}

	return 0;
}
