#include <dos.h>
#include <dir.h>
#include <io.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

char destinatie[PATH_MAX];
char vechi[PATH_MAX];
int max_depth = -1;
int max_length = -1;
int include_hidden = 0;

void recursiveTraverse(char *path, int depth);
int is_hidden(struct _finddata_t *fileinfo);
int directory_exists(const char *dir);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s [options] source_directory destination_directory\n", argv[0]);
        return 1;
    }

    strcpy(destinatie, argv[argc - 1]);
    printf("Destination set to: %s\n", destinatie);

    if (chdir(argv[argc - 2]) != 0) {
        perror("Failed to change directory");
        return 1;
    }
    printf("Changed directory to: %s\n", argv[argc - 2]);

    for (int i = 1; i < argc - 2; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            include_hidden = 1;
        } else if (strncmp(argv[i], "-dx", 3) == 0) {
            max_depth = atoi(argv[i] + 3);
            printf("Max depth set to: %d\n", max_depth);
        } else if (strncmp(argv[i], "-lx", 3) == 0) {
            max_length = atoi(argv[i] + 3);
            printf("Max length set to: %d\n", max_length);
        }
    }

    if (strstr(destinatie, argv[argc - 2]) == destinatie) {
        fprintf(stderr, "Destination cannot be a subdirectory of source.\n");
        return 1;
    }

    recursiveTraverse(argv[argc - 2], 0);
    return 0;
}

void recursiveTraverse(char *path, int depth) {
    printf("path: %s", path);
    char searchPath[PATH_MAX];
    char newPath[PATH_MAX];
    char mutat[PATH_MAX];
    int value;
    struct _finddata_t fileinfo;

    snprintf(searchPath, sizeof(searchPath), "%s", path);
    value = _findfirst(searchPath, &fileinfo);

    while (_findnext(value, &fileinfo) == 0) {
        if (strcmp(fileinfo.name, "..") != 0 && strcmp(fileinfo.name, ".") != 0) {
            if (max_length == -1 || fileinfo.size <= max_length) {
                if (include_hidden || !is_hidden(&fileinfo)) {
                    snprintf(mutat, sizeof(mutat), "%s\\%s", destinatie, fileinfo.name);
                    if (rename(fileinfo.name, mutat) == 0) {
                        printf("Moved: %s to %s\n", fileinfo.name, mutat);
                    } else {
                        perror("Error moving file");
                    }
                }
            }
        }

        if (fileinfo.attrib & _A_SUBDIR) {
            
            if (max_depth == -1 || depth < max_depth) {
                snprintf(newPath, sizeof(newPath), "%s\\%s", path, fileinfo.name);
                // printf("newPath: %s, path: %s, fileinfo.name: %s", newPath, path, fileinfo.name);

                snprintf(vechi, sizeof(vechi), "%s\\%s", destinatie, fileinfo.name);
                // printf("vechi: %s, destinatie: %s, fileinfo.name: %s", vechi, destinatie, fileinfo.name);
                if (!directory_exists(vechi)) {
                    mkdir(vechi);
                    printf("Created directory: %s\n", vechi);
                } else {
                    printf("Directory already exists: %s\n", vechi);
                }
                recursiveTraverse(newPath, depth + 1);
            }
        }
    }

    _findclose(value);
}

int is_hidden(struct _finddata_t *fileinfo) {
    return fileinfo->attrib & _A_HIDDEN;
}

int directory_exists(const char *dir) {
    struct _finddata_t fileinfo;
    int value = _findfirst(dir, &fileinfo);
    if (value == 0) {
        _findclose(value);
        return fileinfo.attrib & _A_SUBDIR;
    }
    return 0;
}