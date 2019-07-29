typedef struct N {
	int data;
	struct N* next;
}Node;

void PrintList( Node* n);
void DeleteList(Node**Head);
void AddFrontNode(Node**Head,int NewData);
void AddTailNode(Node**Head,int NewData);
void AddNode(Node**Head,int NewData,int Position);
void DeleteNode(Node**Head,int Position);
