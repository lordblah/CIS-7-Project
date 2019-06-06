/** 
 * Program title: cipher.c
 * Author:Tapatiolookalikeguy
 * Purpose:a program that encrypts messages using Vigenère’s cipher. 
 * Same code as cipher.
 **/
 
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include <iostream>


//prototype functions
//TODO change to strings so i can use a string as a key, right now its only a number
std::string enycrptMEssage(std::string message, std::string key );
std::string decyptMessage(std::string message,std::string key );
std::string CiperKey(std::string message, std::string key);

using namespace std;
int main()
{

    //k, secrect key, # of places to moveover
    string key;
    //secrect message to encrypt
    string message;
    string enycrptM;
    string decyptMessage;
    //user 
    cout << "Enter secrect key" << endl;
    cin >> key;
    cout << "Enter secrect message" << endl;
    cin >> message;

    key = CiperKey(key,message);
    enycrptM = enycrptMEssage(message,key);

    cout<< "The enycrpt message is as follows: " << enycrptM << endl;



   
}

string CiperKey(std::string message, std::string key)
{
  string cipherKEy;
  for(int x = 0, y = 0; x < message.length(); x++,y++)
  {
    //what do i want to do?, i want to get a letter from the key
    //a loop which will repeating loop through a word until
    if(key.length() == y)
    {
      y = 0;
    }
    cipherKEy[x] = key[y];
  } 
  return cipherKEy;
   
}
string enycrptMEssage(std::string message, std::string key)
{

  string encrptyeMessage;
  int z;
  for(int x = 0; x < message.length(); x++)
  {
    z = (message[x] + key[x]) % 26; 
    // convert into alphabets(ASCII) 
    z += 'a'; 
  
    encrptyeMessage.push_back(z); 
  }

  return encrptyeMessage;
}
