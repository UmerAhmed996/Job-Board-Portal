#include<iostream>
#include<fstream>
using namespace std;

void job_seekers();
void employer();
void SignInMenu(char*);
void SignInMenu_U(char*);
void SignUpMenu();
void SignUpMenu_U();
bool PassCheck(char*, char*);
void UpdatePass(char* password, char* username);
void copyfile(char* file1, char* file2);
void PassUpdateMenu(char*);
void usertotxt(char*, char*);
int size_arr(char* arr);
void ModifyMenu(char username[]);
void ModifyMenu_U(char username[]);
void menue();
void Post_Item();
void modify_Item();
void List_Of_Posted_Items();
bool compare_array(char* arr1, char* arr2);
void view_list_of_job();
void search_job();
void copyarr(char filename[], char username[]);

int main()
{
	menue();
	return 0;
}
void menue()
{
	int num = 0;
	system("cls");

	cout << endl << endl << endl;

	cout << "               <><><><><><><><><><><><><><><><><><><>	" << endl;
	cout << "                         WELCOME TO JOB AGENCY 	" << endl;
	cout << "               <><><><><><><><><><><><><><><><><><><>  ";
	cout << "\n\n\t\t\t\ 1.Job Seeker mode (1)\n\t\t\t\ 2.Employer mode(2)\n\t\t\t\ 3.Exit(3)" << endl;
	cout << "\n\t\t    Please enter your choice:";
	cin >> num;
	switch (num)
	{
	case 1:
		job_seekers();
		break;
	case 2:
		employer();
		break;
	case 3:
		cout << "Good bye " << endl;
		break;
	}
}
void Apply()
{
	system("cls");
	char* job_title = nullptr;
	char* category = nullptr;
	char* city = nullptr;
	char* deadline = nullptr;
	char* details = nullptr;
	char* status = nullptr;
	char status1[5] = { "open" };
	int exp;
	char apply = '\0';
	char choice = '\0';
	job_title = new char[50];
	category = new char[50];
	city = new char[50];
	deadline = new char[50];
	details = new char[500];
	status = new char[6];
	ifstream fin;
	fin.open("jobs.txt");
	ofstream fout;
	fout.open("file.txt");

	while (1)
	{
		cout << "Do you want to enter another job?(Y For Yes || N For No)";
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			while (fin >> job_title)
			{
				fin >> category;
				fin >> city;
				fin >> deadline;
				fin >> exp;
				fin >> status;
				fin.ignore();
				fin.getline(details, 500);

				if (compare_array(status, status1))
				{
					cout << "job title : ";
					cout << job_title << endl;
					cout << "categorey : ";
					cout << category << endl;
					cout << " city : ";
					cout << city << endl;
					cout << "details : ";
					cout << details << endl;
					cout << "job deadline : ";
					cout << deadline << endl;
					cout << "required experience : ";
					cout << exp << endl;
					cout << "job status :";
					cout << status << endl;
				}
				cout << "whould you like to apply (Y For Yes || N For No) ";
				cin >> apply;
				if (apply == 'Y' || apply == 'y')
				{
					fout << job_title << endl;
					fout << category << endl;
					fout << city << endl;
					fout << details << endl;
					fout << exp << endl;
				}
				else if (apply == 'N' || apply == 'n')
				{
					continue;
				}
				else
				{
					cout << "Wrong choice." << endl;
				}
			}

		}
		else if (choice == 'N' || choice == 'n')
		{
			break;
		}
		else
		{
			cout << "Wrong choice." << endl;
		}

	}
	fin.close();
	fout.close();
}
void job_seekers()
{
	char*  username = { '\0' };
	char*  user1 = { '\0' };
	char*  password = { '\0' };
	username = new char[20];
	user1 = new char[20];
	password = new char[20];
	int   num = 0;
	int  num1 = 0;
	int  num2 = 0;
	int  num3 = 0;
	int  num4 = 0;
	int  num5 = 0;
	bool brk = false;
	system("CLS");

	cout << "\n\n\t\t\t\Welcome to job Seekers" << endl;
	cout << "\n\n\t\t\1.Sign in (1) \n\t\t\2.Sign Up(2) \n\t\t\3.Exit(3)" << endl;
	cout << "\n\t\t Please enter your choice:";
	cin >> num1;
	switch (num1)
	{
	case 1:
		system("cls");
		cout << "\n\n\t\Sign In ";
		SignInMenu(username);
		copyarr(user1, username);
		system("cls");
		cout << "\n\t\t\tWelcome to Your Account" << endl;
		cout << "\t\t\t\tGreetings" << endl;
		cout << "\n\t\t\ 1.Modify  User Profile (1) \n\t\t\ 2.View all available jobs (2) \n\t\t\ 3.Search job by category(3)\n\t\t\ 4.Apply for a job (4)\n\t\t\ 5.View list of applied jobs (5)\n\t\t\ 6.View list of accepted jobs(6)\n\t\t\ 7.sign out(7)" << endl;
		cout << "\n\t\t Please enter your choice:";
		cin >> num2;
		switch (num2)
		{
		case 1:
			ModifyMenu(username);
			break;
		case 2:
			List_Of_Posted_Items();
			break;
		case 3:
			search_job();
			break;
		case 4:
			Apply();
			break;
		case 5:
			view_list_of_job();
			break;
		case 7:
			menue();
			break;
		default:
			cout << "\n\t\tWrong Input" << endl;
		}
		break;
	case 2:
		cout << "\n\n\t\Sign Up \n\n";
		SignUpMenu();
		break;
	case 3:
		break;
	}
}
void employer()
{
	char*  username = { '\0' };
	char*  user1 = { '\0' };
	char*  password = { '\0' };
	username = new char[20];
	user1 = new char[20];
	password = new char[20];
	int   num = 0;
	int  num1 = 0;
	int  num2 = 0;
	int  num3 = 0;
	int  num4 = 0;
	int  num5 = 0;
	bool brk = false;
	system("CLS");

	cout << "\n\n\t\t\t\Welcome to Employer's menue'" << endl;
	cout << "\n\n\t\t\1.Sign in (1) \n\t\t\2.Sign Up(2) \n\t\t\3.Exit(3)" << endl;
	cout << "\n\t\t Please enter your choice:";
	cin >> num1;
	switch (num1)
	{
	case 1:
		system("cls");
		cout << "\n\n\t\Sign In ";
		SignInMenu(username);
		copyarr(user1, username);
		system("cls");
		cout << "\n\t\t\tWelcome to Your Account" << endl;
		cout << "\t\t\t\tGreetings" << endl;
		cout << "\n\t\t\ 1.Change password (1) \n\t\t\ 2.post job description (2) \n\t\t\ 3.View list of posted jobs(3)\n\t\t\ 4.modify jobs(4)\n\t\t\ 5.View list of applied jobs (5)\n\t\t\ 6.View list of accepted jobs(6)\n\t\t\ 7.sign out(7)" << endl;
		cout << "\n\t\t Please enter your choice:";
		cin >> num2;
		switch (num2)
		{
		case 1:
			ModifyMenu(username);
			break;
		case 2:
			Post_Item();
			break;
		case 3:
			List_Of_Posted_Items();
			break;
		case 4:
			modify_Item();
			break;
		case 5:
			view_list_of_job();
			break;
		case 6:
			cout << "no jobs found";
			break;
		case 7:
			employer();
			break;
		default:
			cout << "\n\t\tWrong Input" << endl;
		}
		break;
	case 2:
		cout << "\n\n\t\Sign Up \n\n";
		SignUpMenu_U();
		cout << "Your account has been created press 1 to sgin in ";
		int c;
		cin >> c;
		if (c == 1)
			employer();
		break;
	case 3:
		menue();
		break;
	}
}
void copyarr(char filename[], char username[])
{
	for (int i = 0; username[i] != '\0'; i++)
	{
		filename[i] = username[i];
	}
	cout << filename << endl;
}
int array_length(char* arr)
{
	int c = 0;
	for (int i = 0; arr[i] != '\0'; i++)
		c++;
	return c;
}
bool compare_array(char* arr1, char* arr2)
{
	bool flag = true;

	if (array_length(arr1) != array_length(arr2))
		flag = false;
	else
	{
		for (int i = 0; arr1[i] != '\0'; i++)
		{
			if (arr1[i] != arr2[i])
				flag = false;
		}
	}
	return flag;
}
void Post_Item()
{
	char* job_title = NULL;
	char* category = NULL;
	char* city = NULL;
	char* deadline = NULL;
	char* details = NULL;
	char status[5] = { "open" };
	int exp;
	job_title = new char[50];
	category = new char[50];
	city = new char[50];
	deadline = new char[50];
	details = new char[500];
	ofstream fout;
	fout.open("jobs.txt", ios::app);
	while (true)
	{
		cout << "Please enter job title : ";
		cin >> job_title;
		cout << "Please enter categorey: ";
		cin >> category;
		cout << "Please enter city: ";
		cin >> city;
		cin.ignore();
		cout << "Please enter details : ";
		cin.getline(details, 500);

		cout << "Please enter job deadline ";
		cin >> deadline;
		cout << "Please enter job required experience ";
		cin >> exp;
		fout << endl;
		fout << job_title << " ";
		fout << category << " ";
		fout << city << " ";
		fout << deadline << " ";
		fout << exp << " ";
		fout << status << " ";
		fout << details << " ";

		char choice = '\0';
		while (!(choice == 'Y' || choice == 'y') || (choice == 'N' || choice == 'n'))
		{
			cout << "Do you want to enter another job?(Y For Yes || N For No)";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				continue;
			}
			else if (choice == 'N' || choice == 'n')
			{
				break;
			}
			else
			{
				cout << "Wrong choice." << endl;
			}
		}
		if (choice == 'N' || choice == 'n')
		{
			break;
		}
	}
}
void modify_Item()
{
	char* job_title = NULL;
	char* category = NULL;
	char* city = NULL;
	char* deadline = NULL;
	char* details = NULL;
	char status[5] = { "open" };
	int exp;
	job_title = new char[50];
	category = new char[50];
	city = new char[50];
	deadline = new char[50];
	details = new char[500];
	char* job_title1 = NULL;;
	char* category2 = NULL;
	char* city3 = NULL;;
	char* deadline4 = nullptr;
	char* details5 = nullptr;
	char status6[5] = { "open" };
	int exp7;
	job_title = new char[50];
	category = new char[50];
	city = new char[50];
	deadline = new char[50];
	details = new char[500];
	ofstream fout;
	fout.open("temp.txt");
	while (true)
	{
		cout << "Please enter job title : ";
		cin >> job_title;
		cout << "Please enter categorey: ";
		cin >> category;
		cout << "Please enter city : ";
		cin >> city;
		cin.ignore();
		cout << "Please enter details : ";
		cin.getline(details, 500);

		cout << "Please enter job deadline ";
		cin >> deadline;
		cout << "Please enter job required experience ";
		cin >> exp;
		fout << endl;
		fout << job_title << " ";
		fout << category << " ";
		fout << city << " ";
		fout << deadline << " ";
		fout << exp << " ";
		fout << status << " ";
		fout << details << " ";

		char choice = '\0';
		while (!(choice == 'Y' || choice == 'y') || (choice == 'N' || choice == 'n'))
		{
			cout << "Do you want to enter another job?(Y For Yes || N For No)";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				continue;
			}
			else if (choice == 'N' || choice == 'n')
			{
				break;
			}
			else
			{
				cout << "Wrong choice." << endl;
			}
		}
		if (choice == 'N' || choice == 'n')
		{
			break;
		}
	}

	ifstream fin;
	fin.open("temp.txt");
	ofstream fout1;
	fout1.open("jobs.txt", ios::app);
	while (fin)
	{
		fin >> job_title1;
		fin >> category2;
		fin >> city3;
		fin >> deadline4;
		fin >> exp7;
		fin >> status6;
		fin.ignore();
		fin.getline(details5, 500);
		if (compare_array(job_title1, job_title))
		{

			fout1 << job_title << " ";
			fout1 << category << " ";
			fout1 << city << " ";
			fout1 << deadline << " ";
			fout1 << exp << " ";
			fout1 << status << " ";
			fout1 << details << " ";
		}
	}
}
void List_Of_Posted_Items()
{
	system("cls");
	char* job_title = nullptr;
	char* category = nullptr;
	char* city = nullptr;
	char* deadline = nullptr;
	char* details = nullptr;
	char status[5] = { "open" };
	int exp;
	job_title = new char[50];
	category = new char[50];
	city = new char[50];
	deadline = new char[50];
	details = new char[500];
	ifstream fin;
	fin.open("jobs.txt");
	while (fin >> job_title)
	{
		fin >> category;
		fin >> city;
		fin >> deadline;
		fin >> exp;
		fin >> status;
		fin.ignore();
		fin.getline(details, 500);

		cout << "job title            : ";
		cout << job_title << endl;
		cout << "categorey            : ";
		cout << category << endl;
		cout << " city                : ";
		cout << city << endl;
		cout << "details              : ";
		cout << details << endl;
		cout << "job deadline         : ";
		cout << deadline << endl;
		cout << "required experience  : ";
		cout << exp << endl;
		cout << "job status  :";
		cout << status << endl;
	}
}
void SignUpMenu()
{
	system("cls");
	char username[20] = { '\0' };
	char password[20] = { '\0' };
	char fname[20] = { '\0' };
	char lname[20] = { '\0' };
	char cellphone[20] = { '\0' };
	char address[50] = { '\0' };
	char name[20] = { '\0' };
	char education[20] = { '\0' };
	int e = 0;
	cout << "\t\t\Please enter the folowing details to Sign Up";
	cout << "\n\n\t\t\t\ First Name : ";
	cin >> fname;
	cout << "\n\t\t\t\ Last Name : ";
	cin >> lname;
	while (1)
	{
		char filename[20] = { '\0' };
		cout << "\n\t\t\t\ Username : ";
		cin >> username;
		usertotxt(username, filename);
		ifstream fin(filename);
		if (!fin)
		{
			ofstream fout(filename);
			cout << "\n\t\t\t\ Cellphone          : ";
			cin >> cellphone;
			cout << "\n\t\t\t\ Address            : ";
			cin.ignore(49, '\n');
			cin.getline(address, 49);
			cout << "\n\t\t\t\ Password           : ";
			cin >> password;
			cout << "\n\t\t\t\ education          : ";
			cin >> education;
			cout << "\n\t\t\t\ Experience in years: ";
			cin >> e;
			fout << password << endl;
			fout << username << endl;
			fout << fname << endl;
			fout << lname << endl;
			fout << cellphone << endl;
			fout << address << endl;
			fout << education << endl;
			fout << e << endl;
			cout << endl;
			fout.close();
			break;
		}
		fin.close();
		cout << "\t\t Username already taken. Please enter again: ";
	}
}
void SignUpMenu_U()
{
	system("cls");
	char username[20] = { '\0' };
	char password[20] = { '\0' };
	char fname[20] = { '\0' };
	char lname[20] = { '\0' };
	char cellphone[20] = { '\0' };
	char address[50] = { '\0' };
	char name[20] = { '\0' };
	char education[20] = { '\0' };
	int e = 0;
	cout << "\t\t\Please enter the folowing details to Sign Up";
	cout << "\n\t\t\t\ First Name : ";
	cin >> fname;
	cout << "\n\t\t\t\ Last Name : ";
	cin >> lname;
	while (1)
	{
		char filename[20] = { '\0' };
		cout << "\n\t\t\t\ Username : ";
		cin >> username;
		usertotxt(username, filename);
		ifstream fin(filename);
		if (!fin)
		{
			ofstream fout(filename);

			char password1[20] = { '\0' };
			cout << "\n\t\t\t\ Password : ";
			cin >> password;
			while (PassCheck(password, password1) == false)
			{
				cout << "\n\t\t\t\ Enter Password again : ";
				cin >> password1;
			}

			fout << password << endl;
			fout << username << endl;
			fout << fname << endl;
			fout << lname << endl;
			cout << endl;
			fout.close();
			break;
		}
		fin.close();
		cout << "\t\t Username already taken. Please enter again: ";
	}
}
void SignInMenu(char* username)
{
	bool pass = false;
	bool check = false;
	char test[20] = { '\0' };
	bool flag = false;

	char*  password = { '\0' };
	password = new char[20];

	char choice = { '\0' };
	while (1)
	{
		cout << "\n\n\t\t\ Username : ";
		cin >> username;
		cout << "\n\t\t\ Password : ";
		cin >> password;
		char filename[20] = { '\0' };
		usertotxt(username, filename);
		ifstream fin(filename);
		while (1)
		{
			if (!fin)
			{
				cout << "\n\t There is no such username as \"" << username << "\"." << endl;
				cout << "\t Would you like to create an account? " << endl << endl;
				cout << "\t Press (Y/y) for Yes & (N/n) to try again: ";
				cin >> choice;
				if (choice == 'n' || choice == 'N')
				{
					system("cls");
					cout << "\n\n\t\Sign In \n";
					break;
				}
				while (1)
				{
					if (choice == 'y' || choice == 'Y')
					{
						SignUpMenu();
						flag = true;
						break;
					}
					else
					{
						cout << "\t Invalid input. Enter Again" << endl << endl;
						break;
					}
				}
				if (flag == true)
				{
					char input = '\0';
					cout << "\t You have successfully created your account." << endl;
					cout << "\n\n\t\ Press any key to Sign In ";
					cin >> input;
					system("cls");
					break;
				}
			}
			else
			{
				fin >> test;
				if (PassCheck(password, test) == false)
				{
					cout << "\tWrong Password. Please Enter your credentials Again" << endl;
					break;
				}
				else
				{
					check = true;
					break;
				}
			}

		}
		if (check == true)
		{
			break;
		}
		fin.close();
	}
}
void SignInMenu_U(char *)
{
}
bool PassCheck(char* password, char* test)
{
	bool flag = false;
	int size1 = size_arr(password);
	int size2 = size_arr(test);
	if (size1 != size2)
	{
		flag = false;
	}
	else
	{
		for (int i = 0; password[i] != '\0'; i++)
		{
			if (password[i] == test[i])
				flag = true;
			else
				flag = false;
		}
	}

	if (flag == true)
		return true;
	else
		return false;
}
void copyfile(char* file1, char* file2)
{
	char copy[50] = { '\0' };
	ifstream fin(file1);
	ofstream fout(file2);
	while (fin)
	{
		fin.getline(copy, 49);
		fout << copy << endl;
	}
	fin.close();
	fout.close();
}
void UpdatePass(char* password, char* username)
{
	char copy[50] = { '\0' };
	ifstream fin(username);
	ofstream fout("temp.txt");
	fout << password;
	fin >> copy;
	while (fin)
	{
		fin.getline(copy, 49);
		fout << copy << endl;
	}
	char file2[] = { "temp.txt" };
	fin.close();
	fout.close();
	copyfile(file2, username);
}
void PassUpdateMenu(char* filename)
{
	ifstream fin(filename);
	char test[20] = { '\0' };
	while (1)
	{
		char password[20] = { '\0' };
		cout << "\n\n\t\t\t\ Current Password : ";
		cin >> password;
		fin >> test;
		if (PassCheck(password, test) == true)
		{
			char password1[20] = { '\0' };
			cout << "\n\n\t\t\t\ Enter a new Password : ";
			cin >> password;
			while (PassCheck(password, password1) == false)
			{
				cout << "\n\n\t\t\t\ Enter Password again : ";
				cin >> password1;
			}
			UpdatePass(password, filename);
			cout << "Your password was updated succesfully" << endl;
			cout << "Press (1) to return: ";
			int n = 0;
			cin >> n;
			while (n != 1)
			{
				cout << "Enter again : ";
				cin >> n;
			}
			system("cls");
			break;
		}
		else
		{
			cout << "\n\n\t\t\Incorrect. Enter Password again ";
		}
	}
	fin.close();
}
void usertotxt(char* username, char* filename)
{
	int loc = 0;
	for (int i = 0; username[i] != '\0'; i++)
	{
		filename[i] = username[i];
		loc++;
	}
	filename[loc] = '.';
	filename[loc + 1] = 't';
	filename[loc + 2] = 'x';
	filename[loc + 3] = 't';
}
int size_arr(char* arr)
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
void ModifyMenu(char username[])
{
	bool brk = false;
	int num3 = 0;
	system("cls");
	cout << "\n\t\t\Modify  User Profile";

	while (1)
	{
		cout << "\n\t\t\Enter the username you want to modify: ";
		cin >> username;


		char filename[20] = { '\0' };
		usertotxt(username, filename);
		ifstream fin(filename);
		char test[20] = { '\0' };
		if (!fin)
		{
			cout << "This username does not exist.";
		}
		else
		{
			while (1)
			{
				cout << "\n\n\t\t\t\Welcome to \"" << username << "\"'s Profile" << endl;
				cout << "\n\n\t\t\1.Change Password (1)\n\t\t\2.Go Back (2)" << endl;
				cout << "\n\t\t Please enter your choice:";
				cin >> num3;
				if (num3 == 1)
				{
					PassUpdateMenu(filename);
				}
				else if (num3 == 2)
				{
					brk = true;
					break;
				}
				else
				{
					cout << "\n\t\tInvalid input try again" << endl;
				}
			}
			if (brk == true)
			{
				break;
			}
		}
		fin.close();
	}
}
void ModifyMenu_U(char username[])
{
	bool brk = false;
	int num3 = 0;
	system("cls");
	cout << "\n\t\t\Modify User Profile";

	while (1)
	{
		char filename[20] = { '\0' };
		usertotxt(username, filename);
		ifstream fin(filename);
		char test[20] = { '\0' };
		if (!fin)
		{
			cout << "\t\tThis username does not exist.";
		}
		else
		{
			while (1)
			{
				cout << "\n\n\t\t\t\Welcome to your Profile" << endl;
				cout << "\n\n\t\t\1.Change Password (1)\n\t\t\2.Go Back (2)" << endl;
				cout << "\n\t\t Please enter your choice:";
				cin >> num3;
				if (num3 == 1)
				{
					PassUpdateMenu(filename);
				}
				else if (num3 == 2)
				{
					brk = true;
					break;
				}
				else
				{
					cout << "\n\t\tInvalid input try again" << endl;
				}
			}
			if (brk == true)
			{
				break;
			}
		}
		fin.close();
	}
}
void search_job()
{
	char* job_title = nullptr;
	char* deadline = nullptr;
	char* category = nullptr;
	char* city = nullptr;
	char* details = nullptr;
	int exp = 0, flag = 0;
	const int SIZE = 50;
	deadline = new char[SIZE];
	job_title = new char[SIZE];
	category = new char[SIZE];
	city = new char[SIZE];
	details = new char[SIZE];
	char* ctg = nullptr;
	ctg = new char[SIZE];
	category = new char[SIZE];
	cout << "Please enter catogry: ";
	cin.ignore();
	cin.getline(ctg, SIZE);
	ifstream fin("jobs.txt");

	while (fin >> job_title)
	{
		fin >> category;
		if (compare_array(ctg, category))
		{
			fin >> city;
			fin >> deadline;
			fin >> exp;
			fin.ignore();
			fin.getline(details, 500, '\n');
			cout << "job title : ";
			cout << job_title << endl;
			cout << "categorey : ";
			cout << category << endl;
			cout << " city : ";
			cout << city << endl;
			cout << "details : ";
			cout << details << endl;
			cout << "required experience : ";
			cout << exp << endl;
			flag = 0;
			break;
		}
		fin >> city;
		fin >> deadline;
		fin >> exp;
		fin.ignore();
		fin.getline(details, 500, '\n');
		flag = 1;
	}
	if (flag == 1)
	{
		cout << "There is no such category available";
	}
	fin.close();
}
void view_list_of_job()
{
	system("cls");
	char* job_title = nullptr;
	char* category = nullptr;
	char* city = nullptr;
	char* details = nullptr;
	int exp = 0;
	job_title = new char[50];
	category = new char[50];
	city = new char[50];
	details = new char[500];
	ifstream fin;
	fin.open("file.txt");

	cout << "Total jobs applied" << endl;
	while (fin >> job_title)
	{
		fin >> category;
		fin >> city;
		fin.ignore();
		fin.getline(details, 500);
		fin >> exp;
		cout << "job title : ";
		cout << job_title << endl;
		cout << "categorey : ";
		cout << category << endl;
		cout << " city : ";
		cout << city << endl;
		cout << "details : ";
		cout << details << endl;
		cout << "required experience : ";
		cout << exp << endl;
	}
	fin.close();
}