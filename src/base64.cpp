#include "config.h"

/*
引用相关库进行Base64编解码
*/
String Base64Encode(String str){
    char * InputString = const_cast<char*>(str.c_str());
    int encodedLength = Base64.encodedLength(str.length());
    char encodedString[encodedLength + 1];
    Base64.encode(encodedString, InputString, str.length());
    return String(encodedString);
}

String Base64Decode(String str){
    char * InputString = const_cast<char*>(str.c_str());
    int decodedLength = Base64.decodedLength(InputString, str.length());
    char decodedString[decodedLength + 1];
    Base64.decode(decodedString, InputString, str.length());
    return String(decodedString);
}