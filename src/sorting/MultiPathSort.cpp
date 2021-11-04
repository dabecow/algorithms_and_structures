#include "MultiPathSort.h"
#include <mem.h>
#include <math.h>

int mp_sort(const string file, int pathsNum){
    File* mFile = new File("./input.txt");
    if(open_file(mFile, READ) == -1)
        return -1;

    File** sFiles = (File**) malloc(sizeof(File*) * pathsNum * 2);

    int ioutFile = 0;
    int linesCount = 0;

    int activeFileNum = 0;
    int activeFileLinesNum = 0;

    int passCounter = 0;

    int* iMap = (int*) malloc(sizeof(int) * pathsNum * 2);

    if(mFile){
        for(int i = 0; i < pathsNum * 2; i++){
            char name[256];
            sprintf(name, "%s%d.txt", FOLDER, i);
            File* file = new File(name);
            open_file(file, WRITE);
            sFiles[i] = file;
        }

        do{
            char* line;
            read_line(mFile, &line);
            if(!sFiles[ioutFile]->empty)
                write_next(sFiles[ioutFile], ", ");
            write_next(sFiles[ioutFile], line);
            sFiles[ioutFile]->empty = false;
            ioutFile = loop(0, pathsNum, ioutFile + 1);
            linesCount++;
        }while(!feof(mFile->file));

        for(int i = 0; i < pathsNum; i++){
            close_file(sFiles[i]);
        }

        close_file(mFile);

        for(int i = 0; i < pathsNum * 2; i++){ //начальная инициализация индекной карты
            iMap[i] = i;
        }

        while(linesCount != 1){ //процесс слияния
            activeFileNum = min(linesCount, pathsNum);

            for(int i = 0; i < activeFileNum; i++){
                open_file(sFiles[iMap[i]], READ);
            }

            for(int i = pathsNum; i < pathsNum * 2; i++){
                open_file(sFiles[iMap[i]], WRITE);
            }

            int* iaMap = (int*) malloc(sizeof(int) * pathsNum);

            for(int i = 0; i < activeFileNum; i++){
                iaMap[i] = iMap[i];
            }

            linesCount = 0;
            ioutFile = pathsNum;

            while(activeFileNum != 0){ //проход
                linesCount++;
                passCounter++;
                activeFileLinesNum = activeFileNum;

                //read first number from all files lines to array
                Value* values = (Value*) malloc(sizeof(Value) * activeFileLinesNum);

                // int valueNum = activeFileLinesNum;

                if(!sFiles[iMap[ioutFile]]->empty)
                    write_next(sFiles[iMap[ioutFile]], ", ");

                for(int i = 0; i < activeFileLinesNum; i++){
                    char* v;
                    int count = read_next(sFiles[iaMap[i]], &v);

                    values[i].index = iaMap[i];
                    values[i].value = -1;
                    values[i].eof = false;
                    values[i].eol = false;

                    if(count == -1){
                        values[i].eof = true;
                        continue;
                    }
                    if(strcmp(v, ",") == 0){
                        values[i].eol = true;
                        continue;
                    }
                    values[i].value = atoi(v);
                }

                while(activeFileLinesNum != 0){

                    int minIndex = -1;
                    int min = INT32_MAX;

                    for(int i = 0; i < activeFileLinesNum;){
                        if(values[i].eof){
                            activeFileNum--;
                            activeFileLinesNum--;
                            values = delete_value(values, activeFileLinesNum + 1, values[i].index);
                            // iaMap = delete_index(iaMap, activeFileLinesNum + 1, values[i].index);
                            continue;
                        }
                        if(values[i].eol){
                            activeFileLinesNum--;
                            values = delete_value(values, activeFileLinesNum + 1, values[i].index);
                            // iaMap = delete_index(iaMap, activeFileLinesNum + 1, values[i].index);
                            continue;
                        }
                        i++;
                    }

                    // valueNum = activeFileLinesNum;

                    for(int i = 0; i < activeFileLinesNum; i++){
                        if(values[i].value <= min){
                            min = values[i].value;
                            minIndex = i;
                        }
                    }

                    if(activeFileLinesNum == 0){
                        continue;
                    }

                    char v[256];
                    sprintf(v, "%d ", values[minIndex].value);
                    write_next(sFiles[iMap[ioutFile]], v);
                    sFiles[iMap[ioutFile]]->empty = false;

                    //read next value

                    values[minIndex].value = -1;
                    values[minIndex].eof = false;
                    values[minIndex].eol = false;

                    char* val;
                    int count = read_next(sFiles[values[minIndex].index], &val);
                    if(count == -1)
                        values[minIndex].eof = true;
                    else{
                        if(strcmp(val, ",") == 0)
                            values[minIndex].eol = true;
                        else
                            values[minIndex].value = atoi(val);
                    }
                }
                ioutFile = loop(pathsNum, pathsNum * 2, ioutFile + 1);
            }

            //swap iMap

            for(int i = 0; i < pathsNum; i++){
                int temp = iMap[i];
                iMap[i] = iMap[i + pathsNum];
                iMap[i + pathsNum] = temp;
            }

            free(iaMap);
        }

        for(int i = 0; i < pathsNum * 2; i++){
            close_file(sFiles[i]);
        }
    }

    return passCounter;
}

