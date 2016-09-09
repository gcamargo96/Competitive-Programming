#include <bits/stdc++.h>
using namespace std;

struct Trie{
    bool hasWord;

    map<char,Trie> adj;

    Trie(){
        hasWord = false;
        adj.clear();
    }

    void insert(string& s, int i){
        if(i == s.size()){
            hasWord = true;
        }else{
            adj[s[i]].insert(s, i+1);
        }
    }

    bool search(string& s, int i){
        if(i == s.size()){
            return hasWord;
        }else{
            if(hasWord) return true;

            /*if(!adj.count(s[i])){
                if(hasWord) return true;
                return false;
            }*/
            //if(hasWord) return true;
        return adj[s[i]].search(s, i+1);
        }
    }
};

Trie tr;
string s;

int main(void){
    while(cin >> s){
        if(tr.search(s, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
        tr.insert(s, 0);
    }

    return 0;
}