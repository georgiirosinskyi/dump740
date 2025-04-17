#ifndef DUMP_740_TYPES_H
#define DUMP_740_TYPES_H

typedef enum
{
    LOG_DEBUG   = 0,
    LOG_INFO    = 1,
    LOG_WARNING = 2,
    LOG_ALERT   = 3,
    LOG_FATAL   = 4
} t_LogLevel;

typedef enum
{
    DEFAULT_FREQUENCY = 740000000,
    DEFAULT_GAIN = 2000000,
    DEFAULT_LOG_LEVEL = LOG_FATAL
} t_DefaultSettings;

typedef enum
{
    ARG_GAIN_MAX  = 0xfff0,
    ARG_GAIN_AUTO = 0xfff1
} t_GainArg;

typedef struct
{
	int dev_index;
	int freq;
	int freq_correction;
	int gain;
	char* ifile;
	int raw;
	unsigned char log_level;
	int dump;
} t_Options;

typedef struct
{
    long long int time;
    int board_number;
    int altitude;
    int fuel;
} t_BoardInfoStruct;

#endif