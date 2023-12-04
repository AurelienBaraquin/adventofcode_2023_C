#include "class.h"

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

bool is_symbol(char c)
{
    return c != '.' && !is_digit(c) && c != '\0';
}

bool has_adjacent(size_t i, size_t j, String **arr) {
    if (i > 0 && j > 0 && is_symbol(arr[i - 1]->at(arr[i - 1], j - 1)))
        return 1;

    if (i > 0 && j < arr[i - 1]->size(arr[i - 1]) - 1 && is_symbol(arr[i - 1]->at(arr[i - 1], j + 1)))
        return 1;

    if (j > 0 && is_symbol(arr[i]->at(arr[i], j - 1)))
        return 1;

    if (j < arr[i]->size(arr[i]) - 1 && is_symbol(arr[i]->at(arr[i], j + 1)))
        return 1;

    if (arr[i + 1] != NULL && j > 0 && is_symbol(arr[i + 1]->at(arr[i + 1], j - 1)))
        return 1;

    if (arr[i + 1] != NULL && j < arr[i + 1]->size(arr[i + 1]) - 1 && is_symbol(arr[i + 1]->at(arr[i + 1], j + 1)))
        return 1;

    if (i > 0 && is_symbol(arr[i - 1]->at(arr[i - 1], j)))
        return 1;

    if (arr[i + 1] != NULL && is_symbol(arr[i + 1]->at(arr[i + 1], j)))
        return 1;

    return 0;
}

int adjacent_symbols(size_t i, size_t *j, String **arr)
{
    int adjacents = 0;
    int number = arr[i]->to_int(arr[i]->sub_s(arr[i], *j, arr[i]->size(arr[i])));
    for (int k = 0; is_digit(arr[i]->at(arr[i], *j)); k++) {
        if (has_adjacent(i, *j, arr))
            adjacents++;
        (*j)++;
    }
    (*j)--;
    return adjacents > 0 ? number : 0;
}

int main(void)
{
    ENABLE_AUTO_FREE;
    ifStream *input = NEW(ifStream, "input");
    if (!input || !input->is_open)
        return 1;
    String *str = NEW(String, input->getall(input));
    if (!str)
        return 1;

    String **arr = str->split_c(str, "\n");
    if (!arr)
        return 1;
    
    int total = 0;
    
    for (size_t i = 0; arr[i] != NULL; i++) {
        for (size_t j = 0; arr[i]->at(arr[i], j) != '\0'; j++) {
            if (!is_digit(arr[i]->at(arr[i], j)))
                continue;
            total += adjacent_symbols(i, &j, arr);
        }
    }

    printf("%d\n", total);

    free(arr);
    return 0;
}
