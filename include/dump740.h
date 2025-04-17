#ifndef DUMP_740_H
#define DUMP_740_H

typedef struct
{
    long long int time;
    int board_number;
    int altitude;
    int fuel;
} t_BoardInfoStruct;

typedef void (*BoardSignalCallback)(t_BoardInfoStruct board_info);

__declspec(dllexport) void dump740_init();

__declspec(dllexport) void dump740_deinit();

__declspec(dllexport) void dump740_start();

__declspec(dllexport) void dump740_stop();

__declspec(dllexport) void dump740_register_callback(BoardSignalCallback callback);

__declspec(dllexport) void dump740_deregister_callback();

#endif