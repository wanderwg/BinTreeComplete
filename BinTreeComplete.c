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
	while (pRoot != NULL) {//���ڵ㲻Ϊ�գ��ͽ��г����У�����ӽڵ�����Һ���
		pRoot = QueueFront(&q);
		QueuePop(&q);
		if (pRoot != NULL) {
			QueuePush(&q, pRoot->_pLeft);
			QueuePush(&q, pRoot->_pRight);
		}
	}
	while (!QueueEmpty(&q)) {//�ڵ�ΪNULL�����в���ʱ
		pRoot = QueueFront(&q);
		QueuePop(&q);
		if (pRoot == NULL)//�ڷǿսڵ���ֳ�����NULL�ڵ㣬˵��������ȫ������
			return -1;
	}
	return 1;
}
