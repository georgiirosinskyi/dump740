/* Part of dump740, a UVD protocol decoder for RTLSDR devices.
 *
 * Copyright (c) 2016 Alexandr Ivanov <alexandr.sky@gmail.com>
 *
 * This file is free software: you may copy, redistribute and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _DUMP_740_OPTIONS_H_
#define _DUMP_740_OPTIONS_H_

#include "dump740_types.h"
#include "routines.h"

#define DEFAULT_FREQUENCY		740000000
#define SAMPLE_RATE				2000000
#define DEFAULT_GAIN			2000000
#define BLOCK_SIZE				524288
#define MAX_MESSAGES_IN_BLOCK	256
#define DEFAULT_LOG_LEVEL		LOG_FATAL

#define ARG_GAIN_MAX	0xfff0
#define ARG_GAIN_AUTO	0xfff1

// #define TEST	1

void init_default_options();
void set_options(t_Options* options);
t_Options* get_options();

#endif
