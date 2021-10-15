#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "address_book_fops.h"
#include "address_book_menu.h"
#include "address_book.h"

int get_option(int type, const char *msg)
{
	/*
	 * Mutilfuction user intractions like
	 * Just an enter key detection
	 * Read an number
	 * Read a charcter
	 */ 

	/* Fill the code to add above functionality */
}

Status save_prompt(AddressBook *address_book)
{
	char option;

	//do
	//{
		//main_menu();

		// option = get_option(CHAR, "\rEnter 'N' to Ignore and 'Y' to Save: ");

		// if (option == 'Y')
		// {
		// 	save_file(address_book);
		// 	printf("Exiting. Data saved in %s\n", DEFAULT_FILE);
		// 	//break;
		// }
	//} while (option != 'N');

	free(address_book->list);

	return e_success;
}

Status list_contacts(AddressBook *address_book, const char *title, int *index, const char *msg, Modes mode)
{
	/* 
	 * Add code to list all the contacts availabe in address_book.csv file
	 * Should be menu based
	 * The menu provide navigation option if the entries increase the page size
	 */ 
	char buffer[32];
	int row=index, column = 0;
	menu_header(title);
	printf("=============================================================================================================\n");
	printf(":S.No : Name \t\t\t\t: Phone.No \t\t\t  : Email ID \t\t\t    :\n");
	printf("=============================================================================================================\n");

	while(fgets(buffer,40,address_book->fp)){
		column=0;
		row++;
		
		if(row==1)
			continue;
		printf(": %d   :", row-1);
		char* value = strtok(buffer, ", ");

		while(value){
			if(column==0)
				printf(" %-32s:", value);

			if(column==1)
				printf(" %-32s:", value);

			if(column==2){
				//if(row<temp){
					value[strlen(value)-1]='\0';
				//}
				printf(" %-32s:\n", value);
			}

			value=strtok(NULL,", ");

			column++;
		}
		printf("=============================================================================================================\n");
	}
	int *test = row-1;
	printf("there are %d people in your book", test);

	fclose(address_book->fp);

	return e_success;
}

void menu_header(const char *str)
{
	fflush(stdout);

	//system("clear");

	printf("#######  Address Book  #######\n");
	if (*str != '\0')
	{
		printf("#######  %s:\n", str);
	}
}

void main_menu(void)
{
	menu_header("Features:\n");

	printf("0. Exit\n");
	printf("1. Add Contact\n");
	printf("2. Search Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Delete Contact\n");
	printf("5. List Contacts\n");
	printf("6. Save\n");
	printf("\n");
	printf("Please select an option: ");
}

Status menu(AddressBook *address_book)
{
	ContactInfo backup;
	Status ret;
	int option;
	// do
	// {
	// 	main_menu();

	// 	option = get_option(NUM, "");

	// 	if ((address_book-> count == 0) && (option != e_add_contact))
	// 	{
	// 		get_option(NONE, "No entries found!!. Would you like to add? Use Add Contacts");

	// 		continue;
	// 	}

	// 	switch (option)
	// 	{
	// 		case e_add_contact:
	// 			/* Add your implementation to call add_contacts function here */
	// 			break;
	// 		case e_search_contact:
	// 			search_contact(address_book);
	// 			break;
	// 		case e_edit_contact:
	// 			edit_contact(address_book);
	// 			break;
	// 		case e_delete_contact:
	// 			delete_contact(address_book);
	// 			break;
			//case e_list_contacts:
				list_contacts(address_book,"Contact List",0,"Search Result",e_list);
				//break;
				/* Add your implementation to call list_contacts function here */
	// 		case e_save:
	 			save_file(address_book);
	// 			break;
	// 		case e_exit:
	// 			break;
	// 	}
	// } while (option != e_exit);

	return e_success;
}

Status add_contacts(AddressBook *address_book)
{
	/* Add the functionality for adding contacts here */
}

Status search(const char *str, AddressBook *address_book, int loop_count, int field, const char *msg, Modes mode)
{
	/* Add the functionality for adding contacts here */
}

Status search_contact(AddressBook *address_book)
{
	/* Add the functionality for search contacts here */
}

Status edit_contact(AddressBook *address_book)
{
	/* Add the functionality for edit contacts here */
}

Status delete_contact(AddressBook *address_book)
{
	/* Add the functionality for delete contacts here */
}