/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** new map
*/

#include "./../include/my.h"
#include "./../include/square.h"
#include "./../include/my_bsq.h"

int size_square(char **map, int row, int col, int size)
{
    if (map[row][col] > size){
        size = map[row][col];
    }

    return (size);
}

square_t find_first_appearance(map_t map, int size, square_t first_bsq)
{
    for (map.col = 0; map.col < map.nb_cols; map.col++){
        if (map.map[map.row][map.col] == size){
            first_bsq.first_appearance = 1;
            first_bsq.row = map.row;
            first_bsq.col = map.col;
            break;
        }
    }
    return (first_bsq);
}

square_t find_first_bsq(map_t map)
{
    int size = 0;

    square_t first_bsq;
    first_bsq.size = 0;
    first_bsq.row = 0;
    first_bsq.col = 0;
    for (int row = map.nb_rows; row >= 1; row--){
        for (int col = map.nb_cols; col >= 0; col--){
            first_bsq.size = size_square(map.map, row, col, first_bsq.size);
        }
    }
    size = first_bsq.size;
    for (map.row = 0; map.row <= map.nb_rows; map.row++){
        first_bsq = find_first_appearance(map, size, first_bsq);
        if (first_bsq.first_appearance == 1){
            break;
        }
    }

    return (first_bsq);
}

void fill_new_map(char **map, int row, int col)
{
    if (map[row][col] > 0 && map[row][col] < 9){
        map[row][col] = '.';
    } else if (map[row][col] == 0){
        map[row][col] = 'o';
    }
}

void my_new_map(map_t map)
{
    square_t bsq = find_first_bsq(map);
    int row = bsq.row;
    int col = bsq.col;
    int size = bsq.size;

    for (int i = size - 1; i >= 0; i--){
        for (int j = size - 1; j >= 0; j--){
            map.map[row - i][col - j] = 'x';
        }
    }

    for (int row = 1; row <= map.nb_rows; row++){
        for (int col = 0; col < map.nb_cols; col++){
            fill_new_map(map.map, row, col);
        }
    }
}
