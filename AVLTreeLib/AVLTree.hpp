#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <ostream>
#include <iomanip>
#include <utility>
#include <list>

using namespace std;

template<typename KeyType, typename ValueType>
class AVLTree{
	private:
		struct AVLNode{
			KeyType m_key;
			ValueType m_value;
			AVLNode* m_left;
			AVLNode* m_right;

			AVLNode(const KeyType& key, const ValueType& value, AVLNode* left = nullptr, AVLNode* right = nullptr)
			: m_key(key), m_value(value), m_left(left), m_right(right) {};

			~AVLNode() {};

            AVLNode& operator=(AVLNode& el) {
                this->m_key = el->m_key;
                this->m_value = el->m_value;
                this->m_left = el->m_left;
                this->m_rigth = el->m_right;
            };
            bool operator==(AVLNode& el) {
                return this->m_key == el.m_key
                    && this->m_value == el.m_value
                    && this->m_left == el.m_left
                    && this->m_right == el.m_right;
            };
            bool operator!=(AVLNode& el) {
                return !(this->operator==(el));
            };
            string toString(bool space = false) {
                ostringstream key, value;
                key << this->m_key;
                value << this->m_value;
                return "[" + key.str() + "," + (space ? " " : "") + value.str() + "]";
            };
		};

        AVLNode* m_root;
        unsigned int m_size;

		AVLNode* ll_rotation(AVLNode* node) {
			AVLNode* temp = node->m_left;
			node->m_left = temp->m_right;
			temp->m_right = node;
			return temp;
		};
		AVLNode* rr_rotation(AVLNode* node) {
			AVLNode* temp = node->m_right;
			node->m_right = temp->m_left;
			temp->m_left = node;
			return temp;
		};
		AVLNode* lr_rotation(AVLNode* node) {
			node->m_left = rr_rotation(node->m_left);
			return ll_rotation(node);
		};
		AVLNode* rl_rotation(AVLNode* node) {
			node->m_right = ll_rotation(node->m_right);
			return rr_rotation(node);
		};
        int height(AVLNode* node) {
            if(node == nullptr) return 0;
            return max(height(node->m_right), height(node->m_left)) +1;
        };
        int balance_factor(AVLNode* node) {
            if(node == nullptr) return 0;
            return height(node->m_left) - height(node->m_right);
        };
        AVLNode* balance(AVLNode* node) {
            int bf = balance_factor(node);
            if(bf > 1) { // left heavy
                int bfl = balance_factor(node->m_left);
                if(bfl > 0)
                    node = ll_rotation(node);
                else
                    node = lr_rotation(node);
            }else if(bf < -1) { // right heavy
                int bfr = balance_factor(node->m_right);
                if(bfr > 0)
                    node = rl_rotation(node);
                else
                    node = rr_rotation(node);
            }
            return node;
        };
        AVLNode* insert(AVLNode* node, const KeyType& key, const ValueType& value) {
            if(node == nullptr) {
                node = new AVLNode(key, value);
                return node;
            }else if(key < node->m_key) {
                node->m_left = this->insert(node->m_left, key, value);
                node = this->balance(node);
            }else if(key > node->m_key) {
                node->m_right = this->insert(node->m_right, key, value);
                node = this->balance(node);
            }else {
                node->m_value = value;
            }
            return node;
        };

        string toString(AVLNode* node) const {
            if(node == nullptr) return "";
            return "(" + node->toString() +
                "," + this->toString(node->m_left) +
                "," + this->toString(node->m_right) +
            ")";
        };

        AVLNode* find(AVLNode* node, const KeyType& key) {
            if(node == nullptr) {
                return nullptr;
            }else if(key < node->m_key) {
                return this->find(node->m_left, key);
            }else if(key > node->m_key) {
                return this->find(node->m_right, key);
            }
            return node;
        };

		void clear(AVLNode* node) {
			if(node == nullptr) return;
			this->clear(node->m_left);
			this->clear(node->m_right);
			delete node;
		};

		template<typename StreamType>
		void indent(AVLNode* node, int level, string prefix, StreamType& stream) const {
			if(node != nullptr){
				stream << string(4*level, ' ') << prefix << node->toString(true) << endl;
				level += 1;
				this->indent(node->m_left, level, "L: ", stream);
				this->indent(node->m_right, level, "R: ", stream);
			}
		};

    public:

        AVLTree(): m_root(nullptr), m_size(0){};
        ~AVLTree() {
            this->clear();
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

        ValueType* find(const KeyType& key) {
            AVLNode* found = this->find(this->m_root, key);
            if(found != nullptr) return &(found->m_value);
            return nullptr;
        };

        string toString() const {
            return this->toString(this->m_root);
        };

        struct List{
            list<pair<KeyType, ValueType>> listed;
            List(AVLNode* node){
                this->traverse(node);
            };
            void traverse(AVLNode* node){
                if(node == nullptr)
                    return;

                this->traverse(node->m_left);

                pair<KeyType, ValueType> p;
                p.first = node->m_key;
                p.second = node->m_value;
                this->listed.push_back(p);

                this->traverse(node->m_right);
            };
        };

        list<pair<KeyType, ValueType>>& listify() const {
            List* list = new List(this->m_root);
            return list->listed;
        };

		template<typename StreamType>
		void print(StreamType& stream) const {
			this->indent(this->m_root, 0, "", stream);
		};
};

template<typename KeyType, typename ValueType>
std::ostream& operator <<(std::ostream& stream, AVLTree<KeyType, ValueType> const& tree) {
	// tree.print<std::ostream>(stream);
	return stream;
};
