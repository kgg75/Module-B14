#include <iostream>
#include "Trie.h"

using namespace std;

// ���������� ����� ���� � ������� ������
TrieNode* getNewNode() {
    TrieNode* pNode = new TrieNode;    // �������� ������ ��� ����� ����
    pNode->isEndOfWord = false;    // ������������� ���� ����� ����� � false
    for (int i = 0; i < ALPHABET_SIZE; i++)    // �������������� ����� ������� ����������
        pNode->children[i] = nullptr;

    return pNode;
}


Trie::Trie() {
    root = getNewNode();
}


void Trie::insert(string key) {
    insert(root, key);
}


// ��������� ���� � ������, ���� ��� ���, 
// ����� ���� ���� ������� �������� ���� ������ 
// �������� � �������� �������� �.�. ����� �����
void Trie::insert(TrieNode* _pNode, string key) {
    //TrieNode* pNode = _pNode;

    if (_pNode == nullptr) {
        _pNode = getNewNode();
    }

    char index;
    for (int i = 0; i < key.length(); i++) {
        index = key[i] - 'a';   //����� ������ �� ������������ �����.
        if (_pNode->children[index] == nullptr) {    //���������, ��� ��� ��������� ���� � ����� ��������.
            _pNode->children[index] = getNewNode();
        }

        _pNode = _pNode->children[index];
        //��������� ���� �� ������� ������� ������� ����� ����.
        //��������� �������� ���� ������ ��������� ��������.
        //��������� � �. 1, ���� � ����� ���� �������.
    }
    _pNode->isEndOfWord = true;    //���������� ���� ����� ����� ��� ���������� ����.
}


// ������� ������ ������
void Trie::printTrie() {
    char buf[MAX_WORD_LEN] {0};
    printTrieInner(root, buf, 0);
}


// ���������� ������� ������ ������ ��� ������������ ������
void Trie::printTrieInner(TrieNode* _pNode, char buf[], int ind) {
    if (_pNode->isEndOfWord) {
        buf[ind] = 0;
        std::cout << buf << '\n';
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (_pNode->children[i] != nullptr) {
            buf[ind] = 'a' + (char)i;
            printTrieInner(_pNode->children[i], buf, ind + 1);
        }
    }
}


// ���������� ������� ������ ����� �� �������� ��� ������������ ������
void Trie::findWordByPrefixInner(TrieNode* root, char* _buf, int _index, char* _wordsList, int& _wordsLength) {
    if (root->isEndOfWord == true) {
        int i = 0;
        while (i < _index) {
            _wordsList[_wordsLength++] = _buf[i++];
        }
        _wordsList[_wordsLength++] = ',';
        _wordsList[_wordsLength++] = ' ';
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            _buf[_index] = 'a' + (char)i;
            findWordByPrefixInner(root->children[i], _buf, _index + 1, _wordsList, _wordsLength);
        }
    }
}


// ������� ������ ����� �� ��������
bool Trie::findWordByPrefix(const char* _pPrefix, char* _wordsList) {
    TrieNode* pNode = root;
    int i = 0, wordsLength;
    char chr;
    char buf[MAX_WORD_LEN] {0};

    while (_pPrefix[i] != 0) {   // ������� ������� ������ � ������������
        chr = _pPrefix[i];
        if (chr >= 'A' && chr <= 'Z')
            chr += 'a' - 'A';   // ����������� � ������ �������

        if (!(chr >= 'a' && chr <= 'z'))    // ������ ��� ����������� ���������, �����
            return false;

        if (pNode->children[chr - 'a'] == nullptr)    // ���� � ������� �������� �� ����������, �����
            return false;
        else
            pNode = pNode->children[chr - 'a'];

        buf[i++] = chr;
    }    

    findWordByPrefixInner(pNode, buf, i, _wordsList, wordsLength = 0);

    if (wordsLength != 0) {
        wordsLength -= 2;    // ������� ������� ', ' � �����
        _wordsList[wordsLength] = 0;
    }

    return wordsLength != 0;
}
