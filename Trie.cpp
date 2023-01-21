#include <iostream>
#include "Trie.h"

using namespace std;

// Возвращает новый узел с пустыми детьми
TrieNode* getNewNode() {
    TrieNode* pNode = new TrieNode;    // Выделяем память под новый узел
    pNode->isEndOfWord = false;    // устанавливаем флаг конца слова в false
    for (int i = 0; i < ALPHABET_SIZE; i++)    // инициализируем детей нулевым указателем
        pNode->children[i] = nullptr;

    return pNode;
}


Trie::Trie() {
    root = getNewNode();
}


void Trie::insert(string key) {
    insert(root, key);
}


// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префксом узла дерева 
// помечает в качестве литового т.е. конец слова
void Trie::insert(TrieNode* _pNode, string key) {
    //TrieNode* pNode = _pNode;

    if (_pNode == nullptr) {
        _pNode = getNewNode();
    }

    char index;
    for (int i = 0; i < key.length(); i++) {
        index = key[i] - 'a';   //Взять символ от вставляемого ключа.
        if (_pNode->children[index] == nullptr) {    //Проверить, что нет дочернего узла с таким символом.
            _pNode->children[index] = getNewNode();
        }

        _pNode = _pNode->children[index];
        //Присвоить узлу по индексу взятого символа новый узел.
        //Присвоить текущему узлу только созданный дочерний.
        //Повторять с п. 1, пока в ключе есть символы.
    }
    _pNode->isEndOfWord = true;    //Установить флаг конца слова для последнего узла.
}


// функция печать дерева
void Trie::printTrie() {
    char buf[MAX_WORD_LEN] {0};
    printTrieInner(root, buf, 0);
}


// внутренняя функция печати дерева для рекурсивного вызова
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


// внутренняя функция поиска слова по префиксу для рекурсивного вызова
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


// функция поиска слова по префиксу
bool Trie::findWordByPrefix(const char* _pPrefix, char* _wordsList) {
    TrieNode* pNode = root;
    int i = 0, wordsLength;
    char chr;
    char buf[MAX_WORD_LEN] {0};

    while (_pPrefix[i] != 0) {   // находим уровень дерева с продолжением
        chr = _pPrefix[i];
        if (chr >= 'A' && chr <= 'Z')
            chr += 'a' - 'A';   // преобразуем в нижний регистр

        if (!(chr >= 'a' && chr <= 'z'))    // символ вне допустимого диапазона, выход
            return false;

        if (pNode->children[chr - 'a'] == nullptr)    // узла с искомым символом не существует, выход
            return false;
        else
            pNode = pNode->children[chr - 'a'];

        buf[i++] = chr;
    }    

    findWordByPrefixInner(pNode, buf, i, _wordsList, wordsLength = 0);

    if (wordsLength != 0) {
        wordsLength -= 2;    // убираем символы ', ' в конце
        _wordsList[wordsLength] = 0;
    }

    return wordsLength != 0;
}
