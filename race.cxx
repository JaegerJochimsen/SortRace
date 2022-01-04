#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <unistd.h>
using namespace std;

#define USAGE "./RaceAlgs SORT_FLAG INPUT_FILE\n"
#define FLAGS "-g   gnome sort\n-i   insertion sort\n-b   bubble sort\n"

void output(vector<int> v){
    stringstream nums;
    for(size_t i = 0; i < v.size(); ++i){
        if(i != 0)
            nums << " ";
        nums << v[i];
    }
    cout << nums.str() << '\n';
    return;    
}

void bubbleSort(vector<int> v){
    bool haveSwapped = true;
    while(haveSwapped){
        haveSwapped = false;
        for(int curr = 1; curr < (int)v.size(); ++curr){
            if(v[curr] < v[curr-1]){
                int temp = v[curr];
                v[curr] = v[curr-1];
                v[curr-1] = temp;
                haveSwapped = true;
                output(v);
            }
        }
        output(v);
    }
}

void gnomeSort(vector<int> v){
    int currIndex = 1;
    int vecSize = (int)v.size();
    while(currIndex != vecSize - 1){
        if(currIndex == 0)
            currIndex++;
        if(v[currIndex - 1] <= v[currIndex])
            currIndex++;
        if(v[currIndex] < v[currIndex - 1]){
            int temp = v[currIndex - 1];
            v[currIndex - 1] = v[currIndex];
            v[currIndex] = temp;
            currIndex--;
        }
        output(v);
    }
    output(v);
}

void insertionSort(vector<int> v){
    for(int i = 1; i < (int)v.size(); ++i){
        int curr = v[i];
        int prev = i - 1;
        /*  move elems of v which are greater than curr
         *  to the position 1 + curr position
         */
        while(prev >= 0 && curr < v[prev]){
            v[prev + 1] = v[prev];
            prev -= 1;
            output(v);
        }
        v[prev + 1] = curr;
        output(v);
    }
}

int main(int argc, char *argv[]){
    if(argc < 3){
        cerr << "usage: " << USAGE << FLAGS << '\n';
        return EXIT_FAILURE;
    }

    bool insertion = false, gnome = false, bubble = false;
    int opt;

    opterr = 0;
    while((opt = getopt(argc, argv, "igb")) != -1){
        switch(opt){
            case 'g': gnome = true; break;
            case 'i': insertion = true; break;
            case 'b': bubble = true; break;
            default:
                      cout << argv[0] << ": illegal option, '-" << optopt << "'" << '\n';
                      cerr << "usage: " << USAGE << FLAGS << '\n';
                      return EXIT_FAILURE;
        }
    }
    if((insertion && gnome) || (gnome && bubble) || (insertion && bubble)){
        cout << argv[0] << ": Cannot specify more than one sort at once" << '\n';
        cerr << "usage: " << USAGE << FLAGS << '\n';
        return EXIT_FAILURE;
    }

    std::ifstream randFile (argv[optind]);
    vector<int> vinit;
    int a;

    while(randFile >> a){
        vinit.push_back(a);
    }

    output(vinit);
    if(insertion) insertionSort(vinit);
    if(gnome) gnomeSort(vinit);
    if(bubble) bubbleSort(vinit);

    return EXIT_SUCCESS;
}







