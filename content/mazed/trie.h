/**
 * Author: Mazed
 * Source:
 * Description: Trie implementation using pointers.
 * Usage:
 * Time: 
 */
 
const int alphabet_size = 26;

struct TrieNode{
    char dat;
    TrieNode* children[alphabet_size];
    int endCount;

    TrieNode(char ch){
        dat = ch;
        for(int i=0; i<alphabet_size; i++){
            children[i] = NULL;
        }
        endCount = 0;
    }
};

struct Trie{ /// Trie *t = new Trie();
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string &word, int i){
        if(i==word.size()){
            root->endCount++;
            return;
        }

        int index = word[i]-'a'; /// assume word are in lower case;
        TrieNode* child;

        if(root->children[index] != NULL){ /// present
            child = root->children[index];
        }
        else{ /// absent
            child = new TrieNode(word[i]);
            root->children[index] = child;
        }

        insertUtil(child, word, i+1);
    }

    void insertWrod(string word){
        insertUtil(root, word, 0);
    }

    int searchUtil(TrieNode* root, string &word, int i){
        if(i==word.size()){
            return root->endCount;
        }

        int index = word[i]-'a'; /// assume word are in lower case;
        TrieNode* child;

        if(root->children[index] != NULL){ /// present
            child = root->children[index];
        }
        else{ /// absent
            return 0;
        }

        return searchUtil(child, word, i+1);

    }

    int searchWord(string word){
        return searchUtil(root, word, 0);
    }
};
