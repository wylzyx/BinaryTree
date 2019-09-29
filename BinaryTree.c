#include "BinaryTree.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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

// ����
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

// �ǵݹ����
// �������
void BinaryTreeLevelOrder(BTNode* root) {

}

// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root) {
	queue q;
	BTNode *ptr;
	// ���й�����ȱ�������α�����������NULL�ڵ�Ҳ�������  
	q.push(root);
	while ((ptr = q.pop()) != NULL)
	{
		q.push(ptr->_left);
		q.push(ptr->_right);
	}
	// �ж��Ƿ���δ�����ʵ��Ľڵ�  
	while (!q.is_empty())
	{
		ptr = q.pop();
		// ��δ���ʵ��ĵķ�NULL�ڵ㣬�������ڿն���Ϊ����ȫ������  
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