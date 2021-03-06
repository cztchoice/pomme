/*
 * =====================================================================================
 *
 *       Filename:  pomme_serilize.c
 *
 *    Description:  the implement of serilize
 *
 *        Version:  1.0
 *        Created:  03/20/2012 11:12:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#include "pomme_serilize.h"
extern int errno;
int read_data(pomme_data_t *wt, int handle)
{
    int ret = 0;
    int tl = 0;
    ssize_t st = read(handle, &tl, sizeof(int));
    if( st < 0 )
    {
	debug("read error %s",strerror(errno));
    }
    int readed = 0;

    pomme_data_init(&wt, tl);
    unsigned char *pb = wt->data;
    while( ( st = read(handle, pb+readed, tl) ) >= 0 )
    {
	readed += st;
    } 
    assert( readed == tl );
   return ret;
}

int write_data(pomme_data_t *wt, int handle)
{
    int ret = 0;
    int wrl = 0;

    ssize_t wl = write(handle, &wt->size, sizeof(int));

    wl = write(handle, wt->data, wt->size);

    assert(wl == wt->size);
    return ret;
}
