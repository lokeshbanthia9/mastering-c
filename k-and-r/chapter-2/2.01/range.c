/**
 * Program to determine the ranges of basic data types. 
 * 
 * Exercise 2.1 
 */

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#define BITS 8

int main(void)
{
    printf("\n+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                 INTEGER DATA TYPE RANGES (C Language)                                                                 |\n");
    printf("+---------------------------+---------------------------+-------------------------------------------------------+-------------------------------------------------------+\n");
    printf("|                           |                           |                        ACTUAL                         |                       COMPUTED                        |\n");
    printf("| Data Type                 | Size (bytes)              |---------------------------+---------------------------|---------------------------+---------------------------|\n");
    printf("|                           |                           | Minimum                   | Maximum                   | Minimum                   | Maximum                   |\n");
    printf("+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+\n");

    char c_min = 1 << (sizeof(char) * BITS - 1);
    char c_max = ~c_min;
        printf("| %-25s | %-25u | %-25hhi | %-25hhi | %-25hhi | %-25hhi |\n",
        "char",
        sizeof(char),
        SCHAR_MIN,
        SCHAR_MAX,
        c_min,
        c_max
    );

    unsigned char uc_max = ~0;
    printf("| %-25s | %-25u | %-25hhu | %-25hhu | %-25hhu | %-25hhu |\n",
        "unsigned char",
        sizeof(unsigned char),
        0,
        UCHAR_MAX,
        0,
        uc_max
    );

    short s_min = 1 << (sizeof(short) * BITS - 1);
    short s_max = ~s_min;
    printf("| %-25s | %-25u | %-25hi | %-25hi | %-25hi | %-25hi |\n",
        "short",
        sizeof(short),
        SHRT_MIN,
        SHRT_MAX,
        s_min,
        s_max
    );

    unsigned short us_max = ~0;
    printf("| %-25s | %-25u | %-25hu | %-25hu | %-25hu | %-25hu |\n",
        "unsigned short",
        sizeof(unsigned short),
        0,
        USHRT_MAX,
        0,
        us_max
    );

    int i_min = 1 << (sizeof(int) * BITS - 1);
    int i_max = ~i_min;
    printf("| %-25s | %-25u | %-25i | %-25i | %-25i | %-25i |\n",
        "int",
        sizeof(int),
        INT_MIN,
        INT_MAX,
        i_min,
        i_max
    );

    unsigned int ui_max = ~0U;
    printf("| %-25s | %-25u | %-25u | %-25u | %-25u | %-25u |\n",
        "unsigned int",
        sizeof(unsigned int),
        0,
        UINT_MAX,
        0,
        ui_max
    );

    long l_min = 1L << (sizeof(long) * BITS - 1);
    long l_max = ~l_min;
    printf("| %-25s | %-25u | %-25li | %-25li | %-25li | %-25li |\n",
        "long",
        sizeof(long),
        LONG_MIN,
        LONG_MAX,
        l_min,
        l_max
    );

    unsigned long ul_max = ~0;
    printf("| %-25s | %-25u | %-25lu | %-25lu | %-25lu | %-25lu |\n",
        "unsigned long",
        sizeof(unsigned long),
        0L,
        ULONG_MAX,
        0L,
        ul_max
    );

    long long ll_min = 1LL << (sizeof(long long) * BITS - 1);
    long long ll_max = ~ll_min;
    printf("| %-25s | %-25u | %-25lli | %-25lli | %-25lli | %-25lli |\n",
        "long long",
        sizeof(long long),
        LLONG_MIN,
        LLONG_MAX,
        ll_min,
        ll_max
    );

    unsigned long long ull_max = ~0;
    printf("| %-25s | %-25u | %-25llu | %-25llu | %-25llu | %-25llu |\n",
        "unsigned long long",
        sizeof(unsigned long long),
        0LL,
        ULLONG_MAX,
        0LL,
        ull_max
    );

    printf("+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+\n");
    
    printf("\n+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                                                         FLOATING-POINT DATA TYPE RANGES (C Language)                                                                                          |\n");
    printf("+---------------------------+---------------------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+\n");
    printf("|                           |                           |                                      ACTUAL                                       |                                     COMPUTED                                      |\n");
    printf("| Data Type                 | Size (bytes)              |---------------------------+---------------------------+---------------------------|---------------------------+---------------------------+---------------------------|\n");
    printf("|                           |                           | Minimum (subnormal)       | Minimum (normal)          | Maximum                   | Minimum (subnormal)       | Minimum (normal)          | Maximum                   |\n");
    printf("+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+\n");

    float f_true_min = pow(FLT_RADIX, -FLT_MANT_DIG + 1) * pow(FLT_RADIX, FLT_MIN_EXP - 1);
    float f_min = pow(FLT_RADIX, FLT_MIN_EXP - 1);
    float f_max = (FLT_RADIX - pow(FLT_RADIX, -FLT_MANT_DIG + 1)) * pow(FLT_RADIX, FLT_MAX_EXP - 1);
    printf("| %-25s | %-25u | %-25g | %-25g | %-25g | %-25g | %-25g | %-25g |\n",
        "float",
        sizeof(float),
        FLT_TRUE_MIN,
        FLT_MIN,
        FLT_MAX,
        f_true_min,
        f_min,
        f_max
    );

    double d_true_min = pow(FLT_RADIX, -DBL_MANT_DIG + 1) * pow(FLT_RADIX, DBL_MIN_EXP - 1);
    double d_min = pow(FLT_RADIX, DBL_MIN_EXP - 1);
    double d_max = (FLT_RADIX - pow(FLT_RADIX, -DBL_MANT_DIG + 1)) * pow(FLT_RADIX, DBL_MAX_EXP - 1);
    printf("| %-25s | %-25u | %-25g | %-25g | %-25g | %-25g | %-25g | %-25g |\n",
        "double",
        sizeof(double),
        DBL_TRUE_MIN,
        DBL_MIN,
        DBL_MAX,
        d_true_min,
        d_min,
        d_max
    );

    printf("+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+---------------------------+\n");
    
    return 0;
}