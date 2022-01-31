#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <ostream>
#include <iomanip>

using namespace std;

template<typename KeyType, typename ValueType>
class BinarySearchTree {
	private:
		struct BSTNode{
			KeyType m_key;
			ValueType m_value;
			BSTNode* m_left;
			BSTNode* m_right;

			BSTNode(const KeyType& key, const ValueType& value, BSTNode* left = nullptr, BSTNode* right = nullptr)
			: m_key(key), m_value(value), m_left(left), m_right(right) {};

			~BSTNode() {};

            BSTNode& operator=(BSTNode& el) {
                this->m_key = el->m_key;
                this->m_value = el->m_value;
                this->m_left = el->m_left;
                this->m_rigth = el->m_right;
            };
            bool operator==(BSTNode& el) {
                return this->m_key == el.m_key
                    && this->m_value == el.m_value
                    && this->m_left == el.m_left
                    && this->m_right == el.m_right;
            };
            bool operator!=(BSTNode& el) {
                return !(this->operator==(el));
            };
            string toString(bool space = false) {
                ostringstream key, value;
                key << this->m_key;
                value << this->m_value;
                return "[" + key.str() + "," + (space ? " " : "") + value.str() + "]";
            };
		};

        BSTNode* m_root;
        unsigned int m_size;

		BSTNode* insert(BSTNode* node, const KeyType& key, const ValueType& value) {
			if(node == nullptr) {
				return new BSTNode(key, value);
			}else if(key < node->m_key) {
				node->m_left = this->insert(node->m_left, key, value);
			}else if(key > node->m_key) {
				node->m_right = this->insert(node->m_right, key, value);
			}else
				node->m_value = value;
			return node;
		};

		BSTNode* remove(BSTNode* node, const KeyType& key) {
			if(node == nullptr) {
				return nullptr;
			}else if(key < node->m_key) {
				node->m_left = this->remove(node->m_left, key);
			}else if(key > node->m_key) {
				node->m_right = this->remove(node->m_right, key);
			}else{
				if(node->m_left == nullptr && node->m_right == nullptr) {
					delete node;
					node = nullptr;
				}else if(node->m_left == nullptr) {
					BSTNode* temp = node->m_right;
					delete node;
					node = temp;
				}else if(node->m_right == nullptr) {
					BSTNode* temp = node->m_left;
					delete node;
					node = temp;
				}else {
					BSTNode* temp = this->max(node->m_left);
					node->m_key = temp->m_key;
					node->m_value = temp->m_value;
					node->m_left = this->remove(node->m_left, temp->m_key);
				}
			}
			return node;
		};

		BSTNode* find(BSTNode* node, const KeyType& key) {
			if(node == nullptr) {
				return nullptr;
			}else if(key < node->m_key) {
				return this->find(node->m_left, key);
			}else if(key > node->m_key) {
				return this->find(node->m_right, key);
			}
			return node;
		};

		BSTNode* min(BSTNode* node) {
			BSTNode* temp = node;
			while(temp->m_right != nullptr) {
				temp = temp->m_right;
			};
			return temp;
		};

		BSTNode* max(BSTNode* node) {
			BSTNode* temp = node;
			while(temp->m_right != nullptr) {
				temp = temp->m_right;
			};
			return temp;
		};

		string toString(BSTNode* node) const {
            if(node == nullptr) return "";
            return "(" + node->toString() +
                "," + this->toString(node->m_left) +
                "," + this->toString(node->m_right) +
            ")";
        };

		void clear(BSTNode* node) {
			if(node == nullptr) return;
			this->clear(node->m_left);
			this->clear(node->m_right);
			delete node;
		};

		template<typename StreamType>
		void indent(BSTNode* node, int level, string prefix, StreamType& stream) const {
			if(node != nullptr){
				stream << string(4*level, ' ') << prefix << node->toString(true) << endl;
				level += 1;
				this->indent(node->m_left, level, "L: ", stream);
				this->indent(node->m_right, level, "R: ", stream);
			}
		};

	public:
		BinarySearchTree(): m_root(nullptr) {};
		~BinarySearchTree() {
			this->clear;
		};

		void clear() {
			this->clear(this->m_root);
			this->m_root = nullptr;
		};

		size_t size() const {
			return m_size;
		};

		void insert(const KeyType& key, const ValueType& value) {
			this->m_root = this->insert(this->m_root, key, value);
			this->m_size++;
		};

		void remove(const KeyType& key) {
			this->m_root = this->remove(this->m_root, key);
			this->m_size--;
		};

		ValueType* find(const KeyType& key) {
			BSTNode* found = this->find(this->m_root, key);
			if(found != nullptr) return &(found->m_value);
			return nullptr;
		};

		ValueType* min(){
			return &(this->min(this->m_root)->m_value);
		};

		ValueType* max(){
			return &(this->max(this->m_root)->m_value);
		};

		string toString() const {
			return this->toString(this->m_root);
		};

		template<typename StreamType>
		void print(StreamType& stream) const {
			this->indent(this->m_root, 0, "", stream);
		};

};
template<typename KeyType, typename ValueType>
std::ostream& operator <<(std::ostream& stream, BinarySearchTree<KeyType, ValueType> const& tree) {
	// tree.print<std::ostream>(stream);
	return stream;
}
