#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "adjacencymatrix.h"

// Prompts menu with options
int menu();

// Opens and returns input file pointer (for reading)
FILE *set_input_file(const char fname[256]);

// Opens and returns output file pointer (for writing)
FILE *set_output_file(const char fname[256]);

// Create a graph from prompt
void create_graph();

// Prompts menu with applicable operations
void operations_menu();

//
int main(int argc, char *argv[]) {

    int choice;
    char fname[256];
    FILE *inf, *outf;

    matrix *m_in = *m_out = NULL;

    if (argc > 1) {
        inf = set_input_file();
        if (inf == NULL) exit(1);
        outf = inf;
        m_out = m_in = (matrix *) malloc(sizeof(matrix));
    }

    if (argc > 2) {
        outf = set_output_file();
        if (outf == NULL) exit(2);
    }

    do {
        choice = menu();
        switch (choice) {
            case 1:
                if (inf != NULL) {
                }

                printf("Enter file name: ");
                scanf("%s", &fname);
                inf = set_input_file(fname);

                break;
            case 2:
                if (outf != NULL) {
                }

                printf("Enter file name: ");
                scanf("%s", &fname);
                outf = set_output_file(fname);
                break;
            case 3:
                create_graph();
                break;
            case 4:
                operations_menu();
                break;
            case 0:
                break;
        }
    } while (choice != 0);

    return 0;
}

void create_graph() {}
void operations_menu() {}

// Prompts menu with options
int menu() {

    int choice, valid = 0;
    do {
        printf("Menu\n");
        printf("1. Load graph from file.\n");
        printf("2. Save current graph to file.\n");
        printf("3. Create graph from scratch.\n");
        printf("4. Apply operation.\n");
        printf("0. Exit.\n");
        scanf("%d", &choice);
        valid = choice <= 0 && choice > 4;
        if (!valid) printf("Bad option number: %d. Choose 1, 2, 3 or 4.", choice); 
    } while (!valid);
    return choice;
}

// Opens and returns input file pointer (for reading)
FILE *set_input_file(const char fname[256]) {
    FILE *fp = NULL;

    if (access(fname, F_OK) != -1) {
        printf("Opening %s for reading.\n", fname);
        fp = fopen(fname, 'r');
    } else {
        printf("File %s does not exist. Aborting.\n", fname);
    }

    return fp;
}

// Opens and returns output file pointer (for writing)
FILE *set_output_file(const char fname[256]) {

    FILE *fp;

    if (access(fname, F_OK) != -1) {
        printf("File %s already exists. Proceed anyway? (y/n)", fname);
        scanf("%c", &choice);
        if (choice == 'n' || choice == 'N') {
            printf("Aborting.\n");
            return NULL;
        }
    }

    printf("Opening %s for writing.\n", fname);
    fp = fopen(fname, 'w');

    return fp;
}

