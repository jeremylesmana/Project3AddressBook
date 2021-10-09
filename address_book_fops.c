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
	address_book->fp=fopen(DEFAULT_FILE,"r");

	/* 
	 * Check for file existance
	 */
	if(!(address_book->fp=fopen(DEFAULT_FILE,"r"))){
		ret=1;
		printf("address_book.csv does not exist, creating new csv file");
		fclose(address_book->fp);
	}

	if (ret == 0)
	{
		errnum=errno;
		fprintf(stderr, "Value of errno: %d\n", errno);
      	perror("Error printed by perror");
      	fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
		address_book->fp=fopen(DEFAULT_FILE,"r+");

		/* 
		 * Do the neccessary step to open the file
		 * Do error handling
		 */ 
	}
	else
	{
		address_book->fp = fopen(DEFAULT_FILE,"w");
		/* Create a file for adding entries */
	}

	return e_success;
}

Status save_file(AddressBook *address_book)
{
	/*
	 * Write contacts back to file.
	 * Re write the complete file currently
	 */ 


	address_book->fp = fopen(DEFAULT_FILE, "w");

	if (address_book->fp == NULL)
	{
		return e_fail;
	}

	/* 
	 * Add the logic to save the file
	 * Make sure to do error handling
	 */ 

	fclose(address_book->fp);

	return e_success;
}
