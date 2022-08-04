# JSON_GetValueOfKey
This repository helps in finding the value of key from json C string 
this library finds the first key match in json string and returns its value.
```
lets say you have json like that:
buffer0=  {
parent->    "a":{
child->          "a":"b"
                }
          }
In this case if you find key "a", then the value extracted will be {"a":"b"}
or If you want the value of child "a" then you have pass {"a":"b"} as input string i.e. value of parent key "a'
e.g.
buffer1=[]
buffer2=[]
JSON_find_key(buffer0, x, "a", buffer1, &y) this will give you {"a":"b"} in buffer1
JSON_find_key(buffer1, x, "a", buffer2, &y) this will give you "b"
```

USAGE:
1. Include header file in your C Code
2. Call the function JSON_find_key() in your C code and pass required parametres 
3. Check if return status == JSON_OK, means value is extarcted correctly

IMPORTANT INFORMATION:
1. THIS LIBRARY USES ONLY POINTERS SO MAKE SURE TO PASS CORRECT ADDRESS.(visit test.c for example)
2. IF ANY PROBLEM IS FOUND THEN REPORT IT.
3. JSON STRING SHLOUD HAVE CORRECT FORMAT. ( visit https://www.freecodecamp.org/news/what-is-json-a-json-file-example/ for more info on json format)
4. IT DOES NOT SUPPORT BOOLEAN DATA STRUCTURE YET IF YOU HAVE REQUIREMENT THEN LET ME KNOW I WILL ADD THAT TOO.
