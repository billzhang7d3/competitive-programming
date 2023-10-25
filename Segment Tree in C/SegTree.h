typedef struct STO* SegTree;

//each ST will need it's own unique arr fgh
SegTree createST(int start, int end, int *arr);

void freeST(SegTree *pST);

//inclusive
int rangeSum(SegTree st, int start, int end);

void update(SegTree st, int index, int value);
