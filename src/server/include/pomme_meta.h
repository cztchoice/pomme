/*
 * =====================================================================================
 *
 *       Filename:  pomme_meta.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2011 06:15:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#ifndef POMME_META_H
#define POMME_META_H

#define MAX_STORE_FILE_NAME_LENGTH 256

typedef struct pomme_object
{
	u_int32	sfid;// the id of the storefile
	u_int64 offset;// the offset of the object in the file
	u_int64 length;// the dataLength of the object
	time_t time;// the create time of the object on this server
	u_int16 version;//reserved
}pomme_object_t;
typedef struct pomme_local_file
{
	u_int64 id;
	int8 path[MAX_STORE_FILE_NAME_LENGTH];
}pomme_local_file_t;

#endif
