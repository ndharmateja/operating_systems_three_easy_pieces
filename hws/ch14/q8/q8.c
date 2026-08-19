#include "vector.h"
#include "linked_list.h"

void run_vector_code()
{
    vector *v = create_vector();
    if (!v)
    {
        printf("Error creating vector.");
        return;
    }

    print_vector(v);
    for (int i = 0; i < 10; i++)
    {
        if (push_back(v, i))
        {
            printf("Error appending to vector.");
            free_vector(v);
            return;
        }
        print_vector(v);
    }

    free_vector(v);
}

void run_linked_list_code()
{
    linked_list *l = create_linked_list();
    if (!l)
    {
        printf("Error creating linked_list.");
        return;
    }
    printf("Linked list created.");

    print_linked_list(l);
    for (int i = 0; i < 10; i++)
    {
        if (insert_last(l, i))
        {
            printf("Error appending to linked_list.");
            free_linked_list(l);
            return;
        }
        print_linked_list(l);
    }

    free_linked_list(l);
}

int main()
{
    run_vector_code();
    run_linked_list_code();

    return 0;
}