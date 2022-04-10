#include <cstdio>
#include <string>

void logError(std::string str) {
    printf("\033[41;37m[ERROR] %s\033[0m\n", str.c_str());
}
void logError(char* str) {
    printf("\033[41;37m[ERROR] %s\033[0m\n", str);
}
void logWarning(std::string str) {
    printf("\033[43;30m[WARNING] %s\033[0m\n", str.c_str());
}
void logWarning(char* str) {
    printf("\033[43;30m[WARNING] %s\033[0m\n", str);
}