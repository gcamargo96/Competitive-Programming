#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int n, m, p;
string op;
list<char> lista;

int main(void){
	scanf("%d%d%d", &n, &m, &p);

	char c;
	for(int i = 0; i < n; i++){
		scanf(" %c", &c);
		lista.pb(c);
	}
	
	cin >> op;

	list<char>::iterator it = lista.begin();
	int cnt = 1;
	while(cnt < p){
		it++;
		cnt++;
	}

	for(int i = 0; i < m; i++){
		if(op[i] == 'L') it--;
		if(op[i] == 'R') it++;
		if(op[i] == 'D'){
			int cont = 1;
			if(*it == '('){
				it = lista.erase(it);
				//it++;
				while(cont > 0){
					if(*it == '(') cont++;
					if(*it == ')') cont--;
					it = lista.erase(it);
					//it++;
				}
				if(it == lista.end()) it--;
			}
			else if(*it == ')'){
				it = lista.erase(it);
				it--;
				while(cont > 0){
					if(*it == ')') cont++;
					if(*it == '(') cont--;
					it = lista.erase(it);
					it--;
				}
				it++;
				if(it == lista.end()) it--;
			}
		}
	}

	for(list<char>::iterator i = lista.begin(); i != lista.end(); i++){
		printf("%c", *i);
	}
	printf("\n");

	return 0;
}
