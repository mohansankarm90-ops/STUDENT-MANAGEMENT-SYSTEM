#include<iostream>
#include<string>
#include<fstream> //for using ofstream and ifstream
#include<cstdio>  //for Renaming and Removing
using namespace std;

struct Student
{
	int roll_no;
	int mark[5];
	string name;	
};
void addDetails()
{
	Student	S;
	cout<<"Enter Roll No of Student: "; 
	cin>>S.roll_no;
	
	cout<<"Enter Name of Student: "; 
	cin.ignore();
	getline(cin,S.name);
	
	cout<<"Enter Mark of Student: ";
	for(int i=0;i<5;i++)
	{
	 cin>>S.mark[i];
	cout<<"\n";
	}

	ofstream file("Student-Data.dat",ios::app);     //Opening & writing the details in the file opened
	file<< S.roll_no <<" " <<S.name<<" "; 		// value trasnfered from variable to file 
	for(int i=0;i<5;i++){ file<<S.mark[i]<<" "; }
	file<<"\n";
	file.close();					//Closing the File
}
void displayDetails()
{
	Student S;
	
	ifstream file("Student-Data.dat",ios::in);     //Opening & Reading from the exisxting file
	while(file>>S.roll_no) 
	{
	   cout<<"===================================================================================\n";
	   cout<<"\t\t"<<"Student-Details For Roll No: "<<S.roll_no<<"\n"; 
	   cout<<"___________________________________________________________________________________\n";
	   cout<<"\t\t"<<"ROll-NO	 : "<<S.roll_no<<"\n"; 
	   file>>S.name; 
	   cout<<"\t\t"<<"Name Of Student: "<<S.name<<"\n"; 
	   cout<<"\t\t"<<"Student's Marks: ";	   
		for(int i=0;i<5;  i++)
		{
		   file>>S.mark[i];
		   cout<<S.mark[i];
		}
	}cout<<"\n";
	   cout<<"===================================================================================\n";
	file.close(); //closing the files
}
void deleteDetails()
{
	Student S;
	int enteredRollNo;
	cout<<"Enter Roll-NO of Student to Delete Their Details: ";
	cin>>enteredRollNo;
	ifstream file1("Student-Data.dat",ios::in);  // Opening & Reading from the first file
	ofstream file2("Temp.dat",ios::out);         // Opening & writing at the newly opened second file
	while(file1>>S.roll_no)			     // loop used for each student for each iteration
	{	
			file1>>S.name;
			for(int i=0;i<5;i++){ file1>>S.mark[i]; }

	 	if(S.roll_no != enteredRollNo)       //if mismatch occurs data transfered to the second file
		{
			file2<<S.roll_no<<" "<<S.name<<" ";
			for(int i=0;i<5;i++){ file2<<S.mark[i]<<" "; }
			file2<<"\n";
		}  				    // if match occurs copying data is skipped, and gets deleted later 
	}
	file1.close(); // closing the files
	file2.close();
	remove("Student-Data.dat"); 		    //Deleting the first file
	rename("Temp.dat","Student-Data.dat");	    //Replacing 1 with 2 
}
void updateDetails()
{
	Student S;
	int enteredRollNo;
	cout<<"Enter The Roll-No of Student Whose Details To Be Updated: ";
	cin>>enteredRollNo;
	ifstream file1("Student-Data.dat",ios::in);
	ofstream file2("Temp.dat",ios::out);
	while(file1>>S.roll_no)
	{
			file1>>S.name;
			for(int i=0;i<5;i++){ file1>>S.mark[i]; }

	 	if(S.roll_no == enteredRollNo)
		{
		      cout<<"Enter New Name : ";
		      cin.ignore();
		      getline(cin,S.name);
		      cout<<"Enter New Marks: ";
			for(int i=0;i<5;i++)	
			{
			cin>>S.mark[i];	
			}
			
		      file2<<S.roll_no<<" "<<S.name<<" ";
			for(int i=0;i<5;i++)
			{
				file2<<S.mark[i];
			}
			file2<<"\n";
		}
		else 		
		{
		      file2<<S.roll_no<<" "<<S.name;
		        for(int i=0;i<5;i++)
			{
				file2<<S.mark[i];
			}
		}
		file2<<"\n";
	}
	file1.close();
	file2.close();
	remove("Student-Data.dat");
	rename("Temp.dat","Student-Data.dat");
	
}
int main()
{

int choice;

   do
   {
	cout<<"\n";
cout<<"\t\t"<<"  ╔══════════════════════════════╗\n";
cout<<"\t\t"<<"  ║   STUDENT MANAGEMENT SYSTEM  ║\n";
cout<<"\t\t"<<"  ╠══════════════════════════════╣\n";
cout<<"\t\t"<<"  ║  1. Add Student              ║\n";
cout<<"\t\t"<<"  ║  2. Update Student           ║\n";
cout<<"\t\t"<<"  ║  3. Delete Student           ║\n";
cout<<"\t\t"<<"  ║  4. Display Students         ║\n";
cout<<"\t\t"<<"  ║  5. Exit                     ║\n";
cout<<"\t\t"<<"  ╚══════════════════════════════╝\n";
cout<<"\t\t"<<"  Enter Choice: ";
		cin>>choice;

	switch(choice)
	{
	case 1:
		addDetails();
		break;
	case 2:
		updateDetails();
		break;
	case 3:
		deleteDetails();
		break;
	case 4:
		displayDetails();
		break;
	default:
		cout<<"Invalid Choice-Select from 1 -> 4";
		break;
	}
    }while(choice!=5);

}
