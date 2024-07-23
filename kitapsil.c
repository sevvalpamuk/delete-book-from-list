#include <stdio.h>

typedef struct Books{
    int id;
    char title[20];
}Book;

int main() {
    Book b;
    int idnum;
    FILE *src;
    FILE *dest;

    printf("Enter book id to be deleted: ");
    scanf("%d", &idnum);

    // Open the source file in read mode
    src = fopen("records.txt", "r");
    if (src == NULL) {
        printf("Not Found Fıle ");
        return 1;
    }

    // Open the temporary file in write mode
    dest = fopen("temp.txt", "w");
    if (dest == NULL) {
        printf("Not Found Fıle ");
        fclose(src);
        return 1;
    }

    // Read records from source file and write to temp file if they don't match idnum
    while (fscanf(src, "%d %s", &b.id, b.title) != EOF) {
        if (b.id != idnum) {
            fprintf(dest, "%d %s\n", b.id, b.title);
        }
    }

    // Close both files
    fclose(src);
    fclose(dest);

    // Remove the original file and rename the temporary file
    remove("records.txt");
    rename("temp.txt", "records.txt");

    return 0;
}
