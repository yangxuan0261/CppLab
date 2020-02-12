#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <Stack>
#include <Queue>
#include <vector>
#include <string>
#include <map>

using namespace std;
#define Element char
#define format "%c"

namespace BinaryTree {

	typedef struct Node {
		Element data;
		struct Node *lchild;
		struct Node *rchild;
	} *Tree;

	int index = 0;  //全局索引变量

	//二叉树构造器,按先序遍历顺序构造二叉树
	//无左子树或右子树用'#'表示
	void treeNodeConstructor(Tree &root, Element data[]) {
		Element e = data[index++];
		if (e == '#') {
			root = NULL;
		} else {
			root = (Node *)malloc(sizeof(Node));
			root->data = e;
			treeNodeConstructor(root->lchild, data);  //递归构建左子树
			treeNodeConstructor(root->rchild, data);  //递归构建右子树
		}
	}

	//深度优先遍历, 思路参考: http://rapheal.iteye.com/blog/1526863
	void depthFirstSearch(Tree root) {
		stack<Node *> nodeStack;  //使用C++的STL标准模板库
		nodeStack.push(root);
		Node *node;
		while (!nodeStack.empty()) {
			node = nodeStack.top();
			printf(format, node->data);  //遍历根结点
			nodeStack.pop();
			if (node->rchild) {
				nodeStack.push(node->rchild);  //先将右子树压栈
			}
			if (node->lchild) {
				nodeStack.push(node->lchild);  //再将左子树压栈
			}
		}
	}

	//广度优先遍历, 思路参考: http://rapheal.iteye.com/blog/1526861
	void breadthFirstSearch(Tree root) {
		queue<Node *> nodeQueue;  //使用C++的STL标准模板库
		nodeQueue.push(root);
		Node *node;
		while (!nodeQueue.empty()) {
			node = nodeQueue.front();
			nodeQueue.pop();
			printf(format, node->data);
			if (node->lchild) {
				nodeQueue.push(node->lchild);  //先将左子树入队
			}
			if (node->rchild) {
				nodeQueue.push(node->rchild);  //再将右子树入队
			}
		}
	}

	void main() {
		// 构成的二叉树如图: http://p7kuppz6y.bkt.clouddn.com/QQ截图20180928173554.png
		//上图所示的二叉树先序遍历序列,其中用'#'表示结点无左子树或无右子树
		Element data[15] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
		Tree tree;
		treeNodeConstructor(tree, data);
		printf("深度优先遍历二叉树结果: ");
		depthFirstSearch(tree);
		printf("\n\n广度优先遍历二叉树结果: ");
		breadthFirstSearch(tree);
		system("pause");
	}
}

	// int main() {
	// 	system("chcp 65001"); // 防止中文乱码, 设置字符集
	// 	// 构成的二叉树如图: http://p7kuppz6y.bkt.clouddn.com/QQ截图20180928173554.png
	// 	//上图所示的二叉树先序遍历序列,其中用'#'表示结点无左子树或无右子树
	// 	Element data[15] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
	// 	BinaryTree::Tree tree;
	// 	BinaryTree::treeNodeConstructor(tree, data);
	// 	printf("深度优先遍历二叉树结果: ");
	// 	BinaryTree::depthFirstSearch(tree);
	// 	printf("\n\n广度优先遍历二叉树结果: ");
	// 	BinaryTree::breadthFirstSearch(tree);
	// 	printf("\n");
	// 	system("pause");
	// 	return 0;
	// }