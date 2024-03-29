/** 
 * Program title: cipher.c
 * Author:Tapatiolookalikeguy
 * Purpose:a program that encrypts messages using Vigenère’s cipher. 
 * Same code as cipher.

 **/
 //so far it works with captial letters
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include <iostream>
#include <stdexcept>
#include<limits>


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
    string decyptM;
    //user 
    
        
    cout << "Enter secrect message" << endl;
    getline(cin,message);
    while(message == "")
    {
    cout<<"You have entered wrong input"<<endl;
    cout << "Enter secrect message" << endl;
    getline(cin,message);
    }

    cout << "Enter secrect key" << endl;
    getline(cin,key);
    while(key == "")
    {
    
    cout<<"You have entered wrong input"<<endl;
    cout << "Enter secrect message" << endl;
    getline(cin,key);
    }
    cout << message << endl;
    key = CiperKey(message,key);
    cout << key << endl;
    enycrptM = enycrptMEssage(message,key);
    decyptM = decyptMessage(enycrptM,key);

    cout<< "The enycrpt message is as follows: " << enycrptM << endl;

    cout<< "The decrpted message is as follows: " << decyptM << endl;

  return 0; 
   
}

string CiperKey(std::string message, std::string key)
{
  string cipherKEy;
  //converting key to uppercase
  for(int i = 0; i < key.size(); i++) {
    key.at(i) = toupper(key.at(i));
}
  for(int x = 0, y = 0; x < message.length(); x++,y++)
  {
    //what do i want to do?, i want to get a letter from the key
    //a loop which will repeating loop through a word until
    if(key.length() == y)
    {
      y = 0;
    }

    cipherKEy.push_back(key[y]);
  } 
  return cipherKEy;
   
}

//create a fnuction that does the 
//todo fix both functions to add special symbol
string enycrptMEssage(std::string message, std::string key)
{
  //uppercase the message 
  for(int i = 0; i < message.size(); i++) {
    message.at(i) = toupper(message.at(i));
  }
  string encrptyeMessage;
  //encypt whole key to upper case
  int z;
  for(int x = 0; x < message.length(); x++)
  {

    if (message[x] >=32 && message[x] <= 64)
    {
      encrptyeMessage.push_back(message[x]);
    }else{
      z = (message[x] + key[x]) % 26; 
      // convert into alphabets(ASCII) 
      //right here is where i will deiced to use A or a
      z += 'A';
      encrptyeMessage.push_back(z); 
    }
  }

  return encrptyeMessage;
}

string decyptMessage(std::string message, std::string key)
{

  string encrptyeMessage;
  int z;
  for(int x = 0; x < message.length(); x++)
  {
     if (message[x] >=32 && message[x] <= 64)
    {
      encrptyeMessage.push_back(message[x]);
    }else{
       z = (message[x] - key[x] + 26) % 26; 
    // convert into alphabets(ASCII) 

    z += 'A';
    encrptyeMessage.push_back(z);
    }
        
  }

  return encrptyeMessage;
}
