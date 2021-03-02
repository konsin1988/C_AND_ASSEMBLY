obj=insert_sort.o std.o in_param.o print_help.o my_getch.o 
insert_sort: main.c $(obj) insert_sort_asm.S print_char.S print_number.S
	gcc -c insert_sort_asm.S -o insert_sort_asm.o
	gcc -c print_char.S -o print_char.o
	gcc -c print_number.S -o print_number.o
	gcc main.c $(obj) insert_sort_asm.o print_char.o print_number.o -o $@

clean:
	rm *.o

run: insert_sort
	./insert_sort
	
