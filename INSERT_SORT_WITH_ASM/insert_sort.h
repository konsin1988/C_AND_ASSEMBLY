#pragma once

int in_param( int argc, char** argv, int* N, int* LOW, int* HIGH );
void print_help( char** argv );
extern void insert_sort_asm( int* arr, int N);
int* allocate_memory( int N );
void random_fill( int* arr, int N, int LOW, int HIGH );
void arr_copy_func( int* arr, int* arr_copy, int N );
void insert_sort_C( int* arr, int N );
void print_array( int* arr, int N, char* array_type );
int yes_no( char* array_type );
void print_conclusions( double spent_time_C, double spent_time_ASM );
int my_getch();
	
