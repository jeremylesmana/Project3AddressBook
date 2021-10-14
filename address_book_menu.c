#include <stdio.h>
#include <stdio_ext.h>
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

	do
	{
		main_menu();

		option = get_option(CHAR, "\rEnter 'N' to Ignore and 'Y' to Save: ");

		if (option == 'Y')
		{
			save_file(address_book);
			printf("Exiting. Data saved in %s\n", DEFAULT_FILE);

			break;
		}
	} while (option != 'N');

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

	return e_success;
}

void menu_header(const char *str)
{
	fflush(stdout);

	system("clear");

	printf("#######  Address Book  #######\n");
	if (str != '\0')
	{
		printf("#######  %s\n", str);
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

	do
	{
		main_menu();

		option = get_option(NUM, "");

		if ((address_book-> count == 0) && (option != e_add_contact))
		{
			get_option(NONE, "No entries found!!. Would you like to add? Use Add Contacts");

			continue;
		}

		switch (option)
		{
			case e_add_contact:
				/* Add your implementation to call add_contacts function here */
				break;
			case e_search_contact:
				search_contact(address_book);
				break;
			case e_edit_contact:
				edit_contact(address_book);
				break;
			case e_delete_contact:
				delete_contact(address_book);
				break;
			case e_list_contacts:
				break;
				/* Add your implementation to call list_contacts function here */
			case e_save:
				save_file(address_book);
				break;
			case e_exit:
				break;
		}
	} while (option != e_exit);

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
	int selection;
	do {
		menu_header("Search Contact to Edit by:");
		printf("0. Back\n");
		printf("1. Name\n");
		printf("2. Phone No\n");
		printf("3. Email ID\n");
		printf("4. Serial No\n");
		
		printf("Please select an option: ");
		scanf("%d", selection);
		menu_header("Search Result:");
		
		switch (selection) {
			case 0:
				menu(&address_book);
				break;

			case 1:
				char nameInput[32];
				printf("Enter the name: ");
				scanf("%s", nameInput);

				
				for(int i = 0; i < address_book->count; i++) //search until end of table ptr++ will increment by one
				{
					if(strcmp(address_book->list[i]->name[0],nameInput))//check if it equals the employee number
						printf(":%5d:%32s:%32s:%32s",addressbook->list[i]->si_no,addressbook->list[i]->name,address_book->list[i]->phone_numbers,address_book->list[i]->address);
						printf("===================================================================================");
				}
				break;

			case 2:
				char phoneInput[32];
				printf("Enter the phone number: ");
				scanf("%s", phoneInput);

				
				for(int i = 0; i < address_book->count; i++) //search until end of table ptr++ will increment by one
				{
					if(strcmp(address_book->list[i]->phone_numbers[0],phoneInput))//check if it equals the employee number
						printf(":%5d:%32s:%32s:%32s",addressbook->list[i]->si_no,addressbook->list[i]->name,address_book->list[i]->phone_numbers,address_book->list[i]->address);
						printf("===================================================================================");
				}
				break;

			case 3:
				char emailInput[32];
				printf("Enter the email: ");
				scanf("%s", emailInput);

				
				for(int i = 0; i < address_book->count; i++) //search until end of table ptr++ will increment by one
				{
					if(strcmp(address_book->list[i]->email_addresses[0],emailInput))//check if it equals the employee number
						printf(":%5d:%32s:%32s:%32s",addressbook->list[i]->si_no,addressbook->list[i]->name,address_book->list[i]->phone_numbers,address_book->list[i]->address);
						printf("===================================================================================");
				}
				break;

			case 4:
				int serialInput;
				printf("Enter the serial number: ");
				scanf("%d", serialInput);

				
				for(int i = 0; i < address_book->count; i++) //search until end of table ptr++ will increment by one
				{
					if(address_book->list[i]->si_no == serialInput)//check if it equals the employee number
						printf(":%5d:%32s:%32s:%32s",addressbook->list[i]->si_no,addressbook->list[i]->name,address_book->list[i]->phone_numbers,address_book->list[i]->address);
						printf("===================================================================================");
				}
				break;
					
		}
	} while (selection != 0);
}

Status edit_contact(AddressBook *address_book)
{
	/* Add the functionality for edit contacts here */
}

Status delete_contact(AddressBook *address_book)
{
	/* Add the functionality for delete contacts here */
}
