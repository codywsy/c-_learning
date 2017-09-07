Postion FindMin( SearchTree T )
{
	if( T = NULL )
		return NULL;
	else
		if(T->left!=NULL)
			return FindMin(T->left);
		else 
			return T;
}


Postion FindMax( SearchTree T )
{
	if( T!=NULL )
		while(T->Right!=NULL)
			T=T->Right;

	return T;

}