#include <unistd.h>
#include <string.h>
#include <stdio.h>

void main() {
	char buff[100];
	int len = 0;
	strncpy(buff,"this is the output of the buffer \n",99);
	len = strlen(buff);

	len = write(1,buff, len);
	
}

