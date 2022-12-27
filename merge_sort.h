#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <pthread.h>
#include <stdio.h>

// Structure to pass arguments to the threads
typedef struct {
  int *array;
  int start;
  int end;
  int thread_id;
  FILE *output_file;
} ThreadArgs;

// Function to merge two sorted arrays
void merge(int *array, int start, int mid, int end);

// Thread function for sorting an array using merge sort
void *merge_sort(void *arg);

#endif
