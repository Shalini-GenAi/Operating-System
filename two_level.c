#include <stdio.h>
#include <string.h>

struct File { char fname[20]; };
struct Directory {
    char dname[20];
    struct File files[10];
    int fileCount;
};

int main() {
    struct Directory dirs[5];
    int dirCount = 0, choice, i, j;
    char dname[20], fname[20];

    while (1) {
        printf("\n1.Create Dir 2.Create File 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Dir name: "); scanf("%s", dirs[dirCount].dname);
            dirs[dirCount].fileCount = 0; dirCount++;
        }
        else if (choice == 2) {
            printf("Dir name: "); scanf("%s", dname);
            for (i = 0; i < dirCount; i++) {
                if (strcmp(dirs[i].dname, dname) == 0) {
                    printf("File name: "); scanf("%s", fname);
                    strcpy(dirs[i].files[dirs[i].fileCount++].fname, fname);
                }
            }
        }
        else if (choice == 3) {
            for (i = 0; i < dirCount; i++) {
                printf("Dir: %s\n", dirs[i].dname);
                for (j = 0; j < dirs[i].fileCount; j++)
                    printf("  %s\n", dirs[i].files[j].fname);
            }
        }
        else break;
    }
}
