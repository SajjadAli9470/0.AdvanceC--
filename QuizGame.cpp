#include <iostream>
#include <string>
#include<fstream>
using namespace std;


void WriteInFile(bool IsScore,string NameOrTopic,int score){
   
   ofstream writeFile;
   
   writeFile.open("Players.txt",ios::app);
    string Status="";
	if(IsScore==true){
			    cout << "\n\t\t\t\t----------------------------------------\n";
				cout << "\t\t\t\t           TOPIC : "<<NameOrTopic<<"\n";
				cout << "\t\t\t\t\t      YOUR SCORE  " << score << "/10";
		    if(score>8){
		          Status="Excellent Job..";  
		    }
		    else if(score>5&&score<8){
		        Status="Nice but Play more to get more.......";
		    }
		    else{
		        Status="Never Give UP and TRY AGAIN and AGAIN........";
		        
		    }
		    cout<<"\n\t\t\t\tSTATUS : "<<Status<<endl;
			cout << "\n\t\t\t\t----------------------------------------\n";
		
		    writeFile<<NameOrTopic<<" : "<<score<<endl;
		
	}
    else{
    	writeFile<<"_________________"<<endl;
        writeFile<<"          PLAYER NAME : "<<NameOrTopic<<endl;
        writeFile<<"_________________"<<endl;
    }
    writeFile.close();
    cout<<"\t\t\t\tPRESS ANY KEY TO MOVE FURTHER------------>\n";
    system("pause");
}
void readFile(){
    ifstream ReadfrmFile;
    string record;
    ReadfrmFile.open("Players.txt");
    while(getline(ReadfrmFile,record) ){
        cout<<record<<endl;
    }
    ReadfrmFile.close();
    cout<<"\t\t\t\tPRESS ANY KEY TO MOVE FURTHER----->\n";
    system("pause");
}
void PleasureToUser()
{

	cout<<"\n\t\t\t\t--------------TEAM PROFILE-----------------\n";
    cout<<"\n\t\t\t\t     ZUNAIR ALI ABID____02-134211-057      \n";
    cout<<"\n\t\t\t\t     ZAIN-UL-ABIDEEN____02-134211-056      \n";
    cout<<"\n\t\t\t\t     TAHMEED AAKAS  __02-134211-063      \n";
    cout<<"\n\t\t\t\t     UBAID NAJAM    __02-134211-094      \n";
    cout<<"\n\t\t\t\t______LETS START GAME______\n\n";
	

}
int knowledge(){
	system("cls");
	cout<<"\n\t\t\t----------------GENERAL KNOWLEDGE---------------------------\n";
	char answer;
	int scores = 0;

	cout << "1-Which  the largest desert in the World?  : \n a)arabian  \t b)gobi \n c)sahara  \t d)australian \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";

	cout << "2-The first airline of Pakistan is____ : \n a)pak airways  \t b)PIA \n c)Orient Aitline  \t d)Airblue \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";

	cout << "3- Muhammad bin Qasim entered Sindh (Indo-Pakistan subcontinent) in ___ A.D.  : \n a)612  \t b)660 \n c)712  \t d)760 \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	
	cout << "4-Urdu was declared national language of Pakistan in:  : \n a)april 1952  \t b)april 1954 \n c)april 1956  \t d)april 1953 \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	cout << "5-Word Urdu means  : \n a)students  \t b)believers \n c)army  \t d)none of these \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	cout << "6-Who composed the verses of Pakistan national Anthem?  : \n a)Allama Iqbal  \t b)Faiz Ahmed faiz \n c)Nasir kazmi  \t d)Hafeez Jallandri \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";
	
	cout << "7-With which country, Pakistan share 2,430 km long border?  : \n a)india  \t b)iran \n c)afghanistan  \t d)china \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	
	cout << "8-Durand line was demarcated in 1893. This line forms:   \n a)pak-india boreder  \t b)pak-iran boredr \n c)pak-china border  \t d)pak-afghan border \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";
	
	cout << "9-Which mountain range has a length of 2700 km?  : \n a)himalaya  \t b)karakoram \n c)hindu kash  \t d)pir pinjai \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'a'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (a)\n"; }
	cout << "_____________________________\n";
	
	cout << "10-When did Pakistan win Olympic gold medal in Hockey for the first time?  : \n a)1952  \t b)1962 \n c)1968  \t d)1960 \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";

    WriteInFile(true,"General Knowledge ",scores);
	return 0;

}
int maths(){
	system("cls");
    cout<<"\n\t\t\t----------------MATHAMATICS---------------------------\n";
	char answer;
	int scores = 0;

	cout << "1-Two matrix A and B are equal if : \n a) They are square matrix \t b)they have same order \n c)corresponding elements are equal  \t d)no of coloumns are equal  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";

	cout << "2-Degree of x4 + 2x - 1  : \n a)0 \t b)-1 \n c)4  \t d)2  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	//--------3
	cout << "3-The quadratic eq. Having roots 2 and -  : \n a)-scores^2 + scores - 6 = 0 \t b)scores^2 + scores - 6 = 0 \n c)scores^2 - scores - 6 = 0  \t d)-scores^2 + scores + 6 = 0  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	//--------4
	cout << "4-A coin  tossed five times, total no. of outcomes  : \n a)2^2 \t b)2^3 \n c)2^5  \t d)2^4  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	//--------5
	cout << "5-How many kinds of trigonometry are? : \n a)one \t b)two \n c)three  \t d)four  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	//--------6
	cout << "6-the average of first 50 natural numbers are : \n a)21.25 \t b)25.5 \n c)12  \t d)25  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	//--------7
	cout << "7-What  2+2ï¿½2ï¿½2-2? : \n a)0 \t b)-2 \n c)2  \t d)1  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	//--------8
	cout << "8-men can eat 20 kg of rice in 3 days. How long will 6 men take to eat 40 kg of rice? : \n a)20 \t b)18 \n c)32  \t d)20  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	//--------9
	cout << "9-Certain quantity of food  sufficient for certain number of men for 13 days. After 1 day 2/5 of them desert how long will the food now last? : \n a)20 \t b)25 \n c)18  \t d)16  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'a'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (a)\n"; }
	cout << "_____________________________\n";
	//--------10
	cout << "10- 15 cattle can graze a field in 20 days 20 cattle can graze 3 such field in how many days? : \n a)30 \t b)45 \n c)60  \t d)50  \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	
	WriteInFile(true,"Mathamatics ",scores);
	return 0;
}
int intelligence(){
	system("cls");
cout<<"\n\t\t\t----------------INTELLEGINCE---------------------------\n";
	char answer;
	int scores = 0;
	string choice[10];
	choice[0] = "1- C  the father of D. But D  not the son of C. How  that possible?  : \n a)D  C's daughter  \t b)C  D's uncle \n c)both are brothers  \t d)they are not related \n Enter Correct Answer : ";
	choice[1] = "2-Before Mount Everest was discovered, what was the highest mountain on earth?  : \n a)K-2  \t b)Himalaya \n c)carmel  \t d)mount everest \n Enter Correct Answer : ";
	choice[2] = "3-What  the world's most populous country?  : \n a)russia  \t b)india \n c)china  \t d)USA \n Enter Correct Answer : ";
	choice[3] = "4- If peacocks do not lay eggs, how are baby peacocks born?  : \n a)live birth  \t b)in labs \n c)peahens have them  \t d)none of these \n Enter Correct Answer : ";
	choice[4] = "5-How can a man go 9 days without sleep?  : \n a)magic  \t b)surgery \n c)impossible  \t d)by sleeping during night \n Enter Correct Answer : ";
	choice[5] = "6-Which number logically follows this series?       4     6     9     6     14     6  ...   \n a)6  \t b)17 \n c)19  \t d)21 \n Enter Correct Answer : ";
	choice[6] = "7-Water  to a pipe as ?  to a wire.  : \n a)cord  \t b)electricity \n c)heat  \t d)gas \n Enter Correct Answer : ";
	choice[7] = "8-LIVE  to EVIL as 5232  to  : \n a)2523  \t b)3252 \n c)2325  \t d)3225 \n Enter Correct Answer : ";
	choice[8] = "9-select the odd one  : \n a)mango  \t b)apple \n c)potato  \t d)banana \n Enter Correct Answer : ";
	choice[9] = "10-Milk  to glass as letter  to  : \n a)pen  \t b)book \n c)stamp  \t d)envelope \n Enter Correct Answer : ";
	//-------1
	cout << choice[0];
	cin >> answer; if (answer == 'a'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (a)\n  D  the child of C. If C  not D's son, she must be D's daughter\n"; }
	cout << "_____________________________\n";

	//-------2
	cout << choice[1];
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n Mt. Everest was the tallest mountain on earth long before discovered it. It was always there.\n"; }
	cout << "_____________________________\n";

	//-------3
	cout << choice[2];
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";

	//-------4
	cout << choice[3];
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n Peacocks are the males of the species and peahens are the females. Females lay the eggs.\n"; }
	cout << "_____________________________\n";

	//-------5
	cout << choice[4];
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";

	//-------6
	cout << choice[5];
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";

	//-------7
	cout << choice[6];
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";

	//-------8
	cout << choice[7];
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";

	//-------9
	cout << choice[8];
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n potato  vegetable"; }
	cout << "_____________________________\n";

	//-------10
	cout << choice[9];
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";

WriteInFile(true,"Intellegence ",scores);
	return 0;
}
int sports(){
	system("cls");
    cout<<"\n\t\t\t----------------SPORTS---------------------------\n";
	int scores = 0;
	char answer;
	//-------1
	cout << "1-how many football worldcups does brazil have : \n a)3  \t b)4 \n c)5  \t d)2 \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	//-------2
	cout << "2-which cricketer known as rawalpindi express  : \n a)waqar younis  \t b)wasim akram \n c)shoib akhtar  \t d)imran khan \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	//-------3
	cout << "3- which captain won the most cricket worldcups : \n a)imran khan  \t b)kapil dev \n c)ricky ponting  \t d)brain lara \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	//-------4
	cout << "4- which country was about to host olympics 2020 : \n a)australia  \t b)brazil \n c)china  \t d)japan \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";
	//-------5
	cout << "5-who scored the winning goal for germany in 2014 world cup final  : \n a)gotze  \t b)muller \n c)kroos  \t d)neuer \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'a'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (a)\n"; }
	cout << "_____________________________\n";
	//-------6
	cout << "6- Ben Stokes  associated with the game of   : \n a)football  \t b)cricket\n c)basket ball  \t d)tennis \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	//-------7
	cout << "7-which football club has most champions league trophies  : \n a)real madrid  \t b)barcelona \n c)beyren munich  \t d)manchester united \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'a'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (a)\n"; }
	cout << "_____________________________\n";
	//-------8
	cout << "8-What  Usain Bolt's blistering 100m world record time?  : \n a)9.38 seconds  \t b)9.58 seconds \n c)9.98 seconds  \t d)8.78 seconds \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	//-------9
	cout << "9-how many squash worldcups did pakistan win so far  : \n a)21  \t b)22 \n c)23  \t d)24 \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";
	//-------10
	cout << "10-who won the kabaddi worldcup 2020  : \n a)india  \t b)iran \n c)australia  \t d)pakistan \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";

