#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    printf("\n");
    
    DIR *dirr;
    struct dirent * item;
    struct stat info;
    int size = 0;

    //--------------------Directory Size--------------------------------
    dirr = opendir(".");//opening directory
    while ((item = readdir(dirr)) != NULL ){//checking if next item exists and assigning
	stat(item->d_name, &info);//getting metadata about item
	size += info.st_size;
    }
    closedir(dirr);
    printf("Total directory size: %d Bytes\n\n", size);

    //--------------------Directory Printing--------------------------------
    dirr = opendir(".");//opening directory
    printf("Printing directories:\n");
    while ((item = readdir(dirr)) != NULL ){//checking if next item exists and assigning
	//sprintf(path, "%s", item->d_name);
	stat(item->d_name, &info);//getting metadata about item
	if (! S_ISREG(info.st_mode)){//checking if item is directory
	    printf("\t%s\n", item->d_name);//printing item name
	}
    }
    closedir(dirr);

    printf("\n");

    dirr = opendir(".");

    //--------------------File Printing--------------------------------
    printf("Printing files:\n");
    while ((item = readdir(dirr)) != NULL ){
	//sprintf(path, "%s", item->d_name);
	stat(item->d_name, &info);
	if (S_ISREG(info.st_mode)){
	    printf("\t%s\n", item->d_name);
	}
    }
    closedir(dirr);

    printf("\n");
    
    return 0;
}
