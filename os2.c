#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {

    int fd;
    char c;
    char str[152];
    int i = 0, j = 0;
    int bytesread;
    int flag = 1;
    int found = 0;
    int line = 1;
    int foundflag = 1;

    char w[] = {'h', 'e', 'l', 'l', 'o'};
    int len = strlen(w);

    if ((fd = open("hello.txt", O_RDONLY, 0)) != -1) { //if 1

        bytesread = read(fd, &c, 1);
        str[j] = c;
        j++;

        if (bytesread != -1) { //if 2

            while (bytesread != 0) { //while

                if (c == '\n')
                    line++;

                if (c == w[i]) { //if 3
                    i++;
                    flag = 0;
                } else if (flag == 0 || i == len) //end of f3
                { // else 3
                    i = 0;
                    flag = 1;
                }// end of else 3
                else if (flag == 1) {
                    while (read(fd, &c, 1)) {
                        str[j] = c;
                        j++;
                        if (c == ' ')
                            break;
                        if (c == '\n') {
                            line++;
                            break;
                        }
                    }
                }

                bytesread = read(fd, &c, 1);
                str[j] = c;
                j++;

                if ((c == ' ' || c == '\n') && flag == 0 && i == len) {
                    found++;
                    foundflag = 0;
                    printf("w was found in line %d.\n", line);
                }

                if ((c == '\n')&&(foundflag == 0)) {

                    for (j = 0; str[j] != '\n'; j += 5) {
                        printf("%c", str[j]);

                        if (str[j + 1] != '\n')
                            printf("%c", str[j + 1]);
                        else {
                            j++;
                            break;
                        }

                        if (str[j + 2] != '\n')
                            printf("%c", str[j + 2]);
                        else {
                            j += 2;
                            break;
                        }

                        if (str[j + 3] != '\n')
                            printf("%c", str[j + 3]);
                        else {
                            j += 3;
                            break;
                        }

                        if (str[j + 4] != '\n')
                            printf("%c", str[j + 4]);
                        else {
                            j += 4;
                            break;
                        }
                    }

                    for (; str[j] != '\n'; j++)
                        printf("%c", str[j]);

                    printf("\n");
                    j = 0;

                } else if (c == '\n')
                    foundflag = 1;

            } //end of while
            printf("w has occured %d times.\n", found);

        } else //end of if 2
            printf("couldn't read file.\n");

    } else //end of if 1
        printf("Couldn't open file for read.\n");

    close(fd);
}
