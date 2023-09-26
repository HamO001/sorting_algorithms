#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "listint.h"

void print_array(const int *array, size_t size);
/*void print_list(const listint_t *list);*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *prev, listint_t *temp);
void selection_sort(int *array, size_t size);
size_t partition(int *array, size_t low, size_t high);
void swap(int *a, int *b);
void quick_sort_helper(int *array, size_t size, size_t low, size_t high);
void quick_sort(int *array, size_t size);
#endif
