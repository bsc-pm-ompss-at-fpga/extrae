
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

#include "common.h"

#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#endif
#ifdef HAVE_STRING_H
# include <string.h>
#endif

#include "utils.h"
#include "deviceinfo.h"

static Extrae_device_info_t *device_info = NULL;
static unsigned device_info_ndevices = 0;

void Extrae_allocate_device_CleanUp (void)
{
	unsigned u;

	for (u = 0; u < device_info_ndevices; u++)
	{
		pthread_mutex_destroy(&device_info[u].lock);
	}

	xfree (device_info);
	device_info = NULL;
}

void Extrae_allocate_device_info (unsigned ndevices)
{
	unsigned u, total_devices;

	total_devices = device_info_ndevices + ndevices;
	device_info = (Extrae_device_info_t*) realloc (device_info, total_devices*sizeof (Extrae_device_info_t));

	for (u = device_info_ndevices; u < total_devices; u++)
	{
		device_info[u].threadid = -1;
		device_info[u].auxdata = NULL;
		device_info[u].latency = 0;
		pthread_mutex_init (&device_info[u].lock, NULL);
	}

	device_info_ndevices = total_devices;
}

unsigned Extrae_get_device_number (void)
{
	return device_info_ndevices;
}

Extrae_device_info_t * Extrae_get_device_info (unsigned deviceid)
{
	return deviceid < device_info_ndevices ? &device_info[deviceid] : NULL;
}
