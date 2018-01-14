#include <bits/stdc++.h>
using namespace std;

int n, y;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int k = 1; k <= n; k++){
		stack <string> deck, hand;
		string s;
		y = 0;
		
		for(int i = 0; i < 52; i++){
				cin >> s;
				deck.push(s);
		}

		for(int l = 0; l < 3; l++){
			// colocando as 25 cartas do topo na mao
			for(int i = 0; i < 25; i++){
				s = deck.top();
				deck.pop();
				hand.push(s);
			}

			s = deck.top();
			deck.pop();
			
			int x;
			if(s[0] >= '2' and s[0] <= '9'){
				x = s[0] -'0';
			}
			else x = 10;

			y += x;

			for(int i = 0; i < 10-x; i++){
				deck.pop();
			}

			while(!hand.empty()){
				s = hand.top();
				hand.pop();
				deck.push(s);
			}
		}

		while(deck.size() > y){
			deck.pop();
		}
		s = deck.top();
		cout << "Case " << k << ": " << s << endl;
		
		while(!deck.empty()){
			deck.pop();
		}
	}

	return 0;
}
