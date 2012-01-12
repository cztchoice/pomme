/*
 * =====================================================================================
 *
 *       Filename:  pomme_storage.c
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  01/11/2012 06:22:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#include "utils.h"
#include "pomme_storage.h"


extern int file_count_strict;

static int get_dir_child_num(char *path, int *count);
static int create_local_file(char *path);

int create_storage(DB *db_handle,
	DB_TXN *txnid,
	char *storage_path,
	size_t *id)
{
    debug("");
    int ret = 0, count, len;
    unsigned int flags = 0;
    DBT key,val;

    if( storage_path == NULL )
    {
	storage_path = "./";
    }
    debug("%p %s ",storage_path,storage_path);

    len = strlen(storage_path) +20;
    debug("");
    char fullpath[len];

    debug("%s",storage_path);
    if( ( ret = get_dir_child_num(storage_path, &count) < 0 ))
    {
	debug("Create Storage failure");
	goto err;
    }
    strcpy( fullpath, storage_path);
    char *ptr = fullpath + strlen(storage_path) - 1;

    while(*ptr == '/') ptr--;

    *(ptr+1)='/';
    sprintf(ptr+1, "%d", count);

    memset(&key, 0, sizeof(key));
    memset(&val, 0, sizeof(val));

    val.data = fullpath;
    val.size = strlen(fullpath) + 1;


    flags |= DB_APPEND;

    ret = db_handle->put(db_handle, txnid, &key, &val, flags);
    if( ret < 0 )
    {
	debug("put to database fail");
    }
    *id = *(unsigned int *)(key.data);
err:
    return ret;
}


/**
 * @brief get_dir_child_num : get the number of the given directory
 *
 * @param path
 *
 * @return: 0 for success , < 0 for failure 
 */
static int get_dir_child_num(char *path,int *num)
{
    int ret , len, file_count = 0;
    struct stat statbuf;
    struct dirent *dirp = NULL;
    DIR *dp;


    if( (ret = lstat(path, &statbuf)) < 0 )
    {
	debug("lstat %s failure: %s",path,strerror(ret));
	ret =  POMME_LOCAL_DIR_ERROR;
	goto err;
    }

    if( S_ISDIR(statbuf.st_mode) == 0 )
    {
	debug("%s is not a dir",path);
	ret = POMME_LOCAL_DIR_ERROR;
	goto err;
    }
	
    len = strlen(path);
    if( path[len-1] != '/' )
    {
	path[len]='/';
	path[len+1] = 0;
    }

    if( ( dp = opendir( path ) ) == NULL )
    {
	debug("open %s fail",path);
	ret =  POMME_LOCAL_DIR_ERROR;
	goto err;
    }

    while( ( dirp = readdir(dp)) != NULL )
    {
	if( (strcmp(dirp->d_name, ".") == 0 )
		|| (strcmp( dirp->d_name, "..") == 0)
	  )
	{
	    continue;
	}
	file_count ++;
    }
    *num =  file_count;
    ret = POMME_SUCCESS;
err:
    return ret;

}
static int create_local_file(char *path)
{
    int ret = 0;
    if( 

err:
   return ret; 
}