WriteInFile(true,"Sports ",scores);
	return 0;
}
int islam(){
	system("cls");
    cout<<"\n\t\t\t----------------ISLAMICS---------------------------\n";
	int scores = 0;
	char answer;
	cout << "1- Islam k pehlay mouzzin kon thay : \n a)Hazrat Ali  \t b)Hazrat Bilal \n c)Hazrat Khalid  \t d)Hazrat Usman \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";
	cout << "2- Quran ma kitnay sajday hain : \n a)10  \t b)12 \n c)16  \t d)14 \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";

	cout << "3-Quran ma kon si surat aik khatoon k nam pa ha  : \n a)Hazrat khadija(R)  \t b)Hazrat Fatima(R) \n c)Hazrat Maryam(a.s)  \t d)Hazrat Ayesha(R) \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";

	cout << "4-Ghazwa badar ma musalmano ki tadad kia thi  : \n a)1000  \t b)313 \n c)315  \t d)300 \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";

	cout << "5-Hazrat Muhammad (S.A.W) k damad kon thay  : \n a)Hazrat umer(R)  \t b)Hazrat Ali(R) \n c)Hazrat usman(R)  \t d)Hazrat Zain Bin Haris \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'b'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (b)\n"; }
	cout << "_____________________________\n";

	cout << "6- Islam ma sab sa bara gunah kon sa ha : \n a)Shirk  \t b)chori \n c)zina  \t d)qatal \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'a'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (a)\n"; }
	cout << "_____________________________\n";

	cout << "7- Bait  ul Muqaddas kis na fatah kia  : \n a)Salah ul din ayyubi  \t b)Muhammad Bin Qasim \n c)Tariq bin ziad  \t d)Mehmood ghaznavi \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'a'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (a)\n"; }
	cout << "_____________________________\n";

	cout << "8-The second Prophet of Allah was  : \n a)Hazrat Noah (A.S) \t b)Hazrat Ayub (A.S) \n c)Hazrat Shees (A.S)  \t d)none of these \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'c'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (c)\n"; }
	cout << "_____________________________\n";

	cout << "9-Sher e Khuda kis ka laqab tha   : \n a)Hazrat Umer(R) \t b)Hazrat Khalid Bin Waleeb(R) \n c)Hazrat Abu Bakar(R)  \t d)Hazrat Ali (R) \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'd'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (d)\n"; }
	cout << "_____________________________\n";

	cout << "10-Allah ki talwar kin sahabi ko kaha jata tha  : \n a)Hazrat Khalid Bin Waleed (R)  \t b)Hazrat Umer(R) \n c)Hazrat Abu Bakar (R)  \t d) Hazrat Ali(R) \n Enter Correct Answer : ";
	cin >> answer; if (answer == 'a'){ cout << "correct\n"; scores = scores + 1; }
	else{ cout << "CORRECT ANSWER :  (a)\n"; }
	cout << "_____________________________\n";

