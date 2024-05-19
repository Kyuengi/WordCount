#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
  
// ��������  
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
        printf("�ַ�����%d\n", result);  
    } else if (strcmp(parameter, "-w") == 0) {  
        result = count_words(file);  
        printf("��������%d\n", result);  
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
    // �����ļ�ָ�뵽�ļ���ʼ�Ա�������ܵĶ�ȡ  
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
    // ����ļ��Ե��ʽ�β�������Ӽ���  
    if (in_word) {  
        count++;  
    }  
    // �����ļ�ָ�뵽�ļ���ʼ�Ա�������ܵĶ�ȡ  
    rewind(file);  
    return count;  
}
