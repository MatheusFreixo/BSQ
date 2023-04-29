/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** Square struct
*/

#ifndef SQUARE_H_
    #define SQUARE_H_

typedef struct square {
    int row;
    int col;
    int size;
    int first_appearance;
    char **map;
}   square_t;

#endif /* !SQUARE_H_ */
