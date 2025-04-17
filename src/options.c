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

#include "options.h"
#include <stdlib.h>

static t_Options g_options;

void init_default_options()
{
	g_options.dev_index = 0;
	g_options.freq = DEFAULT_FREQUENCY;
	g_options.freq_correction = 0;
	g_options.gain = ARG_GAIN_MAX;
	g_options.ifile = NULL;
	g_options.raw = 0;
	g_options.log_level = DEFAULT_LOG_LEVEL;
	g_options.dump = 0;
}

void set_options(t_Options* options)
{
	if (!options)
	{
		return;
	}

	g_options.dev_index = options->dev_index;
	g_options.freq = options->freq;
	g_options.freq_correction = options->freq_correction;
	g_options.gain = options->gain;
	g_options.ifile = options->ifile;
	g_options.raw = options->raw;
	g_options.log_level = options->log_level;
	g_options.dump = options->dump;
}

t_Options* get_options()
{
	return &g_options;
}
