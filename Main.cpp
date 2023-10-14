#include <iostream>
#include <string>
#include <openssl/sha.h>

using namespace std;

string hash_password(string password) {
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1(reinterpret_cast<const unsigned char*>(password.c_str()), password.length(), hash);
    string hashed_password(reinterpret_cast<const char*>(hash), SHA_DIGEST_LENGTH);
    return hashed_password;
}

int main() {
    string password;
    cout << "Enter your password: ";
    cin >> password;
    string hashed_password = hash_password(password);
    cout << "Your hashed password is: " << hashed_password << endl;
    return 0;
}