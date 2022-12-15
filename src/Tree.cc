#include "Tree.h"
#include<algorithm>

namespace {

	/**
	 * @brief Adiciona na arvore através de um processo recursivo.
	 */
	void insertRecursevelly(TreeNode* root, VerbeteType type, std::string key, std::string data) {
		if (key <= root->getKey())
			if (root->leftChild == nullptr) {
				root->leftChild = new TreeNode(type, key, data);
				root->leftChild->parent = root;
			}
			else
				insertRecursevelly(root->leftChild, type, key, data);
		else
			if (root->rightChild == nullptr) {
				root->rightChild = new TreeNode(type, key, data);
				root->rightChild->parent = root;
			}
			else
				insertRecursevelly(root->rightChild, type, key, data);
	}

	/**
	 * @brief Faz a busca na árvore através de um processo recursivo.
	 */
	TreeNode* searchRecursevelly(TreeNode* root, std::string key) {
		if (root == nullptr)
			return nullptr;

		if (root->getKey() == key)
			return root;

		if (key <= root->getKey())
			return searchRecursevelly(root->leftChild, key);
		else
			return searchRecursevelly(root->rightChild, key);
	}

	std::string preOrder(TreeNode* raiz)
	{
		std::string result = "";
		if (raiz != nullptr)
		{
			result += raiz->getKey() + ";";
			result += preOrder(raiz->leftChild);
			result += preOrder(raiz->rightChild);
		}
		return result;
	}
}

TreeNode::TreeNode(VerbeteType type, std::string key, std::string data) : verbete(type, key, data), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}

Tree::Tree() : m_size(0) {}

TreeNode* Tree::search(std::string key) {
	return searchRecursevelly(m_root, key);
}

void TreeNode::setVerbete(Verbete& v) { verbete = v; }

Verbete& TreeNode::getVerbete() { return verbete; }

std::string TreeNode::getKey() { return verbete.m_word; }

std::string TreeNode::getData() {
	std::string meaning = *verbete.m_meaning;
	for (int i = 1; i < verbete.m_meaning_size; i++)
		meaning += ", " + *(verbete.m_meaning + i);
	return meaning;
}

void TreeNode::addData(std::string meaning) {
	verbete.addMeaning(meaning);
}
void Tree::insert(VerbeteType type, std::string key, std::string data) {
	if (m_root == nullptr) {
		m_root = new TreeNode(type, key, data);
		m_size++;
	}
	else {
		TreeNode* node = search(key);

		if (node == nullptr) {
			insertRecursevelly(m_root, type, key, data);
			m_size++;
		}
		else {
			node->addData(data);
		}
	}
}

void Tree::remove(TreeNode* node) {
	TreeNode* parent = node->parent;
	TreeNode* temp;
	bool isLeftNode = node->getKey() <= parent->getKey();

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

std::string Tree::to_string() {
	std::string* names;

	names = (std::string*)malloc(m_size * sizeof(std::string));

	std::string allKeys = preOrder(m_root);

	for (int i = 0; i < m_size; ++i) {
		auto pos = allKeys.find(';');
		
		new (names + i) std::string(allKeys.substr(pos));

		allKeys = allKeys.substr(pos+1, allKeys.size()-1);
	}

	std::sort(names, names + m_size);

	TreeNode* item = search(*names);
	Verbete v = item->getVerbete();
	std::string output = v.m_word + " " + v.getType() + "\n" + v.getMeaning();

	for (int i = 1; i < m_size; ++i) {
		Verbete v = search(*(names + i))->getVerbete();
		output += "\n";
		output += v.m_word + " " + v.getType() + "\n" + v.getMeaning();
	}

	return output;
}