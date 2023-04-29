/*
** EPITECH PROJECT, 2022
** BSQ.h
** File description:
** BSQ.h
*/

#ifndef BSQ_H_
    #define BSQ_H_
    #include "my_map.h"
    #include "square.h"

int find_size_square(char **map, int nb_rows, int nb_cols);

void my_new_map(map_t map);

void check_all_char(map_t map, int length);

void usage();

#endif /* !BSQ_H_ */
