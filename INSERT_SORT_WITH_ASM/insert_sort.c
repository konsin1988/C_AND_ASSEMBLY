#include "insert_sort.h"
#include "std.h"

int* allocate_memory( int N )
{
	int* arr = (int*)malloc( N * sizeof(int));
	return arr;
}

void random_fill( int* arr, int N, int LOW, int HIGH )
{
	srand(time(NULL));
	for( size_t i=0; i<N; ++i )
	{
		arr[i] = (int)(rand()%(HIGH - LOW) + LOW);
	}
}

void arr_copy_func( int* arr, int* arr_copy, int N )
{
	for( size_t i=0; i<N; ++i )
	{
		arr_copy[i] = arr[i];
	}
}

void insert_sort_C( int* arr, int N )
{
	int tmp;
	size_t i, j;
	for( i = 1; i<N; ++i)
	{
		j = i;
		while( j>0 && arr[j] < arr[j-1] )
		{
			tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
			--j;
		}
	}
}

void print_array( int* arr, int N, char* array_type )
{
	if( yes_no(array_type) )
	{
		printf("\n\t\t+++ Array %s: +++\n", array_type );
		for( size_t i = 0; i<N; ++i )
			printf("%3d ", arr[i]);
		printf("\n");
	}	
}

int yes_no( char* array_type )
{
	printf("\n>>> Do you want to print array %s? (y/n)\n", array_type);
	char key = my_getch();
	do
	{
		if(key=='y') return 1;
		else if(key=='n') return 0;
		else 
		{
			printf("\nPress 'y' for yes answer, "
				"'n' for abort.\n");
			key=my_getch();
		}
	}
	while(1);
}

void print_conclusions( double spent_time_C, double spent_time_ASM )
{
	printf("\n\n>>> Average running time of a function 'insert sort', \n\t"
		"written in C:\t%lf sec.\n"
		"\n\n>>> Average running time of a function 'insert sort', \n\t"
		"written in assembly:\t%lf sec.\n",
		spent_time_C, spent_time_ASM);
	printf("\n.. Press any key for continue ...\n");
	my_getch();
}
	
