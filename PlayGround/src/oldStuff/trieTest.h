#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

struct Node {
    Node* children[26];
    bool endOfWord = false;
};

void insert(Node *root, string insertWord, int wordIndex = 0){
    if(wordIndex == insertWord.size()){
        root->endOfWord = true;
        return;
    }
    if(!root->children[insertWord[wordIndex] - 'a']){
        root->children[insertWord[wordIndex] - 'a'] = new Node();
    }
    insert(root->children[insertWord[wordIndex] - 'a'], insertWord, wordIndex + 1);
}

bool wordPresent(Node *root, string searchWord, int wordIndex = 0){
    if(wordIndex == searchWord.size() && root->endOfWord){
        return true;
    }
    if(!root->children[searchWord[wordIndex] - 'a']){
        return false;
    }
    return wordPresent(root->children[searchWord[wordIndex] - 'a'], searchWord, wordIndex + 1);
}

void printTrie(Node* root, char character, int depth){
    cout << character;
    for(int i = 0; i < 26; ++i){
        if(root->children[i]){
            printTrie(root->children[i], (char)(i + 'a'), depth + 1);
        }
    }
}

/* Input
 *
 * add hack
 * add hackerrank
 * find hac
 * find hak
 */
void testTrie(){
    auto *root = new Node();
    bool flag = true;
    while(flag){
        string cmd, input;
        cin >> cmd;
        if(cmd == "end"){
            flag = false;
        }else if(cmd == "add"){
            cin >> input;
            insert(root, input, 0);
        }else if(cmd == "find"){
            cin >> input;
            cout << (wordPresent(root, input, 0) ? "Word \'" + input + "\' is present" : "Word \'" + input + "\' is NOT present" )<< "\n";
        }else if(cmd == "print"){
            printTrie(root, '*', 0);
        }

    }
}
