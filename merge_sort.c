#include "merge_sort.h"

#define THREAD_COUNT 2

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./merge_sort input_file output_file\n");
    return 1;
  }

  // Open the input and output files
  char *input_file_name = argv[1];
  char *output_file_name = argv[2];
  FILE *input_file = fopen(input_file_name, "r");
  FILE *output_file = fopen(output_file_name, "w");

  // Read the array size and elements from the input file
  int array_size;
  fscanf(input_file, "%d", &array_size);
  int array[array_size];
  for (int i = 0; i < array_size; i++) {
    fscanf(input_file, "%d", &array[i]);
  }

  // Sort the array using threads
  ThreadArgs args = {array, 0, array_size - 1, 0, output_file};
  pthread_t thread;
  pthread_create(&thread, NULL, merge_sort, &args);
  pthread_join(thread, NULL);

  // Write the sorted array to the output file
  for (int i = 0; i < array_size; i++) {
    fprintf(output_file, "%d ", array[i]);
  }
  fprintf(output_file, "\n");

  // Close the file handles
  fclose(input_file);
