#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#include <time.h>
#include <string>

using namespace std;

//note: used http://www.askyb.com/cpp/openssl-md5-hashing-example-in-cpp/ to figure out how to create an MD5 hash in C++
//note: used https://stackoverflow.com/questions/2146792/how-do-you-generate-random-strings-in-c to figure out how to generate random string C++

//to compile: g++ -I/usr/local/openssl/lib -lcrypto -lssl -o find findit.cpp

string randomString(int length){
    string s;
    const char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    for (int i = 0; i < length; i++){
        s[i] = chars[rand() % strlen(chars)];
    }
    return s;
}
 
int main()
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    int input = 1;
    char string[] = "ridh74hdks92jfn648s48ncsk53dsa1";  //random stuff

    char hacker[] = "\'||\'1";

    unsigned char * hash;

    srand(time(NULL));

    while(true){

    strcpy(string, randomString(32).c_str());

    printf("%s\n", string);

    // strcpy(string, "129581926211651571912466741651878684928");

    // printf("%s\n", string);

    hash = MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

    if (strstr((char*)hash, hacker) != NULL){ // if the hash contains the sql injection
            printf("%s\n", "FOUND IT: ");
            printf("%s", hash);
        }
    }



    // int i = 0;
    // while(true){
    //     i += 1;

    //     strcpy(string, randomString(32).c_str());

    //     printf("%s\n", string);

    //     hash = MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

    //     if (strstr((char*)hash, hacker) != NULL){ // if the hash contains the sql injection
    //         printf("%s\n", "FOUND IT: ");
    //         printf("%s\n", string);
    //         printf("%s", hash);
    //         exit(0);
    //     } 

    // }
 
    return 0;
}