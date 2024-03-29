#ifndef _KODAMA_H_
#define _KODAMA_H_

#include <glib.h>
#include <stdint.h>

#if DEBUG
/* Yay C preprocessor */
#include <stdio.h>              /* Just in case */

#define DEBUG_LOG(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#else
#define DEBUG_LOG() {}
#endif

#define VERBOSE_LOG(...) {if (globals.verbose) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}}

#define NUM_CHANNELS (1)
#define SAMPLE_RATE  (8000)

#define PORTNUM (7650)

/* Select sample format. TODO: let's not make these constants, yes? */
#define PA_SAMPLE_TYPE  paInt16
typedef int16_t SAMPLE;
#define SAMPLE_SILENCE  (0)

/* Macro stolen from lighty for unused values */
#define UNUSED(x) ( (void)(x) )

void stack_trace(int die);

struct globals {
    /* tx side */
    gchar *txhost;
    int tx_xmit_port;
    int tx_recv_port;

    /* rx side */
    gchar *rxhost;
    int rx_xmit_port;
    int rx_recv_port;

    /* Fake delay */
    int tx_delay_ms;
    int rx_delay_ms;

    /* rx-side echo cancellation */
    int echo_cancel;

    /* Verbose mode */
    int verbose;

    int shardnum;
} globals;

#endif
