bool VerifySequenceOfBSTInPostOrder(int sequence[], int length)
{
	if(sequence == NULL || length < 0)
		return;

	int root = sequnece[length-1];

	//在BST中左子树的结点小于根结点
	int i = 0;
	for( ; i < length - 1; ++i)
	{
		if(sequence[i] > root)
			break;
	}

	//在BST中右子树的结点大于根结点
	int j = i;
	for( ; j < length - 1; ++j)
	{
		if(sequence[j] < root)
			return false;
	}

	//判断左子树是不是BST
	bool left = true;
	left = VerifySequenceOfBSTInPostOrder(sequence, i);

	//判断右子树是不是BST
	bool right = true;
	right = VerifySequenceOfBSTInPostOrder(sequence[i], length - i - 1);

	return (left && right);

}