#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

extern int errno ;

#include "address_book.h"

Status load_file(AddressBook *address_book)
{
	int ret=0;
	int errnum;
	address_book->fp=fopen(DEFAULT_FILE,"r+");
	address_book= malloc(sizeof(AddressBook)*10);

	/* 
	 * Check for file existance
	 */
	if(!(address_book->fp=fopen(DEFAULT_FILE,"r"))){
		ret=1;
		printf("address_book.csv does not exist, creating new csv file");
		fclose(address_book->fp);
		
	}

	if (ret == 0){
		address_book->fp=fopen(DEFAULT_FILE,"r+");
		errnum=errno;
		fprintf(stderr, "Value of errno: %d\n", errno);
      	perror("Error printed by perror");
      	fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));

		char buffer[32];
		int row=0, column = 0;
		while(fgets(buffer,40,address_book->fp)){
			column=0;
			row++;
			if(row==1)
				continue;

			char* value = strtok(buffer, ", ");
			while(value){
				if(column==0)
					strcpy(address_book->list->name,value);

				if(column==1)
					strcpy(address_book->list->phone_numbers,value);

				if(column==2)
					strcpy(address_book->list->email_addresses,value);

				value=strtok(NULL,", ");
				column++;
			}
			address_book->count = row-1;
		}
		fclose(address_book->fp);
	}
	else{
		address_book->fp = fopen(DEFAULT_FILE,"w");
		/* Create a file for adding entries */
	}
	return e_success;
}

Status save_file(AddressBook *address_book)
{
	char buffer[32];
	/*
	 * Write contacts back to file.
	 * Re write the complete file currently
	 */ 

	address_book->fp = fopen(DEFAULT_FILE, "w");
	
	while(fgets(buffer,40,address_book->fp)){
		fprintf(address_book->fp,"hello%s,%s,%s\n", address_book->list->name,address_book->list->phone_numbers,address_book->list->email_addresses);
	}


	if (address_book->fp == NULL)
	{
		printf("Saving failed");
		return e_fail;
	}

	/* 
	 * Add the logic to save the file
	 * Make sure to do error handling
	 */ 

	fclose(address_book->fp);

	return e_success;
}