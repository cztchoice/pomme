/*
 * =====================================================================================
 *
 *       Filename:  pomme_msg.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/17/2012 09:38:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#include "pomme_msg.h"
#include "utils.h"

int pomme_send(int handle, void *buffer, 
	int len, int flags)
{
	int ret = 0;
	assert(buffer != NULL );
	if( len <= 0 )
	{
	    debug("len <= 0 ");
	    ret = POMME_WRONG_ARG;
	    goto err;
	}
	ret = send( handle, buffer, len , flags);
	if( ret <= len )
	{
	    debug("send msg error: %s", strerror(ret));
	    ret = POMME_SEND_MSG_ERROR;
	    goto err;
	}
	//TODO: may add statistic infomations
err:
	return ret;
}

int pomme_recv(int handle, void *buffer,
	size_t len, int flags)
{
    int ret = 0 ;
    size_t r_len = 0;
    assert(buffer != NULL);
    if( len <= 0 )
    {
	debug("len <= 0");
	ret = POMME_WRONG_ARG;
	goto err;
    }

    r_len = recv( handle, buffer, len, flags);
    
    if( r_len < 0 )
    {
	debug("recv_error: %s", strerror(r_len));
	ret = POMME_RECV_MSG_ERROR;
	goto err;
    }else if(r_len ==0 ){
	debug("The peer has been shutdown");
	ret = POMME_SHUTDOWN_PEER;
	goto err;
    }
err:
    return ret;

}