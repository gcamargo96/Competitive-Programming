#include <bits/stdc++.h>
using namespace std;


struct node{
	node* p;
	node* nxt[27];
	bool end;
	// node *sl; // suffix length
	int c;
	node() : c(0), end(false) , p(NULL){
		memset(nxt, 0, sizeof nxt);
	}

};
typedef node* trie;

trie root = new node();

void add(const string& s){
	trie t = root;
	for(int i = 0; i < s.size(); i++){
		char c = s[i];
		int v = c-'a';
		if(!t->nxt[v]){
			trie son = new node();
			son->c = v;
			son->p = t;
			t->nxt[v] = son;
		}
		t = t->nxt[v];
		if(i == s.size()-1){
			t->end = true;
		}
	}
}

bool search(const string& s){
	trie t = root;
	for(int i = 0; i < s.size(); i++){
		char c = s[i];
		int v = c-'a';
		if(!t->nxt[v]) return false;
		t = t->nxt[v];
	}
	if(t->end) return true;
	return false;
}

void ok(const string& s){
	cout << "OK" << " " << s << endl;
}

int main(void){
	add("abcd");
	add("abcde");
	add("asdf");

	if(search("abcd")) ok("abcd");
	if(search("abcde")) ok("abcde");
	if(search("asdf")) ok("asdf");
	if(!search("test")) ok("!test");

	return 0;
}
