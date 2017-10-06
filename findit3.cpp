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

    char hacker[] = "\'<>\'";
    char hacker2[] = "\'or\'1";
    char hacker3[] = "\'||1;#";
    char hacker4[] = "\'||\'1";
    char hacker5[] = "\'OR\'1";
    char hacker6[] = "\'oR\'1";
    char hacker7[] = "\'Or\'1";

    unsigned char * hash;

    srand(time(NULL));

    unsigned int a = 1;

    while(true){

        a += 1;

    strcpy(string, randomString(32).c_str());

    printf("%s\n", string);

    // strcpy(string, "129581926211651571912466741651878684928");

    //  printf("%s\n", string);

    hash = MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

    if (strstr((char*)hash, hacker) != NULL){ // if the hash contains the sql injection
            printf("%s\n", "FOUND IT: ");
            printf("%s", hash);
            exit(0);
        }
    

    if (strstr((char*)hash, hacker2) != NULL){ // if the hash contains the sql injection
            printf("%s\n", "FOUND IT: ");
            printf("%s", hash);
            exit(0);
        }
    

    if (strstr((char*)hash, hacker3) != NULL){ // if the hash contains the sql injection
            printf("%s\n", "FOUND IT: ");
            printf("%s", hash);
            exit(0);
        }
    

    if (strstr((char*)hash, hacker4) != NULL){ // if the hash contains the sql injection
            printf("%s\n", "FOUND IT: ");
            printf("%s", hash);
            exit(0);
        }
    

    if (strstr((char*)hash, hacker5) != NULL){ // if the hash contains the sql injection
            printf("%s\n", "FOUND IT: ");
            printf("%s", hash);
            exit(0);
        }
    

    if (strstr((char*)hash, hacker6) != NULL){ // if the hash contains the sql injection
            printf("%s\n", "FOUND IT: ");
            printf("%s", hash);
            exit(0);
        }
    

    if (strstr((char*)hash, hacker7) != NULL){ // if the hash contains the sql injection
            printf("%s\n", "FOUND IT: ");
            printf("%s", hash);
            exit(0);
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