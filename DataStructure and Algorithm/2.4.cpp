typedef struct _polyNode{
	ElementType coef;
	int expon;
	polynomials * link;
}polyNode;
typedef struct polyNode *polymonial;

polynomialAdd(polynomial A, polynomial B)
{
	polynomial front, rear, Nodetemp;
	rear = (polynomial)malloc(sizeof(polyNode));	//build an empty node
	front = rear;
	
	while( A && B )
	{
		switch( Compare( A->expon,B->expon ) )
		case >: 
				{
					Attach( A->coef, A->expon, rear);
					A=A->link;
					break;
				}
		case <:
				{
					Attach( B->coef, B->expon, rear);
					B=B->link;
					break;
				}
		case ==:
				{
					Nodetemp->coef = A->coef + B->coef ;
					Nodetemp->expon = A->expon;
					Attach( Nodetemp->coef, Nodetemp->expon, rear);
					A=A->link;
					B=B->link;
					break;
				}
	}
	
	if( A==Null && B!=Null )
	{
		while(B!=Null)
		{
			Attach( B->coef, B->expon, rear);
			B=B->link;
		}
	}	
	else if( A!=Null && B==Null )
	{
		while( A!=Null )
		{
			Attach( A->coef, A->expon, rear);
			A=A->link;
		}
	}
		
		
		
		
}