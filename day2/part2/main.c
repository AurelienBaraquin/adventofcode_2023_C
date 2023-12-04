#include "class.h"

typedef struct drawing {
    int red;
    int green;
    int blue;
} drawing_t;

const char colors[3][6] = {
    "red",
    "green",
    "blue"
};

int parse(String *str)
{
    drawing_t tmp_draw = {0, 0, 0};
    String **reroll = str->split_c(str, ";");
    if (!reroll)
        return 0;
    
    for (size_t i = 0; reroll[i]; i++) {
        String **tmp = reroll[i]->split_c(reroll[i], ",");
        if (!tmp)
            return 0;
        for (size_t j = 0; tmp[j]; j++) {
            int nb = tmp[j]->to_int(tmp[j]);
            for (int k = 0; k < 3; k++) {
                if (tmp[j]->contains_c(tmp[j], colors[k])) {
                    if (k == 0 && nb > tmp_draw.red)
                        tmp_draw.red = nb;
                    else if (k == 1 && nb > tmp_draw.green)
                        tmp_draw.green = nb;
                    else if (k == 2 && nb > tmp_draw.blue)
                        tmp_draw.blue = nb;
                }
            }
        }
        free(tmp);
    }

    free(reroll);
    return tmp_draw.red * tmp_draw.green * tmp_draw.blue;
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

    for (size_t i = 0; arr[i]; i++) {
        arr[i] = arr[i]->sub_c(arr[i], arr[i]->find_c(arr[i], ":") + 1, arr[i]->size(arr[i]));
        total += parse(arr[i]);
    }

    printf("%d\n", total);

    free(arr);
}
