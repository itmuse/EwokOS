#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/vfs.h>
#include <sys/vdevice.h>
#include <sys/syscall.h>

#define MAX_DUP_DEV 8

static int _fds[MAX_DUP_DEV]; 
static int _fds_num = 0;

static int dup_write(int fd, 
		int from_pid,
		fsinfo_t* info,
		const void* buf,
		int size,
		int offset,
		void* p) {
		
	(void)fd;
	(void)from_pid;
	(void)info;
	(void)offset;
	(void)p;

	int i;
	for(i=0; i<_fds_num; i++) {
		if(_fds[i] > 0)
			write(_fds[i], buf, size);
	}
	return size;
}

int main(int argc, char** argv) {
	if(argc < 3) {
		fprintf(stderr, "Error: target devices missed!\n"
				"Usage: dupd <mnt_point> {target devices}\n");
		return -1;
	}

	const char* mnt_point = argv[1];
	int i;
	for(i=0; i<MAX_DUP_DEV && i<(argc-2); i++) {
		_fds[i] = open(argv[i+2], O_WRONLY);
	}
	_fds_num = i;

	vdevice_t dev;
	memset(&dev, 0, sizeof(vdevice_t));
	strcpy(dev.name, "dup");
	dev.write = dup_write;

	device_run(&dev, mnt_point, FS_TYPE_CHAR);
	return 0;
}
