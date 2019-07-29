#include <stdlib.h>

typedef struct N {
	int data;
	struct N* next;
}Node;

void PrintList( Node* n)
{
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
	printf(" # ");
}

void DeleteList(Node**Head)
{
    Node*n=*Head;
    Node*m;
    while (n!=NULL)
    {
        m=n->next;
        free(n);
        n=m;
    }
    *Head=NULL;
}
void AddFrontNode(Node**Head,int NewData)
{
    Node* newhead = (Node*)malloc(sizeof(Node));
    newhead->data = NewData;
    newhead->next = *Head;
    *Head = newhead;
}
void AddTailNode(Node**Head,int NewData)
{
    Node* NewTail = (Node*)malloc(sizeof(Node));
    NewTail->data = NewData;
    NewTail->next = NULL;
    if (*Head==NULL)
    {
        *Head = NewTail ;
        return;
    }
    else
    {
        Node* Tail= *Head;
        while ( (Tail->next)!=NULL )
        {
            Tail=Tail->next;
        }
        Tail->next=NewTail;
    }
}
void AddNode(Node**Head,int NewData,int Position)
{
    int i=1;
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = NewData;
    NewNode->next = NULL;
    if(Position==0)
    {
        printf("ERROR : Position Start From 1\n");
    }
    else if (Position==1)
    {
        NewNode->next = *Head;
        *Head = NewNode;
    }
    else
    {
       Node*n = *Head;
       Node*m ;
       while(n!=NULL && i<Position)
       {
           i++;
           m = n;
           n = n->next;
       }
       m->next=NewNode;
       NewNode->next=n;
    }
}

void DeleteNode(Node**Head,int Position)
{
    int i=1;
    Node*n = *Head;
    Node*m ;
    if (Position==0)
    {
        printf("ERROR : Position Start From 1\n");
    }
    else if (Position==1)
    {
        *Head=n->next;
        free(n);

    }
    else
    {
        while(n!=NULL && i<Position)
        {
            i++;
            m = n;
            n = n->next;
        }
        m->next=n->next;
        free(n);
    }

}

int ListLenght(Node*Head)
{
    int i=0;
    while(Head!=NULL)
    {
        Head=Head->next;
        i++;
    }
    return i;
}

