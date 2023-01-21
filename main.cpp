#include <iostream>
#include <string>
#include "Trie.h"
#include "Source.h"

using namespace std;


int main() {
	system("chcp 1251");

	Trie trie;

	// количество слов WORDS_COUNT = 15;
	trie.insert("call");
	trie.insert("cat");
	trie.insert("cult");
	trie.insert("run");
	trie.insert("rut");

	trie.insert("duck");
	trie.insert("dove");
	trie.insert("zebra");
	trie.insert("dog");
	trie.insert("dot");

	trie.insert("a");
	trie.insert("answer");
	trie.insert("the");
	trie.insert("hero");
	trie.insert("heroplane");

	std::cout << "Список слов в словаре:\n";
	trie.printTrie(); std::cout << '\n';

	char prefix[MAX_WORD_LEN], wordsList[MAX_WORD_LEN * WORDS_COUNT];	// буферы для префикса и списка слов;

	do {
		std::cout << "Введите начало слова: ";
		std::cin.getline(prefix, MAX_WORD_LEN);

		if (trie.findWordByPrefix(prefix, wordsList))
			std::cout << "Подходящие слова: " << wordsList << '\n';
		else
			std::cout << "Подходящие слова не найдены.\n";
	}
	while (QuestionYN("Продолжить выполнение программы?"));

	return 0;
}