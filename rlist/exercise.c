#include <stdio.h>
#include <r_types.h>
#include <r_list.h>

int main (int argc, char *argv[]) {
	ut32 i;
	RList *mylist;
	char *ptr;

	if (argc < 2) {
		return 0;
	}

	mylist = r_list_new();
	for (i = 1; i < argc; i++) {
		ptr = strdup (argv[i]);
		
		r_list_prepend (mylist, ptr);
	}

	while (ptr = r_list_pop(mylist)) {
		puts (ptr);
		free (ptr);
	}

	r_list_free(mylist);

	return 0;
}
