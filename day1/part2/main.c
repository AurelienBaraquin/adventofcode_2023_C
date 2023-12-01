#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>

typedef struct number {
    char *str;
    int n;
} number_t;

const number_t numbers[] = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
};

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int get_number(const char *str) {
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        if (strncmp(str, numbers[i].str, strlen(numbers[i].str)) == 0) {
            return numbers[i].n;
        }
    }
    return -1;
}

int get_first_digit(char *str) {
    for (int i = 0; str[i]; i++) {
        if (is_digit(str[i])) {
            return str[i] - '0';
        }
        int num = get_number(&str[i]);
        if (num != -1) {
            return num;
        }
    }
    return -1;
}

int get_last_digit(char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (is_digit(str[i])) {
            return str[i] - '0';
        }
        int num = get_number(&str[i]);
        if (num != -1) {
            return num;
        }
    }
    return -1;
}

char **getlines(int *size)
{
    char **lines = NULL;
    int capacity = 0;
    int i = 0;
    while (1) {
        if (i == capacity) {
            capacity = capacity ? capacity * 2 : 1;
            char **tmp = realloc(lines, capacity * sizeof(char *));
            if (!tmp) {
                perror("realloc");
                return NULL;
            }
            lines = tmp;
        }

        char *line = NULL;
        size_t n = 0;
        ssize_t len = getline(&line, &n, stdin);
        if (len == -1) {
            free(line);
            break;
        }
        lines[i++] = line;
    }
    *size = i;
    return lines;
}

int main(void)
{
    int size = 0;
    char **lines = getlines(&size);
    if (!lines)
        return 1;
    
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += get_first_digit(lines[i]) * 10 + get_last_digit(lines[i]);
    }

    printf("%d\n", res);

    for (int i = 0; i < size; i++)
        free(lines[i]);
    free(lines);
    return 0;
}