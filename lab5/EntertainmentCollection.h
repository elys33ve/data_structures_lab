#include <iostream>
#pragma once

template <class T>
class EntertainmentCollection
{
private:
	static const int maxItems = 10;
	int item_num;
	T* items[maxItems];
public:
	EntertainmentCollection() {
		this->item_num = 0;
	}
	void addItem(T* media) {
		if (this->item_num + 1 > EntertainmentCollection::maxItems) {
			std::cout << "media could not be added, shelf is full.\n";
		}
		this->items[this->item_num] = media;
		this->item_num++;
	}
	T* removeItem() {
		if (this->item_num - 1 < 0) {
			std::cout << "media could not be removed, shelf is empty.\n";
		}
		T* item = this->items[this->item_num - 1];
		this->items[this->item_num - 1] = nullptr;
		this->item_num--;
		return item;
	}
	int numItemsInShelf() {
		return this->item_num;
	}
};