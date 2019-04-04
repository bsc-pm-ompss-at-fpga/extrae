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

#pragma once

void Extrae_set_trace_GPI(int trace);
int  Extrae_get_trace_GPI();
void Extrae_set_trace_GPI_HWC(int trace);
int  Extrae_get_trace_GPI_HWC();

void Probe_GPI_init_Entry();
void Probe_GPI_init_Exit();
void Probe_GPI_term_Entry();
void Probe_GPI_term_Exit();
void Probe_GPI_barrier_Entry();
void Probe_GPI_barrier_Exit();
void Probe_GPI_segment_create_Entry();
void Probe_GPI_segment_create_Exit();
void Probe_GPI_write_Entry();
void Probe_GPI_write_Exit();