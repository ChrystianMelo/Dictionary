#include "Tree.h"

namespace {
	void insertRecursevelly(TreeNode* root, int key, std::string data) {
		if (key <= root->m_key)
			if (root->leftChild == nullptr) {
				root->leftChild = new TreeNode(key,data);
				root->leftChild->parent = root;
			}
			else
				insertRecursevelly(root->leftChild,key, data);
		else
			if (root->rightChild == nullptr) {
				root->rightChild = new TreeNode(key, data);
				root->rightChild->parent = root;
			}
			else
				insertRecursevelly(root->rightChild, key, data);
	}
	TreeNode* searchRecursevelly(TreeNode* root, int key) {
		if (root == nullptr)
			return nullptr;

		if (root->m_key == key)
			return root;

		if (key <= root->m_key)
			return searchRecursevelly(root->leftChild, key);
		else
			return searchRecursevelly(root->rightChild, key);
	}
}

TreeNode::TreeNode(int key, std::string data) : m_key(key), m_data(data), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}

TreeNode* Tree::search(int key) {
	return searchRecursevelly(m_root, key);
}

void Tree::insert(int key, std::string data) {
	if (m_root == nullptr)
		m_root = new TreeNode(key,data);
	else
		insertRecursevelly(m_root,key, data);
}

void Tree::remove(TreeNode* node) {
	TreeNode* parent = node->parent;
	TreeNode* temp;
	bool isLeftNode = node->m_key <= parent->m_key;

	if (node->rightChild == nullptr)
	{
		temp = node;
		node = node->leftChild;
	}
	else
		if (node->leftChild == nullptr)
		{
			temp = node;
			node = node->rightChild;
		}
		else
		{
			temp = node->rightChild;

			while (temp->leftChild != nullptr)
				temp = temp->leftChild;

			temp->leftChild = node->leftChild;

			temp = node;
			node = node->rightChild;
		}
	if (node == nullptr) {
		if (isLeftNode) parent->leftChild = nullptr;
		else parent->rightChild = nullptr;
	}

	delete temp;
}