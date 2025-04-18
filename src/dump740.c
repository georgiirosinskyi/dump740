#include <stdio.h>
#include <pthread.h>

#include "receiver.h"
#include "decoder.h"
#include "thread.h"
#include "options.h"
#include "routines.h"

#include "dump740.h"

static pthread_t g_thread;
static BoardSignalCallback g_callback = NULL;

static void* work()
{
	block_t* block;
	int block_index = 0;
	int cnt, i;

	uint32_t msg[MAX_MESSAGES_IN_BLOCK];

	while ((block = next_block(&block_index)))
	{
		cnt = decode(block->data, block->data_length, msg, BLOCK_SIZE);

		for (i = 0; i < cnt; i++)
		{
			print_message(stdout, msg[i]);
		}
	}

    return NULL;
}

__declspec(dllexport) void dump740_init(t_Options* options)
{
    if (!options)
    {
        init_default_options();
    }
    else
    {
        set_options(options);
    }
    init_decoder();
	init_receiver();
}

__declspec(dllexport) void dump740_start()
{
    init_thread(reader);
    if (pthread_create(&g_thread, NULL, work, NULL) != 0)
	{
		fatal("Pthread creating error\n");
	}
}

__declspec(dllexport) void dump740_stop()
{
    set_end();
    pthread_join(g_thread, NULL);
    close_thread();
}

__declspec(dllexport) void dump740_register_callback(BoardSignalCallback callback)
{
    g_callback = callback;
}

__declspec(dllexport) void dump740_deregister_callback()
{
    g_callback = NULL;
}

__declspec(dllexport) void dump740_deinit()
{
    close_receiver();
	close_decoder();
}
