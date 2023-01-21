#include <iostream>
#include <string>
#include "Trie.h"
#include "Source.h"

using namespace std;


int main() {
	system("chcp 1251");

	Trie trie;

	// ���������� ���� WORDS_COUNT = 15;
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

	std::cout << "������ ���� � �������:\n";
	trie.printTrie(); std::cout << '\n';

	char prefix[MAX_WORD_LEN], wordsList[MAX_WORD_LEN * WORDS_COUNT];	// ������ ��� �������� � ������ ����;

	do {
		std::cout << "������� ������ �����: ";
		std::cin.getline(prefix, MAX_WORD_LEN);

		if (trie.findWordByPrefix(prefix, wordsList))
			std::cout << "���������� �����: " << wordsList << '\n';
		else
			std::cout << "���������� ����� �� �������.\n";
	}
	while (QuestionYN("���������� ���������� ���������?"));

	return 0;
}