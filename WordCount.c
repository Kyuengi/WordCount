#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
  
// 函数声明  
int count_characters(FILE *file);  
int count_words(FILE *file);  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    char *parameter = argv[1];  
    char *filename = argv[2];  
  
    FILE *file = fopen(filename, "r");  
    if (!file) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    int result;  
    if (strcmp(parameter, "-c") == 0) {  
        result = count_characters(file);  
        printf("字符数：%d\n", result);  
    } else if (strcmp(parameter, "-w") == 0) {  
        result = count_words(file);  
        printf("单词数：%d\n", result);  
    } else {  
        printf("Invalid parameter. Use -c or -w.\n");  
        result = 1;  
    }  
  
    fclose(file);  
    return result;  
}  
  
int count_characters(FILE *file) {  
    int count = 0;  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        count++;  
    }  
    // 重置文件指针到文件开始以便后续可能的读取  
    rewind(file);  
    return count;  
}  
  
int count_words(FILE *file) {  
    int count = 0;  
    int in_word = 0;  
    char ch;  
  
    while ((ch = fgetc(file)) != EOF) {  
        if (isspace(ch) || ch == ',') {  
            if (in_word) {  
                in_word = 0;  
                count++;  
            }  
        } else {  
            in_word = 1;  
        }  
    }  
    // 如果文件以单词结尾，则增加计数  
    if (in_word) {  
        count++;  
    }  
    // 重置文件指针到文件开始以便后续可能的读取  
    rewind(file);  
    return count;  
}
