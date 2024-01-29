#pragma once

#include <iostream>


template<typename ItemType>
struct TreeNode;



//enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

template<typename ItemType>
class TreeType {
public:
	TreeType();
	~TreeType();
	TreeType(const TreeType <ItemType>&);
	//void operator = (const TreeType<ItemType>&);
	//void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int LengthIs() const;
	void RetrieveItem(ItemType&, bool& found);
	void InsertItem(ItemType);
	void DeleteItem(ItemType);
	//void ResetTree(OrderType);
	//void GetNextItem(ItemType&, OrderType, bool&);
	//void printTree(ofstream&) const;

private:
	TreeNode<ItemType>* root;
};

template<typename ItemType>
struct TreeNode
{
	ItemType info;
	TreeNode<ItemType>* left;
	TreeNode<ItemType>* right;
};

template<typename ItemType>
TreeType<ItemType>::TreeType()
{
	root = nullptr;
}

template<typename ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree)
{
	CopyTree(root, originalTree.root);
}

template<typename Itemtype>
void CopyTree(TreeNode<Itemtype>*& copy, const TreeNode<Itemtype>* originalTree)
{
	if (originalTree == nullptr)
		copy = nullptr;
	else
	{
		copy = new TreeNode<Itemtype>;
		copy->info = originalTree->info;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}

template<typename ItemType>
void Destroy(TreeNode<ItemType>*& tree)
{
	if (tree != nullptr)
	{
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

template<typename ItemType>
TreeType<ItemType>::~TreeType()
{
	Destroy(root);
}

template<typename ItemType>
bool TreeType<ItemType>::IsFull() const
{
	TreeNode<ItemType>* location;
	try
	{
		location = new TreeNode<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template<typename ItemType>
bool TreeType<ItemType>::IsEmpty() const
{
	return root == nullptr;
}

template<typename ItemType>
int CountNodes(TreeNode<ItemType>* tree)
{
	if (tree == nullptr)
		return 0;
	else
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template<typename ItemType>
int TreeType<ItemType>::LengthIs() const
{
	return CountNodes(root);
}


template<typename ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	Retrieve(root, item, found);
}

template<typename ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found)
{
	if (tree == nullptr)
		found = false;
	else if (item < tree->info)
		Retrieve(tree->left, item, found);
	else if (item > tree->info)
		Retrieve(tree->right, item, found);
	else {
		item = tree->info;
		found = true;
	}
}

template<typename ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
{
	if (tree == nullptr)
	{
		tree = new TreeNode<ItemType>;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->info = item;
	}
	else if (item < tree->info)
		Insert(tree->left, item);
	else
		Insert(tree->right, item);
}

template<typename ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
{
	Insert(root, item);
}

template<typename ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
{
	ItemType data;
	TreeNode<ItemType>* tempPtr;
	tempPtr = tree;
	if (tree->left == nullptr) {
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == nullptr) {
		tree = tree->left;
		delete tempPtr;
	}
	else {
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);
	}
}

template<typename ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
{
	if (item < tree->info)
		Delete(tree->left, item);
	else if (item > tree->info)
		Delete(tree->right, item);
	else
		DeleteNode(tree);
}

template<typename ItemType>
void GetPredecessor(TreeNode<ItemType > * tree, ItemType& data)
{
	while (tree->right != nullptr)
		tree = tree->right;
	data = tree->info;
}

template<typename ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
	Delete(root, item);
}
