/*
 * =====================================================================================
 *
 *       Filename:  pomme_client_data.h
 *
 *    Description:  the header for client_data
 *
 *        Version:  1.0
 *        Created:  03/01/2012 06:49:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  drealdal (zhumeiqi), meiqizhu@gmail.com
 *        Company:  Tsinghua University, HPC
 *
 * =====================================================================================
 */
#ifndef _POMME_CLIENT_DATA_H
#define _POMME_CLIENT_DATA_H

#include "utils.h"
#include "pomme_pack.h"
#include "pomme_protocol.h"


/**
 * @brief pomme_put_data : put data to an connection
 *
 * @param handle: the handle of the connection
 * @param buffer: the buffer where the data to be sent is stored
 * @param len: the length of the data
 *
 * @return : < 0 failure, ==0 success
 */
int pomme_put_data(int handle, 
	void *buffer,
	int len);

/**
 * @brief pomme_get_data : get  data from an 
 *
 * @param handle: the handle of the connection
 * @param buffer: where the received data is stored
 * @param len: the recved data length
 *
 * @return: < 0 failure, = 0 success 
 */
int pomme_get_data(int handle,
	void **buffer,
	int *len);


#endif