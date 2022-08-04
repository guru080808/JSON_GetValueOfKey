/**
 * @file temp.c
 * @author Gurpal singh (g.singh080808@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "temp.h"
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>
/**
 *
 * @brief this function finds the value of desired key and returns the status if value is extracted correctly
 *           and fills the l_outputJsonStringptr with desired value
 *              {"key":"value"}
 * @param l_inputJsonStringPtr the pointer of input json string
 * @param l_inputJsonStringLen  the length of input json string
 * @param key_to_find  the key string to find
 * @param l_outputJsonStringptr pointer of value buffer to fill
 * @param l_outputJsonStringLen pointer of len variable to gets the length of the desired value
 * @return GURUJsonRet_e
 */
GURUJsonRet_e JSON_find_key(char *l_inputJsonStringPtr, int l_inputJsonStringLen, char *key_to_find, char *l_outputJsonStringptr, int *l_outputJsonStringLen)
{
    int retCode = KEY_NOT_FOUND;
    char *l_valuePtr = NULL;
    char *l_keyPtr = strstr(l_inputJsonStringPtr, key_to_find);
    if (l_keyPtr)
    {
        char *currentPtr = memchr(l_keyPtr, ':', l_inputJsonStringLen - (l_keyPtr - l_inputJsonStringPtr));
        if (currentPtr)
        {
            l_valuePtr = currentPtr + 1;
            while (1)
            {
                if (*l_valuePtr == '{' || *l_valuePtr == '"' || *l_valuePtr == '[' || *l_valuePtr == '-' || isdigit((int)*l_valuePtr))
                {
                    break;
                }
                l_valuePtr++;
                if (l_valuePtr > (l_inputJsonStringPtr + l_inputJsonStringLen))
                {
                    retCode = INVALID_JSON_FORMAT;
                    goto EXIT_ABNORMAL;
                }
            }

            currentPtr = NULL;
            switch (*l_valuePtr)
            {
            case '{':;
                int l_openedBrackets = 0;
                int l_closedbrackets = 0;
                char *tempptr = l_valuePtr;
                while (1)
                {
                    tempptr = memchr((tempptr + 1), '{', l_inputJsonStringLen - (tempptr - l_inputJsonStringPtr));
                    if (tempptr == NULL)
                    {
                        tempptr = l_valuePtr;
                        while (1)
                        {
                            if (l_openedBrackets == l_closedbrackets)
                            {
                                currentPtr = memchr((tempptr + 1), '}', l_inputJsonStringLen - (tempptr - l_inputJsonStringPtr));
                                break;
                            }
                            else
                            {
                                tempptr = memchr((tempptr + 1), '}', l_inputJsonStringLen - (tempptr - l_inputJsonStringPtr));
                                l_closedbrackets++;
                            }
                        }
                        if (currentPtr)
                            break;
                    }
                    l_openedBrackets++;
                }
                break;
            case '"':
                currentPtr = memchr((l_valuePtr + 1), '"', l_inputJsonStringLen - (l_valuePtr - l_inputJsonStringPtr));
                break;
            case '[':
                currentPtr = memchr(l_valuePtr, ']', l_inputJsonStringLen - (l_valuePtr - l_inputJsonStringPtr));
                break;

            default:;
                if (isdigit((int)*l_valuePtr) || *l_valuePtr == '-')
                {
                    currentPtr = l_valuePtr;
                    while (1)
                    {
                        currentPtr++;
                        if (isdigit((int)*currentPtr) == 0)
                        {
                            currentPtr--;
                            break;
                        }
                    }
                }
                break;
            }
            if (currentPtr)
            {
                *l_outputJsonStringLen = currentPtr - l_valuePtr;
                memcpy((char *)l_outputJsonStringptr, (char *)l_valuePtr, *l_outputJsonStringLen + 1);
                goto EXIT_NORMAL;
            }
        }
        retCode = INVALID_JSON_FORMAT;
    }
EXIT_ABNORMAL:
    return -1;
EXIT_NORMAL:
    retCode = JSON_OK;
    return retCode;
}