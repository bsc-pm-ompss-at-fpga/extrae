/*****************************************************************************\
 *                        ANALYSIS PERFORMANCE TOOLS                         *
 *                                   Extrae                                  *
 *              Instrumentation package for parallel applications            *
 *****************************************************************************
 *     ___     This library is free software; you can redistribute it and/or *
 *    /  __         modify it under the terms of the GNU LGPL as published   *
 *   /  /  _____    by the Free Software Foundation; either version 2.1      *
 *  /  /  /     \   of the License, or (at your option) any later version.   *
 * (  (  ( B S C )                                                           *
 *  \  \  \_____/   This library is distributed in hope that it will be      *
 *   \  \__         useful but WITHOUT ANY WARRANTY; without even the        *
 *    \___          implied warranty of MERCHANTABILITY or FITNESS FOR A     *
 *                  PARTICULAR PURPOSE. See the GNU LGPL for more details.   *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public License  *
 * along with this library; if not, write to the Free Software Foundation,   *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA          *
 * The GNU LEsser General Public License is contained in the file COPYING.   *
 *                                 ---------                                 *
 *   Barcelona Supercomputing Center - Centro Nacional de Supercomputacion   *
\*****************************************************************************/

#ifndef __DEVICEINFO_H_INCLUDED_
#define __DEVICEINFO_H_INCLUDED_

#include <pthread.h>

typedef struct Extrae_device_info
{
	unsigned           threadid;  // Extrae's logical thread (the row in Paraver)
	void *             auxdata;   // Aux pointer to access other device data (may be used by OMPT)
	unsigned long long latency;   // Latency that has to be applied to the timestamps of the records produced by this device
	pthread_mutex_t    lock;      // Mutex to avoid collisions between threads instrumenting the device
} Extrae_device_info_t;

void Extrae_allocate_device_CleanUp (void);
void Extrae_allocate_device_info (unsigned ndevices);
unsigned Extrae_get_device_number (void);
Extrae_device_info_t * Extrae_get_device_info (unsigned deviceid);

#endif /* __DEVICEINFO_H_INCLUDED_ */
