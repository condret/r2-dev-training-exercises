#include <r_util.h>
#include <r_io.h>

int main (int argc, char *argv[]) {
	RIO *io = r_io_new ();
	ut8 buf[16];
	int i, fd = r_io_fd_open (io, argv[0], R_IO_READ, 0644);

	r_io_fd_read_at (io, fd, 0LL, buf, 16);
	for(i = 0; i < 16; i++) {
		printf ("%02x ", buf[i]);
	}
	putchar ('\n');
	r_io_fd_close (io, fd);
	r_io_free (io);
	return 0;
}	
