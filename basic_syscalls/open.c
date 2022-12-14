#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void main() {
	int fd;
	fd = open("test_file.txt",O_CREAT|O_RDWR, 0774);
	//when using O_CREAT do pass 3rd arg for perm bits of file.
	//since open is a variadic function, the implementaion checks for O_CREATE bit
	//if 3rd arg is not passed for O_CREAT, behaviour is undefined.
	if (fd)
		printf("file created, fd = %d", fd);
		return;

	printf("file open failed, fd=%d, err= %d",fd, errno);	
}

