void PrintBinaryTreeFromTopToBottom(BinaryTree* pRoot)
{
	if(pRoot==NULL)
		return;

	std::deque<BinaryTree *> dequeTreeNode;

	dequeTreeNode.push_back(pRoot);

	while(dequeTreeNode.size())
	{
		BinaryTree * pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();

		printf("%d", pNode->m_nValue);

		if(pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft);

		if(pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);
	}
}