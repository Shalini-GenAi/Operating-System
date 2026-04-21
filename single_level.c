#include <stdio.h>
#include <string.h>

struct Directory {
    char fname[20];
} dir[10];

int main() {
    int n = 0, choice;
    char name[20];
    
    while (1) {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (n >= 10) {
                    printf("Directory Full! Cannot add more files.\n");
                } else {
                    printf("Enter file name: ");
                    scanf("%s", dir[n].fname);
                    n++;
                    printf("File created successfully.\n");
                }
                break;
                
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", name);
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (strcmp(dir[i].fname, name) == 0) {
                        found = 1;
                        for (int j = i; j < n - 1; j++) {
                            strcpy(dir[j].fname, dir[j + 1].fname);
                        }
                        n--;
                        printf("File deleted successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("File not found.\n");
                }
                break;
                
            case 3:
                printf("Enter file name to search: ");
                scanf("%s", name);
                found = 0;
                for (int i = 0; i < n; i++) {
                    if (strcmp(dir[i].fname, name) == 0) {
                        found = 1;
                        printf("File found: %s\n", dir[i].fname);
                        break;
                    }
                }
                if (!found) {
                    printf("File not found.\n");
                }
                break;
                
            case 4:
                if (n == 0) {
                    printf("Directory is empty.\n");
                } else {
                    printf("Files in Directory:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%s\n", dir[i].fname);
                    }
                }
                break;
                
            case 5:
                return 0;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
