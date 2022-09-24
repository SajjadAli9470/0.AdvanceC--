#include <iostream>
#include<string>
#include <iomanip>
#include<cstdlib>
#include<stdio.h>


using namespace std;
void pd();			//====about the developers====
void archive();		//+++about archive+++
void dis();
void display();		//+++for displaying added books++
void displaylist();		//FOR DISPLAYING WISHLIST
void displaynotes();		//FOR DISPLAYING NOTES
void createnotes();		//====FOR CREATING NOTES====
void wishlist();		//==TO ADD BOOK IN WISH LIST====
void genralinfo();		//----FOR GWNERAL INFORMATION----
void aboutarchive();		//+++ABOUT ARCHIVE++
void privacypolicy();		//_PRIVACY POLICY__
void bliabrary();		// (MAIN LIABRARY)
void display();		//FOR DISPLAYING BOOKS IN "BOOKS LIABRARY"
void add();			//===-====for adding book in archive(ADITION FUNCTION)===-====-=
void sort();			//==-===to sort books in archive(SORTING FUNCTION)==-====
void sortname();		//SORTING BY NAME 
void sortid();			//SORTING BY ID 
void sortauthor();		//SORTING BY AUTHORS NAME 


struct book
{
	int bookid;
	char bookname[100];		//BOOK DETAILS
	char authorname[60];
	char booknotes[500];
	char booklist[100];
};

book books[1000];		//ARRAY OF CODE
int n = 0;			//GLOBAL VARIABLE OF CODE

int
main()
{
	system("CLS");
	system("coclor 74");

	string UserName;
	string UserPassword;
	cout <<
		"         HI! please enter your username and password to login to READING ARCHIVE\n";
	cout <<
		"         ========================================================================\n\n\n";
	int loginAttempt = 0;
	while (loginAttempt < 3)
	{
		cout << "Please user name: ";
		cin >> UserName;
		cout << "Please enter password: ";
		cin >> UserPassword;

		if (UserName == "saba" && UserPassword == "computer")
		{
			cout << "THANK YOU FOR LOGGIG IN MS.saba!\n";
			break;
		}
		else if (UserName == "areeba" && UserPassword == "mindyourownbusiness")
		{
			cout << "THANK YOU FOR LOGGING IN MS.AREEBA!\n\n\n";
			break;
		}
		else
		{
			cout << "INVALID LOGIN !. Please try again.\n\n\n" << '\n';
			loginAttempt++;
		}
	}
	if (loginAttempt == 3)
	{
		cout << "LOGIN LIMIT EXCEEDED ! program will terminate\n";
		return 0;
	}
	char y;
	cout << "                            WELCOME TO READING ARCHIVE \n";
	cout << "                          ======+====+====+====+======\n\n\n";
	cout << "HI !IM DEN (^_^)\n\n";
	cout << " ill be your guide in the archive \n\n";
	while (1)
	{
		cout << "      INDEX      \n";
		cout << "====+========+====\n\n\n";
		cout << "den(^_^) :PRESS THE ELOTED NO. THAT U WOULD LIKE TO DO\n\n";
		cout << " a.   BOOK LIABRARY\n";
		cout << " b.   CREATE NOTES\n";
		cout << " c.   WHISHLIST\n";
		cout << " d.   DISPLAY\n";
		cout << " e.   GENERAL INFORMATION\n";
		cout << " f.   ABOUT ARCHIVE\n";
		cout << " g.   PRIVACY POLICIY\n";
		cout << " h.   EXIT\n";
		cin >> y;

		switch (y)
		{
		case '1':
		case 'a':
			bliabrary();
			break;
		case '2':
		case 'b':
			createnotes();
			break;
		case '3':
		case 'c':
			wishlist();
			break;
		case '4':
		case 'd':
			dis();
			break;
		case '5':
		case 'e':
			genralinfo();
			break;
		case '6':
		case 'f':
			aboutarchive();
			break;
		case '7':
		case 'g':
			privacypolicy();
			break;
		case '8':
		case 'h':
			exit(0);
			break;



		}			//SWITCH CLOSED

	}				//WHILE CLOSED

}

void
bliabrary()			//BOOK LIABRARY
{

	char z;
	cout << "      BOOK LIABRARY\n";
	cout << "     ================\n";
	cout <<
		"DEN^-^: HERE YOU CAN DO THE FOLLOWING SLECT THE ELOTED ALPHABET ACORRDINGLY\n";
	cout <<
		"----------------------------------------------------------------------------\n";
	cout << " (a). TO ADD A BOOK\n";
	cout << " (b) .  Sort A BOOK\n";
	cout << "DEN(^-^):press any alphabet key to return to index";

	cin >> z;
	switch (z)
	{
	case '1':
	case 'a':
		add();
		break;
	case '2':
	case 'b':
		sort();
		break;


	}				//CLOSING SWITCH TWO! 
}

