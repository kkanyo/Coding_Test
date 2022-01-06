#include <stdio.h>

//C style code
int main() {
    int hour, minute, second;
    char format[3];

    scanf("%d:%d:%d%s", &hour, &minute, &second, format);

    if (format[0] == 'A' && hour == 12) { hour = 0; }
    else if (format[0] == 'P' && hour < 12) { hour += 12; }

    printf("%02d:%02d:%02d", hour, minute, second);
}