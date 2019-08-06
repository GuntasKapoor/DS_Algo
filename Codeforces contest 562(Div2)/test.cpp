// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;



// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
    public :
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

    public :
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            if (!root->isTerminal) {
                root -> isTerminal = true;
                return true;    
            } else {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    void autoCompletehelper(TrieNode* root, string pattern, string output){
        
        if(pattern.length() == 0){
            if(root->isTerminal){
                cout<<output<<endl;
            }
            for(int i = 0; i < 26; i++){
                if(root->children[i] != NULL){
                    autoCompletehelper(root->children[i], pattern, output + root->children[i]->data);
                }
            }
            return;
        }
        else{
            int index = pattern[0] - 'a';
            TrieNode * child = root->children[index];
            if(child!=NULL){
                autoCompletehelper(child, pattern.substr(1),output);
            }
            else{
                return;
            }
        }
        
    }
    
    void autoComplete(vector<string> input, string pattern) {
        for(int i = 0; i < input.size(); i++){
            string a = input[i];
            insertWord(a);
        }
        
        autoCompletehelper(root, pattern,pattern);
    }
    
    
    

};








int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);


Trie t;
vector<string> input;
int N;
cin>>N;
for(int i = 0; i < N; i++){
    string a;
    cin>>a;
    input.push_back(a);
}
string pattern;
cin>>pattern;
t.autoComplete(input, pattern);

}