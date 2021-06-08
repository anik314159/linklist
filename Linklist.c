#include<stdio.h>
#include<stdlib.h>

#include"Linklist.h"


void AppendList(struct Nodeint**q,int num)
{
	struct Nodeint* newNode= (struct Nodeint*)malloc(sizeof(struct Nodeint));
	struct Nodeint* temp = *q;
	newNode->val = num;

	newNode->link = NULL;

	if(*q == NULL)
	{
		*q = newNodeint;
		return ;
	}


	while(temp->link!=NULL)
	temp=temp->link;


	temp->link =newNode;
	return;
}


void Display(struct Nodeint* q)
{
	struct Nodeint*temp=NULL;

	temp =q;
	printf("\n\n");
	while(temp!=NULL)
	{
		//		temp=temp->link;
		printf("%i ",temp->val);
		temp=temp->link;
	}printf("\n");
}
int Count(struct Nodeint*q)
{
    int c=0;
    while(q!=NULL)
    {
        q=q->link;
        c++;
    }
    return c;
}
void PrintMiddle(struct Nodeint* headref)
{
	struct Nodeint*temp = headref;
	int c = 0,m,l=-1;
	c = Count(headref);
	temp = headref;

	if(c%2==0)
	{
		m = (c/2);
		l=(c/2)+1;
	}
	else
	{
		m=(c+1)/2;
	}

	int s =0;
	while(s!=m-1)
	{
		temp =temp->link;
		s++;
	}


	if(l==-1)

	{
		printf("\n\n%i\n",temp->val);
	}
	else
	printf("\n\n%i %i\n\n",temp->val,(temp->link)->val);

}
	
void DelMiddle(struct Nodeint*headref)
{
	
    struct Nodeint*temp = headref;
    int c = 0,m,l=-1;
    c = Count(headref);
    temp = headref;

    if(c%2==0)
    {
        m = (c/2);
        l=(c/2)+1;
    }
    else
    {
        m=(c+1)/2;
    }

    int s =0;
    while(s!=m-2)
    {
        temp =temp->link;
        s++;
    }


    if(l==-1)
	{
		struct Nodeint* r;
		r=temp->link;
		temp->link =r->link;
		free(r);
	}
	else
	{
		struct Nodeint* r1,*r2;
		r1=temp->link;
		r2=(temp->link)->link;
		temp->link =r2->link;
		free(r1);
		free(r2);
	}


}
#if 0
void printmiddle(struct Nodeint*headref)
{

    struct Nodeint*temp = headref;
    int c = 0,m,l=-1;
    c = Count(headref);
    temp = headref;

    if(c%2==0)
    {
        m = (c/2);
        l=(c/2)+1;
    }
    else
    {
        m=(c+1)/2;
    }

    int s =0;
    while(s!=m-1)
    {
        temp =temp->link;
        s++;
    }


    if(l==-1)
    {
        struct Nodeint* r;
        //r=temp->link;
		r =temp;
        temp->link =r->link;
		printf("%i\n",r->val);
    }
    else
    {
        struct Nodeint* r1,*r2;
        r1=temp->link;
        r2=((temp->link)->link);
        temp->link =r2->link;
        printf("%i %i\n",r1->val,r2->val);
    }


}
#endif
void Reverse(struct Nodeint** headref)
{
	struct Nodeint* prev ,* next,* current;
	prev=next= NULL;
	current = *headref;
	while(current!=NULL)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	*headref= prev;
}

void SplitList(struct Nodeint* headref)
{


    struct Nodeint*temp = headref;
    int c = 0,m,l=-1;
    c = Count(headref);
    temp = headref;

    if(c%2==0)
    {
        m = (c/2);
        l=0;
    }
    else
    {
        m=(c+1)/2;
    }

    int s =0;
    while(s!=m-2)
    {
        temp =temp->link;
        s++;
    }


    if(l==-1)
    {
        struct Nodeint* r;
        r=temp->link;
        temp->link =NULL;
		struct Nodeint* headref2 = r->link;
        free(r);
		Display(headref);
		Display(headref2);
    }
    else
    {
        struct Nodeint* r1,*r2;
        r1=temp->link;
        r2=(temp->link)->link;
        r1->link= NULL;
        Display(headref);
        Display(r2);
    }


}
void DetectRep(struct Nodeint* headref)
{
	struct Nodeint*temp =headref;
	struct Nodeint*r ;

	while(temp->link!=NULL)
	{
		if((temp->val)== ((temp->link)->val))
		{
			r = temp->link;
			temp->link = r->link;
			free(r);
		}
		temp=temp->link;
	}
	Display(headref);
}



	