//NOTES
void
createnotes()
{
	char ch;
	do
	{
		cout << "(^_^): NOTES\n";
		cout << "=====================";
		cout << endl;
		cout << " DEN (^-^): HERE YOU CAN WRITE YOUR NOTES\n";
		cout << "======================================\n";
		cout << "TYPE THEM DOWN: ";
		cin >> books[n].booknotes;
		n++;
		cout << "Do you want to add more books? [y/n]";
		cin >> ch;
	} while (ch != 'n' && ch != 'N');

}

//WISHLIST
void
wishlist()
{

	char ch;
	do
	{
		cout << "(^_^): WISHLIST\n";
		cout << "=====================";
		cout << endl;
		cout <<
			" DEN (^-^): HERE YOU CAN WRITE THE NAME AND DETAILS OF THE BOOK THAT YOU MIGHT WANNA READ\n";
		cout <<
			"=========================================================================================\n";
		cout << "Enter Book Name: ";
		cin >> books[n].booklist;
		n++;
		cout << "Do you want to add more books? [y/n]";
		cin >> ch;
	} while (ch != 'n' && ch != 'N');
}

//GENERAL INFORMATION
void
genralinfo()
{
	cout << "(^_^): GENERAL INFO\n";
	cout << "=====================\n";
	cout << "DEN (^-^)\n";
	cout << " WHAT IS THIS ARCHIVE?\n\n";
	cout <<
		"(^-^): it helps you sort the book , create notes you want to save,and keep track of the book you want to read\n\n";
	cout << "WHAT IS THE PURPOSE OF THIS ARCHIVE?\n\n";
	cout <<
		"(^-^):Where the world has gone from paper letter to txt messages, it is only fair to have handwritten book, to be converted digitally, that will make them easier to carry and reach, just a touch away. Though that is available one would need to have a place where they can have all their books, together and be able to keep track of their bookmarks and have their finished and unfinished books sorted at a single place to make it easier .That is the main purpose for making our project\n\n";
	cout << "WHAT CAN YOU DO IN THIS ARCHIVE?";
	cout << "(*)	To provide a login id and password to keep their archive save"
		<< endl <<
		"(*)To provide the user with the option of choice or what they want to do within the archive"
		<< endl << "(*)To be able to keep their books sorted" << endl <<
		"(*)To be able to sort book according to size	" << endl <<
		"(*)To keep open and sealed book (not read) separated" << endl <<
		"(*)This will make reading easier" << endl <<
		"(*)To give them the accommodation to search for books within archive"
		<< endl <<
		"(*)They can create folder for different types of book like: favorite, re-reading etc.\n";
}

void
aboutarchive()
{

	char A;
	cout << "         about archive     \n";
	cout << "==================================\n\n";
	cout << "HI! (^-^)~\n ";
	cout << " what do u want to know\n";
	cout << " (a)about the ARCHIVE\n";
	cout << " (b)about THE PROGRAM DEVELOPERS\n";
	cin >> A;
	switch (A)
	{
	case '1':
	case 'a':
		archive();
		break;
	case '2':
	case 'b':
		pd();
		break;

	}				//CLOSING SWITCH THREE!
}

//PROGRAM DEVELOPERS
void
pd()
{
	cout << "(^_^): DEVELOPERS\n";
	cout << "=====================\n";
	cout << "DEN (^-^):\n";
	cout << "THIS PROGRAM IS DEVELOPED BY\n";
	cout << "(*)AAMNA ILYAS\n";
	cout << "================\n";
	cout << "contact no: 02-134202-017\n";
	cout << "age: 18 years old (29/10/2002)\n";
	cout << "studies at :BAHRIA UNIVERSITY\n";
	cout << "degree:UNDERGRADUATE\n";
	cout << "(*)Faisal Jamil Ahmed\n";
	cout << "================\n";
	cout << "contact no: 02-134202-059\n";
	cout << "age: 18 years old (6/1/2001)\n";
	cout << "studies at :BAHRIA UNIVERSITY\n";
	cout << "degree:UNDERGRADUATE\n";
	cout << "(*)Farah siddiqui\n";
	cout << "================\n";
	cout << "contact no: 02-134202-081\n";
	cout << "age: 18 years old (4/9/2002)\n";
	cout << "studies at :BAHRIA UNIVERSITY\n";
	cout << "degree:UNDERGRADUATE\n";
}

//ABOUT ARCHIVE
void
archive()
{

	cout << "(^_^): ABOUT ARCHIVE\n";
	cout << "=====================\n\n\n";
	cout <<
		"We are proactive and innovative in protecting and defending our work from commercial exploitation and legal challenge. We preserve our fannish economy, values, and creative expression by protecting and nurturing our fellow fans, our work, our commentary, our history, and our identity while providing the broadest possible access to fannish activity for all fans.\n";

}

