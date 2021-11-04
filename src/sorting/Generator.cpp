#include "Generator.h"

void create_file(string name, int min, int max, int number){
    FILE* file = fopen(name.c_str(), "w");
    for(int i = 0; i < number; i++){
        int m = min;
        while(m != max - 1){
            int v = rand() % (max - m) + m;
            if(v > min)
                m = v;
            
            fprintf(file, "%d ", v);
        }
        fprintf(file, ", ");
    }

    fclose(file);
}