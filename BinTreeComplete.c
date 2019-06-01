#include "BinTree.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"

int BinaryTreeComplete(BTNode* pRoot) {
	if (pRoot == NULL)
		return 1;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (pRoot != NULL) {//若节点不为空，就进行出队列，并入队节点的左右孩子
		pRoot = QueueFront(&q);
		QueuePop(&q);
		if (pRoot != NULL) {
			QueuePush(&q, pRoot->_pLeft);
			QueuePush(&q, pRoot->_pRight);
		}
	}
	while (!QueueEmpty(&q)) {//节点为NULL但队列不空时
		pRoot = QueueFront(&q);
		QueuePop(&q);
		if (pRoot == NULL)//在非空节点后又出现了NULL节点，说明不是完全二叉树
			return -1;
	}
	return 1;
}
