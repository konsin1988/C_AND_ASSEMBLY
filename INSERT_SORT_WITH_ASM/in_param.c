#include "std.h"

int in_param( int argc, char** argv, int* N, int* LOW, int* HIGH )
{
	if(argc<=1)
	{
		printf("\n\t%s requires more parameters.\n"
			"\tSee '--help' for more information.\n", argv[0]);
	}
	else if(!strcmp(argv[1], "--help"))
	{
		print_help(argv);
	}
	else if( argc != 4 || sscanf( argv[1], "%d", N ) != 1 ||
		sscanf( argv[2], "%d", LOW) != 1 ||
		sscanf( argv[3], "%d", HIGH) != 1 )
	{
		printf("\n\t%s requires three integer arguments\n");
	}
	else
		return 1;
	return 0;
}

