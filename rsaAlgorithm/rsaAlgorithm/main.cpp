//RSA Algorithm
//Programming Project 1
//Professor  Aftab
//
//
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double publicKey(double phi_n)
{
    double e;
    for(e =2; e< phi_n ; e++)
    {
        if (fmod(phi_n,e) != 0)
            return e;
    }
    return 0;
}
double privateKey(double phi_n, double e)
{
   //d*e = 1mod 77
    double d;
    for(d =1; d<phi_n; d++)
    {
        double power = d*e;
        if(fmod(power,phi_n) ==1)
           return d;
    }
    return 0;
}
double encryptedMessage(double m,double n, double e)
{
    double encryption;
    encryption = fmod(pow(m,e),n);
    return encryption;
}
double decryptedMessage(double eM, double d, double n)
{
    long double decryption;
    cout<< eM<< " " << d<< " "<<n <<endl;
    long double power =pow(eM,d);
    cout<< power<<endl;
    decryption = fmod(power, n);
    cout<<decryption<<endl;
    return decryption;
}


int main() {
    double n, p, q, d, e, phi_n;
    double m, decryption, encryption,eM;
    
    cout<<"This is the example"<<endl;
    cout<< "Enter P (prime number): ";
    cin>> p;
    cout<<"\nEnter Q (prime number): ";
    cin>>q;
    
    n = p*q;
    phi_n = (p-1)*(q-1);
    
    cout<<"The value of n is: " <<n <<endl;
    cout<<"The value of phi_n is: "<< phi_n<<endl;
    
    //PublicKey to find e we take the gcd(e, phi_n ) where e<phi_n
    e = publicKey(phi_n);
    cout<<"E is equal to "<< e<<endl;
    
    //privateKey Encryption
    d = privateKey(phi_n,e);
    
    cout<<"D equals: "<<d<<endl;
    
    //this is the message
    cout<< "Enter in your message: ";
    cin>> m;
    
    encryption = encryptedMessage(m, n, e);
    cout<<"Your Encrypted message is: \n"<<encryption<<endl;
    
    //decrypted
    
    cout<<"Enter in your encrypted Message: ";
    cin>> eM;
    
    decryption = decryptedMessage(eM, d, n);
    cout<<"Your Message decrypted is: \n"<<decryption<<endl;
    return 0;
}