FILE* open_read(const string name){
    return fopen(name.c_str(), "r");
}

FILE* open_write(const string name){
    return fopen(name.c_str(), "w");
}

int open_file(File* file, int mode){
    if(!file)
        return -1;

    if(file->opened)
        if(file->mode != mode)
            fclose(file->file);
        else
            return mode;

    switch(mode){
        case READ:
            file->file = fopen(file->name.c_str(), "r");
        break;
        case WRITE:
            file->file = fopen(file->name.c_str(), "w");
            file->empty = true;
        break;
    }

    file->mode = mode;
    file->opened = true;

    return mode;
}

void close_file(File* file){
    if(!file)
        return;

    if(file->opened){
        file->opened = false;
        fclose(file->file);
        file->file = NULL;
    }
}

int read_next(File* file, char** value){
    if(file){
        if(open_file(file, READ) == -1)
            return -1;
        *value = (char*) malloc(sizeof(char) * 256);
        int count = fscanf(file->file, "%s", *value);
        return count;
    }

    return -1;
}

int read_line(File* file, char** value){
    string str = "";

    if(file){
        char* num;
        while(read_next(file, &num) != -1){
            if(strcmp(num, ",") == 0){
                break;
            }
            str.append(num);
            str.append(" ");
        }
        
        *value = (char*) malloc(sizeof(char) * str.length() + 1);
        str.copy(*value, str.length(), 0);
        memset(*value + str.length() * sizeof(char), '\0', sizeof(char));
        //удалить мусор из строки
        return str.length();
    }
    return -1;
}

bool write_next(File* file, const char* value){
    if(file){
        if(open_file(file, WRITE) == -1)
            return false;
        fprintf(file->file, "%s", value);
        fflush(file->file);
        return true;
    }

    return false;
}

string int_to_string(int i){
    char* str = (char*) malloc(sizeof(char) * 256);
    sprintf(str, "%d", i);
    return string(str);
}

int loop(int a, int b, int i){
    if(i < a)
        return a;
    if(i >= b)
        return a;
    return i;
}

int* delete_index(int* arr, int length, int index){
    int* result = (int*) malloc(sizeof(int) * (length - 1));
    int offset = 0;
    for(int i = 0; i < length - 1; i++){
        if(arr[i] == index)
            offset = 1;
        result[i] = arr[i + offset];
    }

    free(arr);

    return result;
}

Value* delete_value(Value* arr, int length, int index){
    Value* result = (Value*) malloc(sizeof(Value) * (length - 1));
    int offset = 0;
    for(int i = 0; i < length - 1; i++){
        if(arr[i].index == index)
            offset = 1;
        result[i] = arr[i + offset];
    }

    free(arr);

    return result;
}
