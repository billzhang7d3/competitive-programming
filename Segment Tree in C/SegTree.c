#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SegTree.h"

typedef struct STO {
    int start, end, sum, *arr;
    struct STO *left, *right;
} STO;

typedef STO* SegTree;

//each ST will need it's own unique arr, this can probably be optimized
SegTree createST(int start, int end, int *arr) {
    //printf("start: %d, end: %d\n", start, end);
    SegTree st = (SegTree) malloc(sizeof(STO));
    st->sum = 0;
    st->start = start;
    st->end = end;
    st->arr = (int *) malloc((end - start + 1) * sizeof(int));
    for (int i = start; i <= end; ++i) {
        st->arr[i - start] = arr[i];
        st->sum += arr[i];
    }
    if (start < end) {
        st->left = createST(start, (end + start) / 2, arr);
        st->right = createST((end + start) / 2 + 1, end, arr);
    }
    return st;
}

void freeST(SegTree *pST) {
    if ((*pST)->left) { freeST(&((*pST)->left)); }
    if ((*pST)->right) { freeST(&((*pST)->right)); }
    free((*pST)->arr);
    (*pST)->arr = NULL;
    free(*pST);
    *pST = NULL;
}

//inclusive
//both start and end should always be contained in (st->start, st->end)
int rangeSum(SegTree st, int start, int end) {
    //obvious case
    if (st->start == start && st->end == end) { return st->sum; }
    //not so obvious cases
    if (start >= st->left->start && start <= st->left->end) {
        if (end < st->right->start) {
            return rangeSum(st->left, start, end);
        } else {
            return rangeSum(st->left, start, st->left->end) + rangeSum(st->right, st->right->start, end);
        }
    } else {
        return rangeSum(st->right, start, end);
    }
    printf("THERE'S NO WAY IT ACTUALLY GOT HERE LMAO\n");
    return 0;
}

void update(SegTree st, int index, int value) {
    if (st->start <= index && st->end >= index) {
        /*printf("value: %d\n", value);
        printf("index: %d\n", index);
        printf("diff: %d\n", st->arr[index - st->start]);*/
        st->sum += value - st->arr[index - st->start];
        st->arr[index - st->start] = value;
        if (st->left) { update(st->left, index, value); }
        if (st->right) { update(st->right, index, value); }
    }
}
