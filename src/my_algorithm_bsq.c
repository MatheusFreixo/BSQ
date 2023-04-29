/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** main
*/

#include "./../include/my.h"
#include "./../include/my_map.h"

void check_space_around(map_t map, int row, int col, int index)
{
    if (map.map[row][col] >= index && (map.map[row][col + 1] >= index &&
    map.map[row + 1][col] >= index && map.map[row + 1][col + 1] >= index)) {
        map.map[row + 1][col + 1]++;
    }
}

void my_algorithm(map_t map, int index)
{
    for (int row = 1; row <= map.nb_rows; row++){
        for (int col = 0; col < map.nb_cols; col++){
            check_space_around(map, row, col, index);
        }
    }
}

void check_all_char(map_t map, int length)
{
    if (length < 50000){
        for (int index = 1; index <= 200; index++){
            my_algorithm(map, index);
    }
    }else {
        for (int index = 1; index <= 20; index++){
            my_algorithm(map, index);
        }
    }
}
