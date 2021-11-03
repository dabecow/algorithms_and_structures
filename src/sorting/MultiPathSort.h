#ifndef MULTIPATHSORT_H
#define MULTIPATHSORT_H

#include <string>

#define SEPARATOR ","

using namespace std;

void mp_sort(const string file);

FILE* open_read(const string name);
FILE* open_write(const string name);
int read_next(FILE* file, char* value);
void write_next(FILE* file, char* value);

#endif