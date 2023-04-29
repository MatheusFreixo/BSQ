/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/

#include "./../include/my.h"
#include "./../include/my_bsq.h"
#include "./../include/square.h"
#include "./../include/my_map.h"

void check_obstacles(char **map, int row, int col, int nb)
{
    if (map[row][col] == '.'){
        nb = 1;
        map[row][col] = nb;
    }else if (map[row][col] == 'o'){
        nb = 0;
        map[row][col] = nb;
    }
}

void fill_map(char *buf)
{
    map_t map;
    square_t bsq;
    map.map = my_str_to_word_array(buf, '\n');
    map.nb_rows = my_getnbr(map.map[0]);
    map.nb_cols = my_strlen(map.map[1]);
    int length = map.nb_cols * map.nb_rows;
    int nb = 0, row = 1, col = 0, size = 0;
    for (row = 1; map.map[row] != NULL; row++){
        for (col = 0; map.map[row][col] != '\0'; col++){
            check_obstacles(map.map, row, col, nb);
        }
        nb = 0;
    }
    check_all_char(map, length);
    my_new_map(map);
    for (row = 1; row <= map.nb_rows; row++){
        my_putstr(map.map[row]);
        my_putchar('\n');
    }
}

int open_file(char *filepath)
{
    struct stat stats;
    stat(filepath, &stats);
    int fd, nb_rows = 0, nb_cols = 0, count = 0, length = 0;
    char *buf = malloc(sizeof(char) * stats.st_size + 1);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    read(fd, buf, stats.st_size);
    fill_map(buf);
    close(fd);
    free(buf);
    return (fd);
}

int main (int argc, char **argv)
{
    if (argc == 1 || my_strcmp(argv[1], "-h") == 0){
        usage();
        return (1);
    }
    open_file(argv[1]);

    return (0);
}
