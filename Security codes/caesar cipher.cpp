#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//ENCODING - method1
string caesarencode(string plaintext,int shift)
{
	
	for(int i=0;i<plaintext.size();i++){
		if(islower(plaintext[i])){
		  plaintext[i]=plaintext[i]+shift;
		  if(plaintext[i]>'z')
		    plaintext[i]=((plaintext[i]-97)%26)+97;
		}
		else if(isupper(plaintext[i])){
		  plaintext[i]=plaintext[i]+shift;
		  if(plaintext[i]>'Z')
		    plaintext[i]=((plaintext[i]-65)%26)+65;	
		}
		
	}
	return plaintext;
}

//DECODING - method2
string caesardecode(string ciphertext,int shift)
{
	for(int i=0;i<ciphertext.size();i++){
		if(islower(ciphertext[i])){
		  ciphertext[i]=ciphertext[i]-shift;
		  if(ciphertext[i]<'a')
		    ciphertext[i]=ciphertext[i] + 'z' - 'a' + 1;
		}
		else if(isupper(ciphertext[i])){
		  ciphertext[i]=ciphertext[i]-shift;
		  if(ciphertext[i]<'A')
		    ciphertext[i]=ciphertext[i] + 'Z' - 'A' + 1;	
		}
		
	}
	return ciphertext;
	
}
int main()
{
	string plaintext;
	int shift1;
	//ENCODE
    cout<<"Enter the text to be encrypted:";
	getline(cin, plaintext);
	//Caesar uses shift=3 generally
	cout<<"Enter the shift:";
	cin>>shift1;
	cout<<"Cipher text is : "<<caesarencode(plaintext,shift1)<<"\n";
	//DECODE
	string ciphertext;
	int shift2;
	cout<<"Enter the text to be decrypted:";
	//getline(cin,ciphertext);
	cin>>ciphertext;
	//Caesar uses shift=3 generally
	cout<<"Enter the shift:";
	cin>>shift2;
	cout<<"Plain text is : "<<caesardecode(ciphertext,shift2);
	return 0;
}
