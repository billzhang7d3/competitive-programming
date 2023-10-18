#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

typedef struct NodeObj {
    int value;
    NodeObj *parent;
    int storage, index;
    NodeObj **children;
} NodeObj;

typedef struct NodeObj* Node;

Node newNode(int value) {
    Node node = (Node) malloc(sizeof(NodeObj)); 
    node->value = value;
    node->parent = NULL;
    node->storage = 1;
    node->index = 0;
    node->children = (Node *) malloc(1 * sizeof(Node));
}

void freeNode(Node *pNode) {
    free((*pNode)->children);
    free(*pNode);
    *pNode = NULL;
}

void merge(Node srcNode, Node destNode) {
    if (srcNode->storage == srcNode->index) {
        srcNode->storage *= 2;
        srcNode->children = (Node *) realloc(srcNode->children, srcNode->storage * sizeof(Node));
    }
    while (destNode->parent) {
        destNode = destNode->parent;
    }
    srcNode->children[srcNode->index] = destNode;
    ++srcNode->index;
}

bool contains(Node node, int value) {
    while (node->parent) {
        node = node->parent;
    }
}