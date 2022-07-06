/* TP, 2018/2019
*/
#include <iostream>

long long int** StirlingoviBrojeviV1 (int n)
{

    if(n<0) throw std::domain_error ("Parametar ne smije biti negativan");
    long long int** redovi;
    try {
        redovi= new long long int* [n+1];
        for(int i=0; i<n+1; i++) redovi[i]=nullptr;

        try {
            for(int i=0; i<n+1; i++) redovi[i] = new long long int [i+1];
            for(int i=0; i<n+1; i++)
                for(int j=0; j<i+1; j++) {
                    if(i==j) redovi[i][j]=1;
                    else if(j==0) redovi[i][j]=0;
                    else redovi[i][j]=redovi[i-1][j-1]+j*redovi[i-1][j];
                }

        } catch(...) {
            for(int i=0; i<n+1; i++) delete [] redovi[i];
            delete [] redovi;
            throw;
        }

    }

    catch(...) {
        throw std::range_error ("Parametar prevelik za raspolozivu memoriju");
    }


    return redovi;

}
long long int** StirlingoviBrojeviV2(int n)
{

    if(n<0) throw std::domain_error ("Parametar ne smije biti negativan");
    long long int** redovi;
    int suma=0;
    for(int i=0; i<n+1; i++)
        suma=suma+i+1;
    try {
        redovi= new long long int* [n+1];
        try {
            redovi[0]= new long long int [suma];
            for(int i=1; i<n+1; i++) redovi[i]=redovi[i-1]+i;
            for(int i=0; i<n+1; i++)
                for(int j=0; j<i+1; j++) {

                    if(i==j) redovi[i][j]=1;
                    else if(j==0) redovi[i][j]=0;
                    else redovi[i][j]=redovi[i-1][j-1]+j*redovi[i-1][j];
                }

        } catch(...) {
            delete [] redovi;
            throw;
        }
    } catch(...) {
        throw std::range_error ("Parametar prevelik za raspolozivu memoriju");
    }
    return redovi;
}

int main ()

{
    try {
        int n;
        std::cin >> n;

        /* long long int** prvi=StirlingoviBrojeviV1(n);*/
        long long int** drugi=StirlingoviBrojeviV2(n);
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<i+1; j++)
                std::cout<< drugi[i][j] << " ";
            std::cout << std::endl;
        }
        delete[] drugi[0];
        delete [] drugi;

    } catch(std::domain_error d) {
        std::cout << d.what();

    } catch(std::range_error r) {
        std::cout << r.what();
    }




    return 0;
}
