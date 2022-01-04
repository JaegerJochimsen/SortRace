#include <iostream>
#include <time.h>
using std::cout;

int main(int argc, char *argv[]){
    int numPts = atoi(argv[1]);
    srand(time(NULL));

    for(int i = 0; i < numPts; ++i)
        cout << (rand() % 10000)  << " ";
    cout << '\n'; 
return EXIT_SUCCESS;
}