WriteInFile(true,"ISLAMIC ",scores);
	
	return 0;
}
int main(){

system("COLOR 70");
	PleasureToUser();
	string FullName;
	cout << "\n\t\t\t\t\t   DEAR PLAYER!\n\t\t\t\t\t INPUT YOUR NAME : ";   getline(cin,FullName);
    WriteInFile(false,FullName,0);
		int choice;
		
		do{
            system("cls");
			cout << "\t\t\t\t\t--------------OPTION FOR TOPIC------------- \n";
			cout << "\t\t\t\t        GENERAL KNOWLEDGE : PRESS (1)\n";
			cout << "\t\t\t\t        INTELLIGENCE      : PRESS (2)\n";
			cout << "\t\t\t\t        SPORTS            : PRESS (3)\n";
			cout << "\t\t\t\t        MATHS             : PRESS (4)\n";
			cout << "\t\t\t\t        ISLAMIC           : PRESS (5)\n";
			cout << "\t\t\t\t        DISPLAY RECORDS   : PRESS (6)\n";
			cout << "\t\t\t\t        EXIT              : PRESS (0) \n";
			cout << "\t\t\t\t        Please Enter Valid Choice to Select Topic :  ";   cin >> choice;
			switch(choice){
            case 1 : {
                 knowledge();
                 break;

                 }
			case 2 : { 
                intelligence();
                break; 
                }
			case 3 :{ 
                sports(); 
                break;
                }
			case 4 :{ 
                maths();
                break; 
                }
			case 5 :{
                 islam();
                 break;       
                 }
			case 6 :{
				readFile();
				break;
			}
			
            
            }
		} while (choice != 0);

        cout<<"\t\t\t\tPLAYER "<<FullName<<" Exited Successfully..........\n";
        cout<<"\t\t\t\t     .........DATA SAVED SUCCESSFULLY...........\n";

}