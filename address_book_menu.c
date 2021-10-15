#include <stdio.h>
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
	/* Add the functionality for search contacts here */
}

Status edit_contact(AddressBook *address_book)
{
	/*
	we want to be able to grab input
	we'll print out prompts based on the user's inputs that delve into sections
	we first have to search what mode we want from the main menu and that's 3 or edit contact so keep that in mind
	*/
	int addressBookSize = address_book->count; //variables to help us deal with searching later on
	const AddressBook *endPtr = address_book + addressBookSize;
	int searchChoice;
	int tempStringInput[32];
	int finalStringInput[32];
	int tempSerial;
	int finalSerial;
	int serialSelector;
	char qzSelector;
	
	menu_header("Search contact to Edit by: \n"); //update the menu name to how the pdf wants it
	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone No\n");
	printf("3. Email ID\n");
	printf("4. Serial No\n");
	printf("\nPlease select an option: ");
	/*
	we then have to specify how we'll identify the person; it can be name, phone number, email, or a serial number
	- but there's also a back button to revert to a previous so implement like a while loop 
	once the option is selected, you'll input the actual value 
	- (i.e. 1 corresponds to name so the user types in the name of the person in a prompt after)
	*/
	scanf("%d", &searchChoice);
	if(searchChoice == 0){
		main_menu();
	}
	else if(searchChoice == 1){
		printf("Enter the Name: \n");
		scanf("%s", &tempStringInput);
		for(; address_book < endPtr; address_book++){
			if(strcmp(address_book->list->name, tempStringInput) == 0){
				/*
				once that's done, we display the contact info in a huge graphic like in 5.17
				- the graphic table prints out everyone with that same name
				- if two people with the same name existed, they get listed out

				menu_header("Search Result: \n");
				list_contacts(address_book, "Contact List", 0, "Search Result", e_edit); //MODES, not features for edit contact
				printf("\nPress: [s] = Select. [q] | Cancel: s\n");
				scanf("%s", qzSelector);
				if(selector == "q"){
					return e_back;
				}
				if(selector != "s"){ //this cannot be reached if q is typed in the selection
					return e_no_match;
				}
				printf("Select a Serial Number (S.No) to Edit: ")
				scanf("%d", serialSelector)
				*/
				printf("\nEnter Name to be changed: %s", &tempStringInput);
				scanf("%s", &tempStringInput);
				strcpy(address_book->list->name, tempStringInput);
			}
		}
	}
	else if(searchChoice == 2){
		printf("Enter Phone Number: \n");
		scanf("%s", &tempStringInput);
		for(; address_book < endPtr; address_book++){
			if(strcmp(address_book->list->phone_numbers, tempStringInput) == 0){
				/*
				menu_header("Search Result: \n");
				list_contacts(address_book, "Contact List", 0, "Search Result", e_edit); //MODES, not features for edit contact
				printf("\nPress: [s] = Select. [q] | Cancel: s\n");
				scanf("%s", qzSelector);
				if(selector == "q"){
					return e_back;
				}
				if(selector != "s"){ //this cannot be reached if q is typed in the selection
					return e_no_match;
				}
				printf("Select a Serial Number (S.No) to Edit: ")
				scanf("%d", serialSelector)
				*/
				printf("\nEnter Phone No to be changed: %s", &tempStringInput);
				scanf("%s", &tempStringInput);
				strcpy(address_book->list->phone_numbers, tempStringInput);
			}
		}
	}
	else if(searchChoice == 3){
		printf("Enter the Email ID: \n");
		scanf("%s", &tempStringInput);
		for(; address_book < endPtr; address_book++){
			if(strcmp(address_book->list->email_addresses, tempStringInput) == 0){
				/*
				menu_header("Search Result: \n");
				list_contacts(address_book, "Contact List", 0, "Search Result", e_edit); //MODES, not features for edit contact
				printf("\nPress: [s] = Select. [q] | Cancel: s\n");
				scanf("%s", qzSelector);
				if(selector == "q"){
					return e_back;
				}
				if(selector != "s"){ //this cannot be reached if q is typed in the selection
					return e_no_match;
				}
				printf("Select a Serial Number (S.No) to Edit: ")
				scanf("%d", serialSelector)
				*/
				printf("\nEnter Email ID to be changed: %s", &tempStringInput);
				scanf("%s", &tempStringInput);
				strcpy(address_book->list->email_addresses, tempStringInput);
			}
		}
	}
	else if(searchChoice == 4){
		printf("Enter the Serial No: \n");
		scanf("%d", &tempSerial);
		for(; address_book < endPtr; address_book++){
			if(address_book->list->si_no == tempSerial){
				/*
				menu_header("Search Result: \n");
				list_contacts(address_book, "Contact List", 0, "Search Result", e_edit); //MODES, not features for edit contact
				printf("\nPress: [s] = Select. [q] | Cancel: s\n");
				scanf("%s", qzSelector);
				if(selector == "q"){
					return e_back;
				}
				if(selector != "s"){ //this cannot be reached if q is typed in the selection
					return e_no_match;
				}
				printf("Select a Serial Number (S.No) to Edit: ")
				scanf("%d", serialSelector)
				*/
				printf("\nEnter Serial No to be changed: %d", &finalSerial);
				scanf("%d", &finalSerial);
				address_book->list->si_no = finalSerial;
			}
		}
	}

/*
	then we ask for what serial number they are specifically so we can work on that specific contact

	afterward, we can select what aspect of their contact we want to adjust with a number input again
	- we prompt them twice asking what is the position of the item we want to change
		- this means that we can have two phone numbers for example if they specify a position value that is + 1 the original amount
			- Note: I say position because it's actually one more than normal index starting at 0, refer to 5.19
	- the other prompt asks what we want to adjust the item to
		- if we specified the point previous to this, pressing enter by itself deletes the new entry
		- if we put an actual value though, then it gets saved along the new position

	then it shows us an updated version of the contact we adjusted 

	then pressing 0 or back will put us back on the menu like nothing changed while every other option would technically put us through the same loop
	*/
}

Status delete_contact(AddressBook *address_book)
{
	/* Add the functionality for delete contacts here */
}
