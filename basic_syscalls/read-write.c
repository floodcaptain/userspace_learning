#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void main() {
	int fd;
	char buf[100];
	char read_buf[100] = {'0'};
	int len = 0;
	int rc = 0;
	ssize_t read_cnt = 0;
	// open/create file
	fd = open("test_file.txt",O_RDWR|O_CREAT, 0774);
	if(fd<0) {
		printf("open fail");
		goto fail;
	}

	strcpy(buf,"text written on the file after creation");
	len = strlen(buf);
	
	//write to the created file	
	rc = write(fd , buf,len);
	if(rc < 0) {
		printf("write fail, rc = %d", rc);
		goto fail;
	}

	printf("No. of bytes written %d \n", rc);

	// attempt to read from file
	read_cnt = read(fd,read_buf,len);
	if (read_cnt < 0) {
		printf("read failed");
		goto fail;
	}

	printf("read count: %llu\n",read_cnt);
	printf("[OUTPUT]:  %s",read_buf);
	return;

	
fail:	
	printf("fail, fd=%d, err= %d",fd, errno);
	return;
}

