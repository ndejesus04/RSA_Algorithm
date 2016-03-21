//RSA Algorithm
//Programming Project 1
//Professor  Aftab
//
//

#include "functions.h"

int main( ) {
    cout<<"Welcome to RSA Encryption/Decryption Algorithm Calculator!!"<<endl;
    // So we need n, p, q, phi_n and e
    float n, p, q, phi_n, e;
    char what2do;
    
    do{
        p =NULL;
        q = NULL;
    cout<< "Enter in your Prime Number 1 (p> 0): ";
    cin>> p; cout<<endl;
    cout<<"Enter in your Prime Number 2(p>0):";
    cin>> q; cout<<endl;
    }while(p<=0 || q<=0);
    
    
    // n = pxq
    n = p*q;
    // phi_n = (p-1)(q-1)
    phi_n = (p-1)*(q-1);
    //gcd(e,phi_n)=1
    e = gcd(phi_n,n);
    what2do = whatTodo();
    if(what2do=='e')
    {
        encryptMessage(e, n);
    }
    else if(what2do=='d')
    {
        decryptMessage(e,n, phi_n);
    }
    return 0;
}
