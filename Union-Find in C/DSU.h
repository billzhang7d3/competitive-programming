#include <stdbool.h>
#include "Node.h"
typedef struct dsuObj* DSU;

DSU newDSU(int n);
void freeDSU(DSU *pDSU);

int getRoot(DSU dsu, int elem);
void unite(DSU dsu, int dstInd, int srcInd);
bool united(DSU dsu, int elem1, int elem2);
