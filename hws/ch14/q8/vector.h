#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} vector;

static int check_and_increase_capacity(vector *v)
{
    if (v->size < v->capacity)
        return 0;
    v->capacity *= 2;
    v->data = (int *)realloc(v->data, sizeof(int) * v->capacity);

    // Check if realloc failed
    if (!v->data)
        return 1;
    return 0;
}

int push_back(vector *v, int value)
{
    if (check_and_increase_capacity(v))
        return 1;
    v->data[v->size++] = value;
    return 0;
}

vector *create_vector()
{
    vector *v = (vector *)malloc(sizeof(vector));
    if (!v)
        return NULL;

    v->size = 0;
    v->capacity = 4;
    v->data = (int *)malloc(sizeof(int) * v->capacity);
    if (!v->data)
    {
        free(v);
        return NULL;
    }
    return v;
}

void print_vector(vector *v)
{
    printf("[ ");
    for (int i = 0; i < v->size; i++)
        printf("%d ", v->data[i]);
    printf("]\n");
}

void free_vector(vector *v)
{
    free(v->data);
    free(v);
}