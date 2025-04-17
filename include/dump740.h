#ifndef DUMP_740_H
#define DUMP_740_H

#include "dump740_types.h"

typedef void (*BoardSignalCallback)(t_BoardInfoStruct board_info);

__declspec(dllexport) void dump740_init(t_Options* options);

__declspec(dllexport) void dump740_deinit();

__declspec(dllexport) void dump740_start();

__declspec(dllexport) void dump740_stop();

__declspec(dllexport) void dump740_register_callback(BoardSignalCallback callback);

__declspec(dllexport) void dump740_deregister_callback();

#endif