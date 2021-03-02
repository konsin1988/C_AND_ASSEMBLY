#include "std.h"

/* The number of elements of the array */
int N;

/* The lowest and the highest elements of the array */
int LOW, HIGH;

/* Start and and of 'insert sort' function. */
clock_t BEGIN, END;

/* Sum running time for 10 times. */
double spent_time_C = 0; 
double spent_time_ASM = 0;

int main(int argc, char** argv)
{
	if( in_param(argc, argv, &N, &LOW, &HIGH) )
	{
		/* Beginning */
		int* arr = allocate_memory(N);
		int* arr_copy = allocate_memory(N);

		/* Сycle of ten repetitions */
		for( size_t i=0; i<10; ++i )
		{
			random_fill( arr, N, LOW, HIGH );
			arr_copy_func( arr, arr_copy, N );

			/* If you want to see results  */
			/* print_array( arr, N, "original" ); */
			
			/* C function in work */
			BEGIN = clock();
			insert_sort_C(arr, N);
			END = clock();
			spent_time_C += (double)(END - 
					BEGIN) / CLOCKS_PER_SEC;

			/* If you want to see results  */
			/* print_array(arr, N, "sorted (C function)"); */
			
			/* Assembler in work */
			BEGIN = clock();
			insert_sort_asm(arr_copy, N);
			END = clock();
			spent_time_ASM += (double)(END - 
					BEGIN) / CLOCKS_PER_SEC;

			/* If you want to see results  */
			/* print_array(arr_copy, N, "sorted (ASM)"); */
		}

		/* Conclusion */
		print_conclusions( spent_time_C/10, 
				 spent_time_ASM/10 );
		free(arr);
		free(arr_copy);
	}

	return 0;
}
	
