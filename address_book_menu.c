#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "address_book_fops.h"
#include "address_book_menu.h"
#include "address_book.h"

int get_option(int type, const char *msg)
{
	int temp;
	char temp2;
	printf("%s",msg);

	if(type==1){
		scanf("%d",&temp);
		return temp;
	}
	if(type==2){
		scanf(" %c", &temp2);
		if (temp2 == 'Y')
			return temp2;
		else
			return temp2;
	}
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
	char* temp;
	char value = '\n';
	char option;
	do{
		menu_header("List Contact Result:");
		printf("\n==========================================================================================================\n");
		printf(":%-5s:%-32s:%-32s:%-32s:","S. No","Name","Phone Number","Email Address");
		printf("\n==========================================================================================================\n");
		for(int i = 1; i <= address_book->count; i++) 
		{

			temp = address_book->list[i].email_addresses[0];
			temp[strlen(temp)-1]='\0';
			printf("\n:%-5d:%-32s:%-32s:%-32s:", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
			printf("\n==========================================================================================================\n");
			strncat(address_book->list[i].email_addresses[0], "\n",address_book->list[i].email_addresses[0]);
		}
		option = get_option(CHAR,"Enter Q to exit: ");
	}while(option != 'Q');
	return e_success;
}

void menu_header(const char *str)
{
	fflush(stdout);

	system("cls");

	printf("#######  Address Book  #######\n");
	if (str != '0')
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

		option = get_option(NUM,"");

		if ((address_book->count == 0) && (option != e_add_contact))
		{
			get_option(NONE, "No entries found!!. Would you like to add? Use Add Contacts");
			continue;
		}

		switch (option)
		{
		case e_add_contact:
			add_contacts(address_book);
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
			list_contacts(address_book,"Search Result:",0,"",e_list);
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
	char nameInput[32] = ""; 
	char phoneInput[32] = ""; 
	char emailInput[32] = ""; 
	int checkPh = 0, checkEmail = 0;
	int option;
	char randomKey[10] = "";
	do
	{
		menu_header("Add contact:");

		printf("0. Back\n");
		printf("1. Name       : %s\n", nameInput);
		printf("2. Phone No   : %s\n", phoneInput);
		printf("3. Email ID   : %s\n", emailInput);
		printf("\nPlease select an option:");
		scanf("%d",&option);

		switch (option)
		{
		case 1:
			printf("Enter the Name : ");
			scanf("%s", nameInput);
			
			break;
			
		case 2:
			printf("Enter the Phone No:");

			scanf("%s", phoneInput);

			if ((strlen(phoneInput) < 10))
				checkPh = 1;
			else
				checkPh = 0;

			if(checkPh == 1){
				printf("invalid phone no\n");
				strcpy(phoneInput,"");
			}
			break;

		case 3:
			printf("3. Email ID :");
			scanf("%s", emailInput);
			break;

		case 0:
			if(strcmp(nameInput, "") != 0 && strcmp(phoneInput, "") != 0  && strcmp(emailInput, "") != 0 ) {
				strcpy(address_book->list[address_book->count + 1].name[0],nameInput);
				strcpy(address_book->list[address_book->count + 1].phone_numbers[0],phoneInput);
				strcpy(address_book->list[address_book->count + 1].email_addresses[0],emailInput);
				address_book->list[address_book->count + 1].si_no = address_book->count + 1;
				strncat(address_book->list[address_book->count + 1].email_addresses[0], "\n",address_book->list[address_book->count].email_addresses[0]);
				address_book->count++;
			}
			else {
				printf("Contact not added because of missing element\nReturning to main menu\n\nEnter any key to continue:");
				scanf("%s", randomKey);
			}
			menu(address_book);
			break;
		}
	} while (option != e_exit);

	return e_success;
}

Status search(const char *str, AddressBook *address_book, int loop_count, int field, const char *msg, Modes mode)
{
	/* Add the functionality for adding contacts here */
}

Status search_contact(AddressBook *address_book)
{
	int selection;
	int serialInput=0;
	char nameInput[32];
	char phoneInput[32];
	char emailInput[32];
	char randomKey[10];
	char* temp;
	do {
		search_top:
		menu_header("Search Contact by:");
		printf("0. Back\n");
		printf("1. Name\n");
		printf("2. Phone No\n");
		printf("3. Email ID\n");
		printf("4. Serial No\n");
		printf("Please select an option: ");

		scanf("%d", &selection);
		int found = 0;
		switch (selection) {
			case 0:
				menu(address_book);
				break;
			case 1:
				printf("Enter the name: ");
				scanf("%s", nameInput);
				menu_header("Search Result:");
				printf("\n================================================================================================================================");
				printf("\n:%5s:%32s:%32s:%32s:\n","S. No","Name","Phone Number","Email Address");
				
				for(int i = 0; i <= address_book->count; i++) 
				{
					if(strcmp(address_book->list[i].name[0], nameInput) == 0){
						found = 1;
						printf("\n:%5d%32s%32s%32s", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
						printf("\n================================================================================================================================");
					}
				}
				if(found == 0) {
					printf("\nNo entries found with name %s\n\n", nameInput);
					printf("\nPress any key to continue: ");
					scanf("%s", randomKey);
					goto search_top;
				}
				else {
					printf("\nPress any key to continue: ");
					scanf("%s", randomKey);
					goto search_top;
				}
			case 2:
				printf("Enter the phone number: ");
				scanf("%s", phoneInput);
				menu_header("Search Result:");
				printf("\n================================================================================================================================");
				printf("\n:%5s:%32s:%32s:%32s:","S. No","Name","Phone Number","Email Address");
				
				for(int i = 0; i <= address_book->count; i++) 
				{
					if(strcmp(address_book->list[i].phone_numbers[0], phoneInput) == 0){
						found = 1;
						printf("\n:%5d:%32s:%32s:%32s:", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
						printf("\n================================================================================================================================\n");
					}
				}
				if(found == 0) {
					printf("\nNo entries found with name %s\n\n", phoneInput);
					printf("\nPress any key to continue: ");
					scanf("%s", randomKey);
					goto search_top;
				}
				else {
					printf("\nPress any key to continue: ");
					scanf("%s", randomKey);
					goto search_top;
				}
			case 3:
				printf("Enter the email address: ");
				scanf("%s", emailInput);
				menu_header("Search Result:");
				
				printf("\n================================================================================================================================");
				printf("\n:%5s:%32s:%32s:%32s:\n","S. No","Name","Phone Number","Email Address");
				
				for(int i = 0; i <= address_book->count; i++) 
				{
					temp = address_book->list[i].email_addresses[0];
					temp[strlen(temp)-1]='\0';
					if(strcmp(address_book->list[i].email_addresses[0], emailInput) == 0){
						found = 1;
						printf("\n:%5d:%32s:%32s:%32s:", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
						printf("\n================================================================================================================================\n");
					}		
					strncat(address_book->list[i].email_addresses[0], "\n",address_book->list[i].email_addresses[0]);
				}
				if(found == 0) {
					printf("\nNo entries found with email address %s\n\n", emailInput);
					printf("\nPress any key to continue: ");
					scanf("%s", randomKey);
					goto search_top;
				}
				else {
					printf("\nPress any key to continue: ");
					scanf("%s", randomKey);
					goto search_top;
				}
			case 4:
				printf("Enter the serial number: ");
				scanf("%d", &serialInput);
				menu_header("Search Result:");
				printf("\n================================================================================================================================");
				printf("\n:%5s:%32s:%32s:%32s:\n","S. No","Name","Phone Number","Email Address");
				
				for(int i = 0; i <= address_book->count; i++) 
				{
					if(address_book->list[i].si_no == serialInput){
						found = 1;
						printf("\n:%5d:%32s:%32s:%32s:", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
						printf("\n================================================================================================================================\n");
					}
				}
				if(found == 0) {
					printf("\nNo entries found with serial number %d\n\n", serialInput);
					printf("\nPress any key to continue: ");
					scanf("%s", randomKey);
					goto search_top;
				}
				else {
					printf("\nPress any key to continue: ");
					scanf("%s", randomKey);
					goto search_top;
				}
		}
		printf("\nTotal number of contacts: %d\n",address_book->count);

	} while (selection != 0);
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
	int editChoice;
	char tempStringInput[32];
	char finalStringInput[32];
	int tempSerial;
	int serialSelector;
	int checker = 0;
	char qzSelector[1];
	char randomKey[10];
	char* temp;

	searchEdit_top:
	
	menu_header("Search Contact to Edit by: \n"); //update the menu name to how the pdf wants it
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
	switch(searchChoice){
	case 0:
		main_menu();
		break;
	case 1:
		printf("Enter the Name: \n");
		scanf("%s", &tempStringInput);
		break;
	case 2:
		printf("Enter the Phone No: \n");
		scanf("%s", &tempStringInput);
		break;
	case 3:
		printf("Enter the Email ID: \n");
		scanf("%s", &tempStringInput);
		break;
	case 4:
		printf("Enter the Serial No: \n");
		scanf("%d", &tempSerial);
		break;
	}

	menu_header("Search Result:");
	printf("\n================================================================================================================================");
	printf("\n:%5s:%32s:%32s:%32s:\n","S. No","Name","Phone Number","Email Address");

	if(searchChoice == 1){	
		for(int i = 0; i <= address_book->count; i++){
			if(strcmp(address_book->list[i].name[0],tempStringInput) == 0){
				checker = 1;
				printf("\n:%5d%32s%32s%32s", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
				printf("\n================================================================================================================================\n");
			}
		}
		if(checker == 0){
			printf("\nNo entries found with search query %s\n\n", tempStringInput);
			printf("\nPress any key to continue: ");
			scanf("%s", randomKey);
			goto searchEdit_top;
		}
	}

	if(searchChoice == 2){
		for(int i = 0; i <= address_book->count; i++) {
			if(strcmp(address_book->list[i].phone_numbers[0], tempStringInput) == 0){
				checker = 1;
				printf("\n:%5d:%32s:%32s:%32s:", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
				printf("\n================================================================================================================================\n");
			}
		}
		if(checker == 0){
			printf("\nNo entries found with search query %s\n\n", tempStringInput);
			printf("\nPress any key to continue: ");
			scanf("%s", randomKey);
			goto searchEdit_top;
		}
	}

	if(searchChoice == 3){
		for(int i = 0; i <= address_book->count; i++) 
				{
					temp = address_book->list[i].email_addresses[0];
					temp[strlen(temp)-1]='\0';
					if(strcmp(address_book->list[i].email_addresses[0], tempStringInput) == 0){
						checker = 1;
						printf("\n:%5d:%32s:%32s:%32s:", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
						printf("\n================================================================================================================================\n");
					}		
					strncat(address_book->list[i].email_addresses[0], "\n",address_book->list[i].email_addresses[0]);
				}
		if(checker == 0){
			printf("\nNo entries found with search query %s\n\n", tempStringInput);
			printf("\nPress any key to continue: ");
			scanf("%s", randomKey);
			goto searchEdit_top;
		}
	}

	if(searchChoice == 4){
		for(int i = 0; i <= address_book->count; i++) {
			if(address_book->list[i].si_no == tempSerial){
				checker = 1;
				printf("\n:%5d:%32s:%32s:%32s:", address_book->list[i].si_no, address_book->list[i].name[0], address_book->list[i].phone_numbers[0], address_book->list[i].email_addresses[0]);
				printf("\n================================================================================================================================\n");
			}
		}
		if(checker == 0){
			printf("\nNo entries found with search query %s\n\n", tempStringInput);
			printf("\nPress any key to continue: ");
			scanf("%s", randomKey);
			goto searchEdit_top;
		}
	}

	
	printf("\nPress: [s] = Select. [q] | Cancel: ");
	scanf("%s", &qzSelector);
	if(strcmp(qzSelector, "q") == 0){
		menu(edit_contact);
	}
	if(strcmp(qzSelector, "s") == 0){
		printf("Select a Serial Number (S.No) to Edit: ");
		scanf("%d", &serialSelector);
		for(int i = 0; i < address_book->count; i++){
			if(address_book->list[i].si_no == serialSelector){
				printf("0. Back\n");
				printf("1. Name       : %s\n", address_book->list[i].name[0]);
				printf("2. Phone No   : %s\n", address_book->list[i].phone_numbers[0]);
				printf("3. Email ID   : %s\n", address_book->list[i].email_addresses[0]);
				printf("\nPlease select an option:");
				scanf("%d", &editChoice);
				if(editChoice == 0){
					menu(edit_contact);
				}
				if(editChoice == 1){
					printf("\nEnter Name to be changed: ");
					scanf("%s", &finalStringInput);
					strcpy(address_book->list[i].name[0], finalStringInput);
					break;
				}
				if(editChoice == 2){
					printf("\nEnter Phone No to be changed: ");
					scanf("%s", &finalStringInput);
					strcpy(address_book->list[i].phone_numbers[0], finalStringInput);
					break;
				}
				if(editChoice == 3){
					printf("\nEnter Email ID to be changed: ");
					scanf("%s", &finalStringInput);
					strcpy(address_book->list[i].email_addresses[0], finalStringInput);
					break;
				}
			}
		}
	}
}

Status delete_contact(AddressBook *address_book)
{
    char nameInput[32] = "";
    char phoneInput[32] = "";
    char emailInput[32] = "";

    int option, siNo;

    menu_header("Search contact to Delete by: \n");
    printf("0. Back\n");
    printf("1. Name\n");
    printf("2. Phone No\n");
    printf("3. Email ID\n");
    printf("4. Serial No\n");
    printf("\nPlease select an option: ");
    scanf("%d", &option);

    if (address_book->count == 0)
    {
        printf("Address book is empty and cannot be deleted");
        return;
    }

    switch (option)
    {
    case 0:
        menu(address_book);
        break;
    case 1:
        printf("Enter the Name: ");
        scanf("%s", nameInput);

        for (int i = 0; i <= address_book->count; i++)
        {
            if (strcmp(address_book->list[i].name[0], nameInput) == 0)
            {
                for (int j = i; j <= address_book->count; j++)
                {
                    address_book->list[j] = address_book->list[j + 1];
                }
            }
        }
        address_book->count--;
        break;
    case 2:
        printf("Enter the Phone No: ");
        scanf("%s", phoneInput);
        for (int i = 0; i <= address_book->count; i++)
        {
            if (strcmp(address_book->list[i].phone_numbers[0], phoneInput) == 0)
            {
                printf("%d", i);
                for (int j = i; j <= address_book->count; j++)
                {
                    address_book->list[j] = address_book->list[j + 1];
                }
            }
        }
        address_book->count--;
        break;
    case 3:
        printf("Enter the Email ID: ");
        scanf("%s", emailInput);
        for (int i = 0; i <= address_book->count; i++)
        {
            if (strcmp(address_book->list[i].email_addresses[0], emailInput) == 0)
            {
                printf("%d", i);
                for (int j = i; j <= address_book->count; j++)
                {
                    address_book->list[j] = address_book->list[j + 1];
                }
            }
        }
        address_book->count--;
        break;
    case 4:
        printf("Enter the Serial Number: ");
        scanf("%d", &siNo);
        for (int i = 0; i <= address_book->count; i++)
        {
            if (address_book->list[i].si_no == siNo)
            {
                printf("%d", i);
                for (int j = i; j <= address_book->count; j++)
                {
                    address_book->list[j] = address_book->list[j + 1];
                }
            }
        }
        address_book->count--;
        break;
    }
    return e_success;
}