#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>

namespace BinaryTreeBigestDist {

	int index = 0;  //全局索引变量

typedef struct Node {
	struct Node *pleft;     //左孩子
	struct Node *pright;    //右孩子
	char chValue;           //该节点的值

	int leftMaxValue;       //左子树最长距离
	int rightMaxValue;      //右子树最长距离
} BinTree;

void findMaxLen(BinTree* root, int *maxLen) {
	//遍历到叶子结点，返回
	if (root == NULL)
		return;

	//如果左子树为空，那么该节点左边最长距离为0
	if (root->pleft == NULL)
		root->leftMaxValue = 0;

	//如果右子树为空，那么该节点右边最长距离为0
	if (root->pright == NULL)
		root->rightMaxValue = 0;

	//如果左子树不为空，递归寻找左子树最长距离
	if (root->pleft != NULL)
		findMaxLen(root->pleft, maxLen);

	//如果右子树不为空，递归寻找右子树最长距离
	if (root->pright != NULL)
		findMaxLen(root->pright, maxLen);

	//计算左子树中距离根节点的最长距离
	if (root->pleft != NULL) {
		if (root->pleft->leftMaxValue > root->pleft->rightMaxValue)
			root->leftMaxValue = root->pleft->leftMaxValue + 1;
		else
			root->leftMaxValue = root->pleft->rightMaxValue + 1;
	}

	//计算右子树中距离根节点的最长距离
	if (root->pright != NULL) {
		if (root->pright->leftMaxValue > root->pright->rightMaxValue)
			root->rightMaxValue = root->pright->leftMaxValue + 1;
		else
			root->rightMaxValue = root->pright->rightMaxValue + 1;
	}

	//更新最长距离
	if (root->leftMaxValue + root->rightMaxValue > *maxLen)
		*maxLen = root->leftMaxValue + root->rightMaxValue;
}

//创建二叉树
// void buildBinTree(BinTree *root)
// {
// 	char ch;
// 	scanf_s("%c", &ch);    //输入一个元素
// 	std::cin;
// 	if (ch == 'u')        //若输入的是空格符，表明二叉树为空，置*root为NULL
// 		root = NULL;
// 	else {               //若输入的不是空格符，则将该值赋值给根节点的chValue, 递归建立左子树和右子树
// 		root = (BinTree*)malloc(sizeof(BinTree));
// 		root->chValue = ch;
// 		root->leftMaxValue = 0;
// 		root->rightMaxValue = 0;

// 		buildBinTree(root->pleft);
// 		buildBinTree(root->pright);
// 	}
// }

//创建二叉树
void buildBinTreeByData(BinTree *&root, char data[])
{
	char ch =  data[index++];
	if (ch == '#')        //若输入的是空格符，表明二叉树为空，置*root为NULL
		root = NULL;
	else {               //若输入的不是空格符，则将该值赋值给根节点的chValue, 递归建立左子树和右子树
		root = (BinTree*)malloc(sizeof(BinTree));
		root->chValue = ch;
		root->leftMaxValue = 0;
		root->rightMaxValue = 0;

		buildBinTreeByData(root->pleft, data);
		buildBinTreeByData(root->pright, data);
	}
}

//销毁二叉树，释放内存
void destroyBinTree(BinTree *root)
{
	if (root != NULL) {
		destroyBinTree(root->pleft);
		destroyBinTree(root->pright);

		free(root);
		root = NULL;
	}
}

//中序遍历二叉树
void preOrderTraverse(BinTree* root)
{
	if (root != NULL) {
		printf("%c", root->chValue);
		preOrderTraverse(root->pleft);
		preOrderTraverse(root->pright);
	}
}

// void main2() {
// 	BinTree* root = nullptr;
// 	buildBinTree(root);
// 	preOrderTraverse(root);
// 	printf("\n");
// 	int maxLen = 0;
// 	findMaxLen(root, &maxLen);
// 	printf("maxLen = %d\n", maxLen);
// 	destroyBinTree(root);
// }

void main() {
	// 构建的二叉树如图: http://p7kuppz6y.bkt.clouddn.com/QQ截图20180928192111.png
	char data[17] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', 'X', '#', '#', '#' };
	BinTree* root = nullptr;
	buildBinTreeByData(root, data);
	preOrderTraverse(root);
	printf("\n");
	int maxLen = 0;
	findMaxLen(root, &maxLen);
	printf("maxLen = %d\n", maxLen);
	destroyBinTree(root);
}
}
