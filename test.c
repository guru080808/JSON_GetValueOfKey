/**
 * @file test.c
 * @author Gurpal singh (g.singh080808@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>
#include "temp.h"

int main()
{
    char payload[1000] = {0};
    int payload_len = 0;
    FILE *fp = fopen("payload.json", "r");
    fread(payload, 1, 1000, fp);
    fclose(fp);
    payload_len = strlen(payload);
    int len = 0;
    char value[1000] = {0};
    if (JSON_find_key(payload, payload_len, "testkey1", value, &len) == JSON_OK)
    {
        printf("valuefound");
    }
    else
    {
        printf("Value not found");
    }

    fflush(stdout);

    return 0;
}
