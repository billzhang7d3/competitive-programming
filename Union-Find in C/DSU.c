#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DSU.h"
#include "Node.h"

typedef struct dsuObj {
    int n, numSets;
    Node *trees;
    int *unitedTo;
}

typedef struct dsuObj* DSU;

DSU newDSU(int n) {
    DSU dsu = (DSU) malloc (sizeof(dsuObj));
    dsu->n = n;
    dsu->numSets = n;
    dsu->trees = (Node) malloc((dsu->n + 1) * sizeof(NodeObj));
    dsu->unitedTo = (int *) malloc((dsu->n + 1) * sizeof(int));
    dsu->trees[0] = NULL;
    dsu->unitedTo[0] = -1;
    for (int i = 1; i <= dsu->n; ++i) {
        dsu->trees[i] = newNode(i);
        dsu->unitedTo[i] = i;
    }
    return dsu;
}

void freeElement(Node *pNode) {
    for (int i = 0; i < (*pNode)->index; ++i) {
        freeElement(&((*pNode)->children[i]));
    }
    freeNode(pNode);
    *pNode = NULL;
}
void freeDSU(DSU *pDSU) {
    for (int i = 0; i < (*pDSU)->n; ++i) {
        if ((*pDSU)->trees[i]) {
            freeElement(&((*pDSU)->trees[i]));
        }
    }
    free(pDSU->trees);
    pDSU->trees = NULL;
    free(pDSU);
    pDSU = NULL;
}

int getRoot(DSU dsu, int elem) {
    return dsu->unitedTo[elem];
}

void setParent(DSU dsu, Node node, int newParent) {
    for (int i = 0; i < node->index; ++i) {
        setElement(dsu, node->children[i], newParent);
    }
    dsu->unitedTo[node->value] = newParent;
}
void unite(DSU dsu, int dstInd, int srcInd) {
    int root1 = getRoot(dstInd), root2 = getRoot(srcInd);
    setParent(dsu, dsu->tree[root1], root1);
    merge(dsu->trees[root1], dsu->trees[root]);
    dsu->trees[root2] = NULL;
}

bool united(DSU dsu, int elem1, int elem2) {
    retrn getRoot(elem1) == getRoot(elem2);
}