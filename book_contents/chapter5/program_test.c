#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define OP *
#define IDENT 1

long DATA_SIZE = 1000000;

typedef long data_t;

typedef struct {
    long len;
    data_t *data;
} vec_rec, *vec_ptr;

vec_ptr new_vec(long len) {
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    data_t *data = NULL;

    if (!result) {
        return NULL;
    }

    result->len = len;

    if (len > 0) {
        data = (data_t *) calloc(len, sizeof(data_t));
        if (!data) {
            free((void *) result);
            return NULL;
        }
    }
    result->data = data;
    return result;
}

void vec_data(vec_ptr v) {
    long len = v->len;
    data_t *data = v->data;
    int op = 1 OP 0;
    for (long i = 0; i < len; i++)
    {
        if (op) {
            data[i] = (data_t) i+1;
        } else {
            data[i] = (data_t) 1;
        }
    }
}

int get_vec_element(vec_ptr v, long index, data_t *dest) {
    if (index < 0 || index >= v->len) {
        return 0;
    }
    *dest = v->data[index];
    return 1;
}

long vec_length(vec_ptr v) {
    return v->len;
}

data_t *get_vec_start(vec_ptr v) {
    return v->data;
}


void combine1(vec_ptr v, data_t *dest) {
    long i;

    *dest = IDENT;
    for (i = 0; i < vec_length(v); i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }
}

void combine2(vec_ptr v, data_t *dest) {
    long i;
    long len = vec_length(v);

    *dest = IDENT;
    for (i = 0; i < len; i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }
}


void combine3(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        *dest = *dest OP data[i];
    }
}

void combine4(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    for (i = 0; i < length; i++) {
        acc = acc OP data[i];
    }
    
    *dest = acc;
}

void combine4b(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    data_t acc = IDENT;

    for (i = 0; i < length; i++) {
        if (i >= 0 && i < v->len) {
            acc = acc OP v->data[i];
        }
    }
    
    *dest = acc;
}

void combine5(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t* data = get_vec_start(v);
    data_t  acc = IDENT;

    for (i = 0; i < limit; i += 2) {
        acc = (acc OP data[i]) OP data[i+1];
    }

    for (; i < length; i++) {
        acc = acc OP data[i];
    }

    *dest = acc;
}

void combine6(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t* data = get_vec_start(v);
    data_t  acc1 = IDENT;
    data_t  acc2 = IDENT;

    for (i = 0; i < limit; i += 2) {
        acc1 = acc1 OP data[i];
        acc2 = acc2 OP data[i+1];
    }

    for (; i < length; i++) {
        acc1 = acc1 OP data[i];
    }

    *dest = acc1 OP acc2;
}

void combine7(vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t* data = get_vec_start(v);
    data_t  acc = IDENT;

    for (i = 0; i < limit; i += 2) {
        acc = acc OP (data[i] OP data[i+1]);
    }

    for (; i < length; i++) {
        acc = acc OP data[i];
    }

    *dest = acc;
}

void minmax1(long a[], long b[], long n) {
    long i;
    for (i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            long t = a[i];
            a[i] = b[i];
            b[i] = t;
        }
    }
}

void minmax2(long a[], long b[], long n) {
    long i;
    for (i = 0; i < n; i++) {
        int min = a[i] > b[i] ? b[i] : a[i];
        int max = a[i] > b[i] ? a[i] : b[i];
        a[i] = min;
        b[i] = max;
    }
}


int main() {
    clock_t t1, t2;

    vec_ptr vec = new_vec(DATA_SIZE);
    vec_data(vec);
    data_t *data;

    t1 = clock();
    combine4(vec, data);
    t2 = clock();

    printf("program test result: %d\n", (t2 - t1));
    return 0;
}


