#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	char *micePath = "/dev/input/mice";
	unsigned char left, right, middle;

	int fd = open(micePath, O_RDONLY);
	char data[3];

	if(fd < 0){
		printf("file open error");
		return 1;
	}

	while(read(fd, &data, sizeof(data)) > 0){
		left = data[0] & 0x1;
		right = data[0] & 0x2;
		middle = data[0] & 0x4;

		printf("x=%d, y=%d, button: left=%d, right=%d \n", data[1], data[2], left, right);
	}

	return 0;
}
