#pragma once
#include <string>
#include <iostream>

template <typename data_type, typename key_type = std::string>
class ordered_table {
private:
	struct node {
		data_type value;
		key_type key;
		node* left;
		node* right;
		node(key_type key, data_type value, node* left = nullptr, node* right = nullptr) {
			this->key = key; this->value = value;
			this->left = left; this->right = right;
		}
	};
	node* root;
public:
	ordered_table() : root(nullptr) {};
	ordered_table(key_type key, data_type value) { root = new node(key, value); }
	void add(key_type key, data_type value);
	data_type find(key_type key);
};

template <typename data_type, typename key_type> void ordered_table<data_type, key_type>::add(key_type key, data_type value) {
	
	if (root != nullptr) {
		node* iterator = root;
		node* parent = root;
		while (iterator != nullptr) {
			if (key > iterator->key) { 
				iterator = iterator->right;
				if (iterator != nullptr) parent = iterator;
			}
			else if (key < iterator->key) { 
				iterator = iterator->left;
				if (iterator != nullptr) parent = iterator;
			}
			else { 
				std::cout << "row with key: " << key << "already in the table" << std::endl;
			}
		}

		if (key > parent->key) parent->right = new node(key, value);
		else if (key < parent->key) parent->left = new node(key, value);
	}

	else {
		root = new node(key, value);
	}
}

template <typename data_type, typename key_type> data_type ordered_table<data_type, key_type>::find(key_type key) {
	if (root != nullptr) {
		node* iterator = root;
		node* parent = root;
		while (iterator != nullptr) {
			if (iterator->key == key) return iterator->value;
			else {
				if (key > iterator->key) iterator = iterator->right;
				else if (key < iterator->key) iterator = iterator->left;
			}
		}
		std::cout << "table doesn't have row with key: " << key << std::endl;
	}

	else {
		std::cout << "table is empty" << std::endl;
	}
}