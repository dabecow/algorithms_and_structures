#ifndef MULTIPATHSORT_H
#define MULTIPATHSORT_H

#include <string>

#define READ 0
#define WRITE 1
#define SEPARATOR ","
#define FOLDER "temp_files/"

using namespace std;

struct File{
    string name;
    FILE* file;
    bool opened;
    int mode;

    File(string name) : name(name){
        file = NULL;
        opened = false;
        mode = 0;
    }
};

struct Value{
    int value;
    bool eof;
    bool eol;
    int index;
};

void mp_sort(const string file, int pathsNum);

static int open_file(File* file, int mode);
static void close_file(File* file);
static FILE* open_read(const string name);
static FILE* open_write(const string name);
static int read_next(File*, char** value);
static int read_line(File* file, char** value);
static bool write_next(File* file, const char* value);

static string int_to_string(int i);
static int loop(int a, int b, int i);
static int* delete_index(int* arr, int length, int index);

#endif