#include "tarea2.h"



struct priqueue {
    PriComparator compare;
    int maxsize, size;
    void **ar;
};

PriQueue* makeFullPriQueue(int iniSize, PriComparator compare) {
    PriQueue *q = malloc(sizeof(PriQueue));
    q->compare= compare;
    q->maxsize= iniSize;
    q->size= -1;
    q->ar= malloc(iniSize*sizeof(void*));
    return q;
}

typedef struct {
    double pri;
    void *elem;
} PriObj;

static int priCmpFun(void *elemA, void *elemB) {
    PriObj *a= elemA;
    PriObj *b= elemB;
    double cmp= b->pri-a->pri;
    return cmp>0 ? 1 : (cmp<0 ? -1 : 0);
}

PriQueue *makePriQueue(void) {
    return makeFullPriQueue(16, priCmpFun);
}

void *priPeek(PriQueue *q) {
    PriObj *priobj= fullPriPeek(q);
    return priobj==NULL ? NULL : priobj->elem;
}

double priBest(PriQueue *q) {
    PriObj *priobj= fullPriPeek(q);
    return priobj==NULL ? 0 : priobj->pri;
}

void *priGet(PriQueue *q) {
    PriObj *priobj= fullPriGet(q);
    if (priobj==NULL)
        return NULL;
    else {
        void *res= priobj->elem;
        free(priobj);
        return res;
    }
}

void priPut(PriQueue *q, void *elem, double pri) {
    PriObj *priobj= malloc(sizeof(PriObj));
    priobj->pri= pri;
    priobj->elem= elem;
    fullPriPut(q, priobj);
}

int priDel(PriQueue *q, void *elem) {
    int k= 0;
    PriObj *priobj;
    while (k<=q->size) {
        priobj= q->ar[k];
        if (priobj->elem==elem)
        break;
        k++;
    }
    if (k>q->size)
        return 1;

    q->ar[k]= q->ar[q->size];
    q->size--;
    if (k<q->size)
        shiftDown(q, k);
    free(priobj);
    return 0;
}