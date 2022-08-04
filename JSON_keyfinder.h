/**
 * @file temp.h
 * @author Gurpal singh (g.singh080808@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief These enums are being used to return status 
 * 
 */
typedef enum{
  JSON_OK,//it means value is extracted of desired key
  KEY_NOT_FOUND,//if key is not found in json string
  INVALID_JSON_FORMAT//it means something is wrong with json format of provided string
}GURUJsonRet_e;

GURUJsonRet_e JSON_find_key(char *l_inputJsonStringPtr, int l_inputJsonStringLen, char *key_to_find, char *l_outputJsonStringptr, int *l_outputJsonStringLen);