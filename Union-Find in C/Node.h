typedef struct NodeObj* Node;

Node newNode(int value);
void freeNode(Node *pNode);

void merge(Node srcNode, Node destNode);
bool contains(Node refNode, int value);