//PRIVACY POLICY
void
privacypolicy()
{
	cout << "         PRIVACY POLICY     \n";
	cout << "===============================\n";
	cout << "DEN^-^\n\n";
	cout <<
		" (->)We do not sell the data that you write here would not be visible to third parties, and we do not include or accept paid advertisements from third parties. Each of the OTW Sites has Terms of Service and a Privacy Policy that explains what information we collect, how we use it and who we share it with; your use of any of the OTW Sites is governed by that site's Terms and Policy.We strive to make each OTW Site's Terms of Service (ToS) and Privacy Policy readable.\n";
	cout <<
		" (->)We have tried to provide explanations for the more unusual legal terms. If you have terminology questions not covered here, Law.com's glossary may help, though we cannot vouch for the accuracy of outside sources, including those referenced in the ToS.\n ";
	cout <<
		" (->)You expressly agree that the OTW shall not be liable to you for any damages of any kind (even if the OTW has been advised of the possibility of such damages) resulting from the Service, including but not limited to your use of or inability to use the Service; unauthorized access to or changes in Content or information you submit; and the acts and statements of third parties who use the Service.\n";
	cout <<
		" (->)Any material you download, view, or otherwise access through the Service is at your own risk. You will be solely responsible for any damage or loss of data that results from the download of any such material.\n";
	cout <<
		" (->)Subject to the next paragraph of this policy, this license exists only for as long as you choose to continue to include such Content on the Archive and will terminate within a reasonable time after you remove or the OTW removes such Content from the Archive. We will always strive to make your Content unavailable to users as soon as possible should you choose to remove it. Though removed Content will not be publicly available, for legal and disaster recovery purposes we may retain backup copies for longer periods.\n";

}

//TO ADD A NEW BOOK
void
add()
{

	char ch; char id1[6];
	do
	{

		cout << endl;
		cout << "ADDING BOOKS\n";
		cout << "Enter Book Name: ";
		cin >> books[n].bookname;
		cout << "Enter Book ID: ";
		cin >> books[n].bookid;
		cout << "Enter Author Name: ";
		cin >> books[n].authorname;

		n++;
		cout << "Do you want to add more books? [y/n]";
		cin >> ch;
	} while (ch != 'n' && ch != 'N');
}

//SORTING BOOK
void
sort()
{

	char J;
	cout << "            SORTING BOOKS\n";
	cout << "             ================\n";
	cout << "DEN(^-^) :  Please choose one of the options below: \n";
	cout << "------------------------------------------------------------\n\n";
	cout << "( N ) Sort by name\n\n";
	cout << "( I ) Sort by Id\n\n";
	cout << "( T ) Sort by author name\n\n";
	cin >> J;

	switch (J)
	{
	case 'n':
	case 'N':
		sortname();
		break;

	case 'i':
	case 'I':
		sortid();
		break;

	case 't':
	case 'T':
		sortauthor();
		break;

		cin >> J;
	}				//SWITCH 4 CLOSED
}

//SORTING BY NAME 
void
sortname(void)
{
	int i, j;
	book temp;

	cout << endl;
	cout << "Sorting by Name\n";
	cout << "================\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if ((books[j].bookname, books[j + 1].bookname) > 0)
			{
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}
	display();
}

//SORTING BY ID 
void
sortid(void)
{

	{
		int i, j;
		book temp;

		cout << endl;
		cout << "Sorting by Id\n";
		cout << "================\n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if (books[j].bookid > books[j + 1].bookid)
				{
					temp = books[j];
					books[j] = books[j + 1];
					books[j + 1] = temp;
				}
			}
		}
		display();
	}



}

//SORTING BY AUTHORS NAME
void
sortauthor(void)
{


	int i, j;
	book temp;

	cout << endl;
	cout << "Sorting by Authors Name\n";
	cout << "=========================\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if ((books[j].authorname, books[j + 1].authorname) > 0)
			{
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}
	display();

}

//display
void
dis()
{

	char A;
	cout << "         display     \n";
	cout << "==================================\n\n";
	cout << "HI! (^-^)~\n ";
	cout << " what do u want to SEE\n";
	cout << " (a)WHISHLIST\n";
	cout << " (b)NOTES\n";
	cin >> A;
	switch (A)
	{
	case '1':
	case 'a':
		displaylist();
		break;
	case '2':
	case 'b':
		displaynotes();
		break;

	}				//CLOSING SWITCH THREE!
}

//DISPLAY BOOKS
void
display(void)
{

	cout << " BOOKS INDEX\n";
	cout << "___" << "_________________"
		<< "__________" << endl;
	cout << setw(10) << "\"Book ID\"" << setw(50) << "\"Book Name\"" <<
		setw(30) << "\"Author Name\"" << endl;
	cout << "___" << "_________________"
		<< "__________" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << books[i].bookid << setw(50) << books[i].
			bookname << setw(30) << books[i].authorname << setw(30) << endl;
		cout << "____" <<
			"__________________" <<
			"__________" << endl;
	}
	cout << "Press enter to goto main manu.....";

}

//DISPLAY wishlist
void
displaylist(void)
{

	cout << " WISHLIST\n";
	cout << "========\n\n\n";
	cout << "____" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << books[i].booklist << endl;
		cout << "____" << endl;
	}
	cout << "Press enter to goto main manu.....";
}

//DISPLAY NOTES
void
displaynotes(void)
{

	cout << " NOTES\n";
	cout << "========\n\n\n";
	cout << "____" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << books[i].booknotes << endl;
		cout << "____" << endl;
	}
	cout << "Press enter to goto main manu.....";

}