#include <dirent.h>
#include <stddef.h>
#include <string.h>

struct dirent* readdir(DIR *dirp) {
	if(dirp == NULL || dirp->offset >= dirp->num)
		return NULL;
	static struct dirent ret;
	uint32_t i = dirp->offset;
	ret.d_ino = dirp->kids[i].data;
	ret.d_off = dirp->offset;
	ret.d_type = dirp->kids[i].type;
	ret.d_reclen = dirp->kids[i].size;
	strncpy(ret.d_name, dirp->kids[i].name, FS_NODE_NAME_MAX-1);

	dirp->offset++;
	return &ret;
}

