//
//  functions.h
//  RSA_Algorithm_Numbers
//
//  Created by Nyvia DeJesus on 3/17/16.
//  Copyright © 2016 CSCI412. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double gcd(double,double);
void encryptMessage(double, double);
double toEncryptMessage(double, double, double);
double decrypt(double, double);
void decryptMessage(double, double, double);
double gcdSolve(double, double, double);
double toDecryptMessage(double, double, double);
char what2do();

#ifndef functions_h
#define functions_h
char whatTodo()
{
    char what2do;
    //This is where you decide if you want to encrypt or decrypt
    do{
        what2do=NULL;
        cout<<"If you want to encrypt type in the letter e. If you want to decrypt type in the letter d. If you want to exit type in x.So what do you want to do??";
        cin>> what2do;
        cout<<endl;
        //cout<<what2do<<endl;
    }while((what2do != 'e')&& (what2do != 'd')&&(what2do!='x'));
    
    return what2do;
}
/*
 //To get greatest common denominator
 double gcd(double phi_n,double n)
 {
 double e;
 //e < phi_n
 for(e =2; e<phi_n; e++)
 {
 //gcd of e and phi_n should be 1
 for( double i = 2; i <=e; i++)
 {
 //so e%i && phi_n%i should not be zero
 if(((fmod(e,i)!=0)&&(fmod(phi_n,i)!=0)))
 {
 //cout<<e<<endl;
 return e;
 }
 //so if they e is equal to i and phi_n%i is not equal to zero then return e
 else if ( e == i)
 {
 if(((fmod(e,i)==0)&&(fmod(phi_n,i)!=0)))
 {
 //cout<<e<<endl;
 return e;
 }
 }
 }
 
 //cout<< e<<endl;
 return 0;
 //take 2
 }*/

//To get greatest common denominator if e is inputted by user
double gcd(double phi_n,double n)
{
    double t, e;
    //double top;
    cout<<"Please enter a prime number less than  "<< phi_n<<" and where "<< n << " and e are prime numbers and are coprime and only have 1 as a common divisor:";
    cin>> t;
    cout<< "Your entered:" <<t<<endl;
    
    e = gcdSolve( phi_n, n, t);
    return e;
}
double gcdSolve(double phi_n, double n, double e)
{
    for(double i = e; i >=1; i--)
    {
        if(fmod(e,i)==0&& fmod(phi_n,i)==0){
            return e;
        }
    }
    return 0;
}

void encryptMessage(double e, double n)
{
    double m, em;
    cout<< "Please Enter the Message You want to Encrypt: ";
    cin>> m;
    
    em = toEncryptMessage(m,e,n);
    
    cout <<"Your e = "<< e<< " n = "<< n<<endl;
    
    cout<<"Your encrypted message is: "<<em<<endl;
}
double toEncryptMessage(double m, double e, double n)
{
    double em;
    em = fmod(pow(m,e),n);
    return em;
}
void decryptMessage(double e, double n, double phi_n)
{
    double em, m, d;
    cout<<"Enter the Message to decrypt: ";
    cin>> em; cout<<endl;
    
    d = decrypt(e, phi_n);
    
    m = toDecryptMessage(em,d,n);
    cout<<"Your Decrypted Message is: "<< m<<endl;
}
double decrypt(double e, double phi_n)
{
    double d;
    for( int i = 2; i<phi_n; i++)
    {
        //cout <<i<<" "<<e <<endl;
        if (fmod((e*i),phi_n)==1)
        {
            d = i;
            //cout<<d<<endl;
            return d;
        }
    }
    return 0;
}
double toDecryptMessage(double em, double d, double n)
{
    double m;
    cout<<"Your encrypted Message is:"<< em<<"\nYour decrypted number is: "<< d<<"\nYour p*q is: "<< n <<endl;
    double power = pow(em,d);
    
    cout<<power<<endl;
    m= fmod(pow(em,d),n);
    return m;
}
#endif /* functions_h */
