#include "BinaryTree.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate() {
	BTNode* bt = NULL;
	char ch;
	scanf("%c", &ch);
	if (ch == 0) {
		bt = NULL;
	}
	if (ch != '#') {
		bt = (BTNode*)malloc(sizeof(BTNode));
		bt->_data = ch;
		bt->_left = BinaryTreeCreate();
		bt->_right = BinaryTreeCreate();
	}
	return bt;
}

void BinaryTreeDestory(BTNode** root) {
	if (root == NULL) {
		return;
	}
	free(&((*root)->_left));
	free(&((*root)->_right));
	free(root);
	root = NULL;
}

int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int lsize = BinaryTreeSize(root->_left);
	int rlize = BinaryTreeSize(root->_right);
	return lsize + rlize + 1;
}

int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL) {
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root->_data == x) {
		return root;
	}
	else {
		return NULL;
	}
	return BinaryTreeFind(root->_left, x);
	return BinaryTreeFind(root->_right, x);
}

// 遍历
void BinaryTreePrevOrder(BTNode* root) {
	assert(root);
	if (root == NULL) {
		return;
	}
	printf("%d\n", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	return;
}

void BinaryTreeInOrder(BTNode* root) {
	assert(root);
	if (root == NULL) {
		return;
	}
	BinaryTreePrevOrder(root->_left);
	printf("%d\n", root->_data);
	BinaryTreePrevOrder(root->_right);
	return;
}

void BinaryTreePostOrder(BTNode* root) {
	assert(root);
	if (root == NULL) {
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%d\n", root->_data);
	return;
}

// 非递归遍历
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root) {

}

// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root) {
	queue q;
	BTNode *ptr;
	// 进行广度优先遍历（层次遍历），并把NULL节点也放入队列  
	q.push(root);
	while ((ptr = q.pop()) != NULL)
	{
		q.push(ptr->_left);
		q.push(ptr->_right);
	}
	// 判断是否还有未被访问到的节点  
	while (!q.is_empty())
	{
		ptr = q.pop();
		// 有未访问到的的非NULL节点，则树存在空洞，为非完全二叉树  
		if (NULL != ptr)
		{
			return 0;
		}
	}
	return 1;
}

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void TestBinaryTree();