#pragma once
#include <string>

const int ALPHABET_SIZE = 26;
const int MAX_WORD_LEN = 20;
const int WORDS_COUNT = 15;


struct TrieNode {
	/*struct*/ TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;	// isEndOfWord - true, если ключ является концом слова
};


class Trie {
	private:
		TrieNode* root;
		void printTrieInner(TrieNode* _pNode, char buf[], int ind);
		void findWordByPrefixInner(TrieNode* root, char* _buf, int _index, char* _wordsList, int& _wordsLength);
	public:
		Trie();
		void insert(std::string key);
		void insert(TrieNode* _pNode, std::string key);
		void printTrie();
		bool findWordByPrefix(const char* _pPrefix, char* _wordsList);
};

TrieNode* getNewNode();