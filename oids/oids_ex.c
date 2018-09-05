#include <r_util.h>
#include <r_types.h>
#include <stdlib.h>

bool my_free(void *user, void *data, ut32 id) {
	free (data);
	return true;
}

int main (int argc, char *argv[]) {
	ut32 i, id, od;
	char *ptr;
	ROIDStorage *oids;

	if (argc < 2) {
		return 0;
	}
	oids = r_oids_new (8, 8 + argc);

	for (i = 1; i < argc; i++) {
		r_oids_add (oids, strdup (argv[i]), &id, &od);
	}

	od = 0;
	while (!!(ptr = r_oids_oget(oids, od))) {
		r_oids_get_id (oids, od, &i);
		printf ("od: %d\tid: %d\tstring: %s\n", od, i, ptr);
		od++;
	}

	r_oids_foreach (oids, my_free, NULL);
	r_oids_free (oids);
	return 0;
}
