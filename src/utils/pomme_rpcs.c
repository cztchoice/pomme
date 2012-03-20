/*
 * =====================================================================================
 *
 *       Filename:  pomme_rpcs.c
 *
 *    Description:  the implemention of the rpc server
 *
 *        Version:  1.0
 *        Created:  03/18/2012 10:19:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#include "pomme_rpcs.h"
#include "pomme_blist.h"

static int fregister(pomme_rpcs_t *,char *,void *);
static int func_print(pomme_rpcs_t *rpcs);
static int start(pomme_rpcs_t *rpcs);

int pomme_rpcs_init(pomme_rpcs_t *rpcs)
{
    int ret = 0;

    assert( rpcs != NULL);
    memset( rpcs, 0, sizeof(pomme_rpcs_t));
    init_link(&rpcs->func);
    rpcs->func_register = (void *)fregister;
    rpcs->func_print = (void *)func_print;

    return ret;
}

int pomme_rpcs_distroy(pomme_rpcs_t *rpcs)
{
    int ret = 0;
    assert( rpcs != NULL );
    
    pomme_func_t *pos = NULL;
    pomme_link_t *head = &rpcs->func;

    list_for_each_entry(pos, head, next)
    {
	link_del(pos);
	free(pos);
    }
    memset(rpcs, 0, sizeof(pomme_rpcs_t));

    return ret;
}
static int start(pomme_rpcs_t *rpcs)
{

}