#define FOSC    12000000
#define CCLK    (FOSC*5)
#define PCLK    (CCLK/4)
#define ADCCLK  3000000
#define CLKDIV  ((PCLK/ADCCLK)-1)

#define CLKDIV_BITS 8
#define PDN_BIT         21
#define START_BIT       24

#define DIGITAL_CONV_DATA       6
#define DONE_BIT                31

#define AIN1_0_27 24

#define MAX_VAL 340
#define MIN_VAL 90
