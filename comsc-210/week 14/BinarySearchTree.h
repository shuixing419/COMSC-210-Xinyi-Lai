// Programmer: Zhou Jie
// Programmer's ID: 2047477
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <queue>
using std::queue;

template<typename K, typename V>
class BinarySearchTree
{
	struct Node
	{
		K key;
		V value;
		Node* left;
		Node* right;
	};

	Node* rootNode;
	int siz;
	void keys(const Node*, queue<K>&) const;
	void clear(Node*);
	void copyTree(Node*, const Node*);

public:
	BinarySearchTree() { rootNode = 0; siz = 0; } //default constructor
	BinarySearchTree(const BinarySearchTree&);  //copy constructor
	BinarySearchTree<K, V>& operator = (const BinarySearchTree<K, V>&);
	~BinarySearchTree(); //destructor

	int size() { return siz; }
	V operator[] (const K&) const; //getter
	V& operator[] (const K&);  //setter
	bool containsKey(const K&)const; //getter
	void deleteKey(const K&); //setter
	queue<K> Keys() const;
	void clear();
};

template<typename K, typename V>
void BinarySearchTree<K, V>::keys(const Node* p, queue<K>& q) const
{
	if (!p) return;

	keys(p->left, q);
	q.push(p->key);
	keys(p->right, q);
}

template<typename K, typename V>
void BinarySearchTree<K, V>::clear(Node* p)
{
	if (!p) return;

	clear(p->left);
	clear(p->right);
	delete p;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::copyTree(Node* p, const Node* copiedTree)
{
	p->key = copiedTree->key;
	p->value = copiedTree->value;
	p->left = p->right = 0;

	if (copiedTree->left)
	{
		copyTree(p->left = new Node, copiedTree->left);
	}
	if (copiedTree->right)
		copyTree(p->right = new Node, copiedTree->right);
}

template<typename K, typename V>
BinarySearchTree<K, V>::BinarySearchTree(const BinarySearchTree& original)
{
	rootNode = 0;
	if (original.rootNode)
		copyTree(rootNode = new Node, original.rootNode);
	siz = original.siz;
}

template<typename K, typename V>
BinarySearchTree<K, V>& BinarySearchTree<K, V>::operator = (const BinarySearchTree<K, V>& original)
{
	rootNode = 0;
	if (original.rootNode)
		copyTree(rootNode = new Node, original.rootNode);
	siz = original.siz;

	return *this;
}

template<typename K, typename V>
BinarySearchTree<K, V>::~BinarySearchTree()
{
	clear();
}

template<typename K, typename V>
V BinarySearchTree<K, V>::operator[](const K& key)const
{
	Node* p = rootNode;

	while (p)
	{
		if (p->key == key)break;

		if (p->key < key) p = p->right;
		else p = p->left;
	}
	if (p) return p->value;
	return V();
}

template<typename K, typename V>
V& BinarySearchTree<K, V>::operator[](const K& key)
{
	Node* p = rootNode;
	Node* prev = 0;

	while (p)
	{
		if (p->key == key) return p->value;

		prev = p;

		if (p->key > key) p = p->left;
		else p = p->right;
	}
	Node* temp = new Node{ key, V()
	};
	siz++;

	if (prev == 0) rootNode = temp;
	else
	{
		if (prev->key < key) prev->right = temp;
		else prev->left = temp;
	}

	return temp->value;
}

template<typename K, typename V>
bool BinarySearchTree<K, V>::containsKey(const K& key) const
{
	Node* p = rootNode;

	while (p)
	{
		if (p->key == key) break;
		if (p->key < key) p = p->right;
		else p = p->left;
	}
	return p != 0;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::deleteKey(const K& key)
{
	Node* p = rootNode;
	Node* prev = 0;
	while (p)
	{
		if (p->key == key) break;
		prev = p;
		if (p->key < key) p = p->right;
		else p = p->left;
	}

	if (!p) return; // case 1: not found

	if (p->left == 0)
	{
		if (p->right == 0)   // if p doesn't have children
		{
			if (prev == 0)   // case 2: it is the root node and only root node
				rootNode = 0;
			if (prev->left == p) // case 3: p has no children
				prev->left = 0;
			else
				prev->right = 0;

			delete p;
			siz--;
			return;
		}

		Node* pSave = p; // promote to this node
		prev = p;
		p = p->right;  // the right step
		while (p->left)
		{
			prev = p;
			p = p->left;
		} // the smallest node from right subtree found

		pSave->key = p->key;  // replace key and value at node of the matched key
		pSave->value = p->value;
		if (prev->left == p) prev->left = p->right; // move p's right sub-tree to prev->left
		else prev->right = p->right;  // in case there is no left-left-left steps

		delete p;
		siz--;
		return;
	}

	Node* pSave = p;  // promote to this node
	prev = p;
	p = p->left;   // the left step

	while (p->right)
	{
		prev = p;
		p = p->right;
	}// the greatest node from left subtree found

	pSave->key = p->key;  // replace key and value at node of the matched key
	pSave->value = p->value;
	if (prev->right == p) prev->right = p->left;// move p's left sub-tree to prev->right
	else prev->left = p->left;  //in case there is no right-right steps
	delete p;
	siz--;
}

template<typename K, typename V>
queue<K> BinarySearchTree<K, V>::Keys() const
{
	queue<K> result;
	keys(rootNode, result);
	return result;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::clear()
{
	clear(rootNode);
	rootNode = 0;
	siz = 0;
}
#endif //BinarySearchTree_h


