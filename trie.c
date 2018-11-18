#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
    unordered_map<char, TrieNode *> umap;
    bool isWord;
};

void trieInsert(TrieNode *root, string s) {
    for (char c : s) {
        if (root->umap.find(c) == root->umap.end())
            root->umap[c] = new TrieNode;
        root = root->umap[c];
    }
    root->isWord = true;
}

bool trieSearch(TrieNode *root, string s) {
    for (char c : s) {
        if (root->umap.find(c) == root->umap.end()) {
            cout << endl << "not found " << c;
            return false;
        }
        else { 
            cout << c;
            root = root->umap[c];
        }
    }
    if (root->isWord == true) {
        cout << endl << "found" << endl;
        return true;
    }
    else {
        cout << endl << "not found" << endl;
        return false;
    }
     
}

int main() {
    TrieNode *root = new TrieNode;
    trieInsert(root, "ab");
    trieSearch (root, "a");
    trieSearch (root, "ab");
    trieSearch (root, "abc");
    return 0;
}
    
    
