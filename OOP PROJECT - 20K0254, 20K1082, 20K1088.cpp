#include <iostream>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<iomanip>
#include <cstdlib>
#include <string>

using namespace std;

class Person{
	protected:
		string fname;
		string lname;
		int age;
	public:
		// CONSTRUCTORS
		
		Person()
		{
			fname = '\0';
			lname = '\0';
			age = 0;
		}
		
		Person(string fname, string lname, int age)
		{
			this -> fname = fname;
			this -> lname = lname;
			this -> age = age ;
		}
		
		// SETTERS
		
		void setFName(string name)
		{
			this -> fname = fname;
		}
		
		void setLName(string name)
		{
			this -> lname = lname;
		}
		
		void setAge(int age)
		{
			this -> age = age ;
		}
		
		// Getters 
		
		string getFName()
		{
			return fname;
		}
		
		string getLName()
		{
			return lname;
		}
		
		int getAge()
		{
			return age ;
		}
		
};


class Player:public Person{
	protected:
		int numMatches;
		int numManOfMatch;
		
	public:
		
		// Constructors
		
		Player()
		{
			numMatches = 0;
			numManOfMatch = 0;
		}
		
		Player(string fname, string lname, int age, int numMatches, int numManOfMatch):Person(fname, lname, age)
		{
			this -> numMatches = numMatches;
			this -> numManOfMatch = numManOfMatch;
		}
		
		Player(string fname, string lname, int age):Person(fname, lname, age)
		{
			
		}
		
		// Setters
		
		void setFName(string name)
		{
			Person::setFName(name);
		}
		
		void setLName(string name)
		{
			Person::setLName(name);
		}
		
		void setAge(int age)
		{
			Person::setAge(age);
		}
		
		void setNumMatches(int numMatches)
		{
			this -> numMatches = numMatches;
		}
		
		void setNumMOM(int numManOfMatch)
		{
			this -> numManOfMatch = numManOfMatch;
		}
		
		// Getters 
		
		string getFName()
		{
			return Person::getFName();
		}
		
		string getLName()
		{
			return Person::getLName();
		}
		
		int getAge()
		{
			return Person::getAge();
		}
		
		int getNumMatches()
		{
			return numMatches;
		}
	
		int getNumMOM()
		{
			return numManOfMatch;
		}
		
		void Input()
		{
			cout << endl << "Enter Fist Name: ";
			cin >> fname;
			cout << "Enter the Last Name: ";
			cin >> lname;
			cout << "Enter the age: ";
			cin >> age;
			cout << "Enter the number of matches played: ";
			cin >> numMatches;
			cout << "Enter the number of how many times he become the Man of the Match:  ";
			cin >> numManOfMatch;
		}
	
};


class Bowler:public Player{
	protected:
		int wickets;
		double oversBowled;
		int runsConceded;
		float economy;
		const int bowlerID;
		static int numID1; // This variable will get incremented every time and will be stored in the constant variable "bowlerID" 
	public:
		Bowler():bowlerID(numID1++)
		{
			wickets = 0;
			oversBowled = 0;
		}
		
		Bowler(string fname, string lname, int age, int numMatches, int numManOfMatch, int wickets, double overBowled, int runsConceded, float economy):Player(fname, lname, age, numMatches, numManOfMatch), bowlerID(numID1++)
		{
			this -> wickets = wickets;
			this -> oversBowled = overBowled;
			this -> runsConceded = runsConceded;
			this -> economy = economy;
		}
		
		Bowler(string fname, string lname, int age):Player(fname, lname, age), bowlerID(numID1++)
		{
	
		}
		
		// Setters
		
		void setFName(string name)
		{
			Player::setFName(name);
		}
		
		void setLName(string name)
		{
			Player::setLName(name);
		}
		
		void setAge(int age)
		{
			Player::setAge(age);
		}
		
		void setNumMatches(int numMatches)
		{
			Player::setNumMatches(numMatches);
		}
		
		void setNumMOM(int numManOfMatch)
		{
			Player::setNumMOM(numManOfMatch);
		}
		
		void setWickets(int wickets)
		{
			this -> wickets = wickets;
		}
		
		void setOversBowled(double oversBowled)
		{
			this -> oversBowled = oversBowled;
		}
		
		void setRunsConceded(int runsConceded)
		{
			this -> runsConceded = runsConceded;
		}
		
		void setEconomy(float economy)
		{
			this -> economy = economy;
		}
		
		// Getters 
		
		string getFName()
		{
			return Player::getFName();
		}
		
		string getLName()
		{
			return Player::getLName();
		}
				
		int getAge()
		{
			return Player::getAge();
		}
		
		int getNumMatches()
		{
			return Player::getNumMatches();
		}
		
		int getNumMOM()
		{
			return Player::getNumMOM();
		}
		
		int getWickets()
		{
			return wickets;
		}
		
		double getOversBowled()
		{
			return oversBowled;
		}
		
		int getRunsConceded()
		{
			return runsConceded;
		}
		
		float getEconomy()
		{
			return economy;
		}
	
		// OTHER FUNCTIONS
		
		void Input1()
		{
			Player::Input();
			cout << endl << "Enter the number of wickets: ";
			cin >> wickets;
			cout << "Enter the number of overs bowled: ";
			cin >> oversBowled;
			cout << "Enter the Runs Conceded: ";
			cin >> runsConceded;
			
			calEconomy();
		}
		
		void calEconomy()
		{
			float eco;
			
			eco = float(getRunsConceded())/float(getOversBowled());
			
			setEconomy(eco);	
		}
		
		friend class Admin;
};

int Bowler::numID1 = 4891;

class Batsman:public Player{
	protected:
		float avg;
		float srate;
		int numBallsPlayed;
		int totalRuns;
		int numInnings;
		const int batsmanID;
		static int numID2; // This variable will get incremented every time and will be stored in the constant variable "batsmanID" 
	public:
		Batsman():batsmanID(numID2++)
		{
			avg = 0.0;
			srate = 0.0;
			numBallsPlayed = 0;
			totalRuns = 0;
		}
		
		Batsman(string fname, string lname, int age, int numMatches, double avg, double srate, int numBallsPlayed, int numManOfMatch, int totalRuns, int numInnings):Player(fname, lname, age, numMatches, numManOfMatch), batsmanID(numID2++)
		{
			this -> avg = avg;
			this -> srate = srate;
			this -> numBallsPlayed = numBallsPlayed;
			this -> totalRuns = totalRuns;
			this -> numInnings = numInnings;
		}
		
		Batsman(string fname, string lname, int age):Player(fname, lname, age), batsmanID(numID2++)
		{
			
		}
		
		// Setters
		
		void setFName(string name)
		{
			Player::setFName(name);
		}
		
		void setLName(string name)
		{
			Player::setLName(name);
		}
		
		void setAge(int age)
		{
			Player::setAge(age);
		}
		
		void setNumMatches(int numMatches)
		{
			Player::setNumMatches(numMatches);
		}
		
		void setNumMOM(int numManOfMatch)
		{
			Player::setNumMOM(numManOfMatch);
		}
	
		void setAVG(double avg)
		{
			this -> avg = avg;
		}
		
		void setSRate(double srate)
		{
			this -> srate = srate;
		}
		
		void setNumBallsPlayed(int numBallsPlayed)
		{
			this -> numBallsPlayed = numBallsPlayed;
		}
		
		void setTotRuns(int totalRuns)
		{
			this -> totalRuns = totalRuns;
		}
			
		void setNumInnings(int numInnings)
		{
			this -> numInnings = numInnings;
		}
		
		// Getters 
		
		string getFName()
		{
			return Player::getFName();
		}
		
		string getLName()
		{
			return Player::getLName();
		}
		
		int getAge()
		{
			Player::getAge();
		}
		
		int getNumMatches()
		{
			Player::getNumMatches();
		}
		
		int getNumMOM()
		{
			Player::getNumMOM();
		}
		
		float getAVG()
		{
			return avg;
		}
		
		float getSRate()
		{
			return srate;
		}
		
		int getNumBallsPlayed()
		{
			return numBallsPlayed;
		}
		
		int getTotRuns()
		{
			return totalRuns;
		}
		
		int getNumInnings()
		{
			return numInnings;
		}
		
		void Input2()
		{
			Player::Input();
			
			cout << endl << "Enter the number of balls played: ";
			cin >> numBallsPlayed;
			cout << endl << "Enter the total runs: ";
			cin >> totalRuns;
			cout << endl << "Enter the number of innings played: ";
			cin >> numInnings;
			
			CalSRate();
			CalAvg();
		}
		
		void CalSRate()
		{
			float rate;
			
			rate = float(getTotRuns())/float(getNumBallsPlayed());
			rate *= 100.0;
			
			setSRate(rate);
		}
		
		void CalAvg()
		{
			float avg;
			
			avg = float(getTotRuns())/float(getNumInnings());
			
			setAVG(avg);
		}
		
		friend class Admin;
};

int Batsman::numID2 = 2193;

class WicketKeeper:public Batsman{
	protected:
		int numCatches;
		int numStumps;
		const int wicketID;
		static int numID3; // This variable will get incremented every time and will be stored in the constant variable "wicketID" 
	public:
		WicketKeeper():wicketID(numID3++)
		{
			numCatches = 0;
			numStumps = 0;
		}
		
		WicketKeeper(string fname, string lname, int age, string role, int numMatches, int numInnings, double avg, double srate, int numBallsPlayed, int numManOfMatch, int totalRuns, int numCatches, int numStumps):Batsman(fname, lname, age, numMatches, avg, srate, numBallsPlayed, numManOfMatch, totalRuns, numInnings), wicketID(numID3++)
		{
			this -> numCatches = numCatches;
			this -> numStumps = numStumps;
		}
		
		WicketKeeper(string fname, string lname, int age):Batsman(fname, lname, age), wicketID(numID3++)
		{
			
		}
		
		// Setters
		
		void setFName(string name)
		{
			Batsman::setFName(name);
		}
		
		void setLName(string name)
		{
			Batsman::setLName(name);
		}
		
		void setAge(int age)
		{
			Batsman::setAge(age);
		}
		
		void setNumMatches(int numMatches)
		{
			Batsman::setNumMatches(numMatches);
		}
		
		void setNumInnings(int numInnings)
		{
			Batsman::setNumInnings(numInnings);
		}
		
		void setNumMOM(int numManOfMatch)
		{
			Batsman::setNumMOM(numManOfMatch);
		}
		
		void setnumCatches(int numCatches)
		{
			this -> numCatches = numCatches;
			
		}
		
		void setnumStumps(int numStumps)
		{
			this -> numStumps = numStumps;
		}
		
		
		// Getters 
		
		string getFName()
		{
			return Player::getFName();
		}
		
		string getLName()
		{
			return Player::getLName();
		}
		
		int getAge()
		{
			return Batsman::getAge();
		}
		
		int getNumMatches()
		{
			return Batsman::getNumMatches();
		}
		
		int getNumInnings()
		{
			return Batsman::getNumInnings();
		}
		
		int getNumMOM()
		{
			return Batsman::getNumMOM();
		}
		
		int getNumCatches()
		{
			return numCatches;
		}
		
		int getNumStumps()
		{
			return numStumps;
		}
		
		void Input3()
		{
			Batsman::Input2();
			
			cout << endl << "Enter the number of catches: ";
			cin >> numCatches;
			cout << endl << "Enter the number of stumps: ";
			cin >> numStumps;
		}
		
		friend class Admin;
};

int WicketKeeper::numID3 = 1438;

class Admin:public Person{
	protected:
		const int adminID;
		static int numID;     // This variable will get incremented every time and will be stored in the constant variable "playerID" 
		
	public:
		
		// Constructors
		
		Admin():adminID(numID+=8)
		{
			
		}
		
		Admin(string fname, string lname, int age):adminID(numID+=8)
		{
			
		}
		
		// Setters
		
		void setFName(string name)
		{
			Person::setFName(name);
		}
		
		void setLName(string name)
		{
			Person::setLName(name);
		}
		
		void setAge(int age)
		{
			Person::setAge(age);
		}
		
		// Getters 
		
		string getFName()
		{
			return Person::getFName();
		}
		
		string getLName()
		{
			return Person::getLName();
		}
		
		int getAge()
		{
			return Person::getAge();
		}
		
		// OTHER FUNCTIONS
		
		// FUNCTIONS FOR ADMIN
		
		void ViewAdmin()		// FUNCTION TO VIEW THE ADMIN INFORMATION
		{
			system("cls");
			ifstream f;
			f.open("Admin Data.txt", ios::in);
			Admin A;
			int a;
				
			cout << "\t\t  =======================================\n";
			cout << "\t\t\tName\t\tID\tAge\n";
			cout << "\t\t  =======================================\n";
				
			while(1)
			{
				if(f.eof())
				{
					break;
				}
				
			   	f >> A.fname >> A.lname >> a >> A.age;
			   	cout<<"\t\t\t"<< A.getFName() <<" "<< A.getLName() <<"\t"<< a <<"\t"<< A.getAge();
			   	cout<<endl;
			}
			f.close();
			cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
			getchar();
		}
			

		void UpdateAdmin()		// FUNCTION TO UPDATE THE ADMIN INFORMATION
		{
			system("cls");
	    	ifstream f;
		    f.open("Admin Data.txt", ios::in);
		    	
			Admin A;
			int a, count = 0, i = 0, j = 0;
			
			int ID;
	    	cout << "Enter your ID update the data: " << endl;
	    	cin >> ID;
	    	
			while(1)
			{
			    f >> A.fname >> A.lname >> a >> A.age;
					
				if(a == ID)
				{
					count ++;	
				}
					
				if(f.eof())
				{
					break;
				}
			}
				
			if (count == 0)
			{
				cout << "\n\tADMIN WITH THIS ID DOES'NT EXIST.\n\n";
				f.clear();
				f.seekg(0, ios::beg);
				getchar();
				return; 
			}
			
			ofstream t;    //new file object
			t.open("temp.temp", ios::app);
				
			if (!t)
			{
				cout << "\n\n\t\t\tTEMP FILE CANNOT BE CREATED!!";
				getchar();
				return; 
			} 
				
			f.clear();
			f.seekg(0, ios::beg);
				
			do {
				f >> A.fname >> A.lname >> a >> A.age;
				
				if (a != ID)
				{
					if (j != 0)
					{
						t << "\n";
					}
					
			       	t << A.getFName() <<" "<< A.getLName() <<"\t"<< a <<"\t"<< A.getAge(); 
						
					j++;
						      	
			       	if(f.eof())
					{
						break;
					}
				}
				
				else
				{
					if (j != 0)
					{
						t << "\n";
					}
					fflush(stdin);
					
					string fn, ln;
					int age;
							
					cout << "Edit First Name: ";
					cin >> fn;
							
					fflush(stdin);
										
					cout << "Edit Last Name: ";
					cin >> ln;
							
					fflush(stdin);
										
					cout << "Edit Age: ";
					cin >> age;
							
					A.setFName(fn);
					A.setLName(ln);
					A.setAge(age);
					
					t << A.getFName() <<" "<< A.getLName() <<"\t"<< a <<"\t"<< A.getAge();
				       	
					}
					
					j++;
					
					if(f.eof())
					{
						break;
					}
					
				}while(1); //end of do while loop
				
				f.close();
				t.close();
				remove("Admin Data.txt");
				rename("temp.temp","Admin Data.txt");
				
				cout << "\n\n\n\t\t Record Updated! PRESS ANY KEY TO RETURN ";
				getchar();	
		}

		
		void UpdatePass()		// FUNCTION TO UPDATE THE LOGIN PASSWORD OF ADMIN 
		{
			system("cls");
	    	ifstream f;
		    f.open("Admin.txt", ios::in);
		    int count = 0;
		    
			Admin A;
			
			int index = 0, index1 = 0, index2 = 0;
			char pass[15], pass1[15], pass2[15], ch;			
			string str, str1;
	    	cout << "Enter your current password to update it: " << endl;
	    	while((ch = getch()) != 13)
			{
	       		if(index < 0)
	           		index = 0;
	       		// 8 is ASCII value of BACKSPACE character
	       		if(ch == 8)
				{
	           		putch('\b');
			        putch('\0');
			        putch('\b');
			        index--;
			        continue;
			    }
			    pass[index++] = ch;
			    putch('*');
		    }
   			pass[index] = '\0';
	    	
			f >> str;
					
			if(str == pass)
			{
				count ++;	
			}
					
			if (count == 0)
			{
				cout << "\nYOU ENTERED WRONG PASSWORD. TRY AGAIN LATER. PRESS ANY KEY TO RETURN.\n\n";
				f.clear();
				f.seekg(0, ios::beg);
				f.close();
				getchar();
				return; 
			}
			
			ofstream t;    //new file object
			t.open("temp.temp", ios::app);
				
			if (!t)
			{
				cout << "\n\n\t\t\tTEMP FILE CANNOT BE CREATED!!";
				getchar();
				return; 
			} 
				
			f.clear();
			f.seekg(0, ios::beg);
								
			cout << endl << "Enter the new password: ";
			while((ch = getch()) != 13)
			{
	       		if(index1 < 0)
	           		index1 = 0;
	       		// 8 is ASCII value of BACKSPACE character
	       		if(ch == 8)
				{
	           		putch('\b');
			        putch('\0');
			        putch('\b');
			        index1--;
			        continue;
			    }
			    pass1[index1++] = ch;
			    putch('*');
		    }
   			pass1[index1] = '\0';		
			
							
			cout << endl << "Enter the new password once again: ";
			while((ch = getch()) != 13)
			{
	       		if(index2 < 0)
	           		index2 = 0;
	       		// 8 is ASCII value of BACKSPACE character
	       		if(ch == 8)
				{
	           		putch('\b');
			        putch('\0');
			        putch('\b');
			        index2--;
			        continue;
			    }
			    pass2[index2++] = ch;
			    putch('*');
		    }
   			pass2[index2] = '\0';	
			
			str1.operator=(pass2);
			
			if(pass1 == str1)
			{
				t << pass2;
			}				
			
			else
			{
				cout << "\nPASSWORDS DON'T MATCH WITH EACH OTHER. TRY AGAIN LATER. PRESS ANY KEY TO RETURN.\n\n";
				f.close();
				t.close();
				remove("temp.temp");
				getchar();
				return; 
			}
			
			f.close();
			t.close();
			remove("Admin.txt");
			rename("temp.temp","Admin.txt");
			
			cout << "\n\n\n\t\t Password Updated! PRESS ANY KEY TO RETURN ";
			getchar();		
			
		}
		
		
		void AddPlayer(int choice)		// FUNCTION TO ADD A PLAYER, WILL RECIEVE A CHOICE FROM "PROMPT" FUNCTION EITHER BATSMAN, BOWLER OR WICKETKEEPER
		{
			system("cls");
			if(choice == 1)
			{  
				fstream f;
				int a, count = 0;
				
				f.open("Batsman Data.txt", ios::in);
				if(!f)
				{
			
					f.close();
					f.open("Batsman Data.txt", ios::app);
					f.close();
					f.open("Batsman Data.txt", ios::in);
				}
				
				while(1)
			    {
			    	if(f.eof())
					{
						break;
					}
				
			    	Batsman B;
				    if(f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >> B.avg >> B.srate)
				    {
				    	count++;
					}
				}
				
				f.close();
				
				if(count != 0)
				{
					Batsman B;
				}
				
				Batsman B;
				B.Input2();
				
				f.open("Batsman Data.txt", ios::app);
				
				if(count != 0)
				{
					f << endl;
				}
				
				f << B.getFName();
				f << " " << B.getLName();
				f << "\t" << B.batsmanID;
				f << "\t" << B.getAge();
				f << "\t" << B.getNumMatches();
				f << "\t" << B.getNumMOM();
				f << "\t" << B.getNumInnings();
				f << "\t" << B.getNumBallsPlayed();
				f << "\t" << B.getTotRuns();
				f << "\t" << setprecision(4) << B.getAVG();
				f << "\t" << setprecision(4) << B.getSRate();
		
				f.close();
				
				cout << "\n\n\n\t\t Record Added! PRESS ANY KEY TO RETURN ";
				getchar();
			}
			
			else if(choice == 2)
			{				
				fstream f;
				f.open("Bowlers Data.txt", ios::in);
				int a, count = 0;
				
				if(!f)
				{
					f.close();
					f.open("Bowlers Data.txt", ios::app);
					f.close();
					f.open("Bowlers Data.txt", ios::in);
				}
				
				while(1)
			    {
			    	if(f.eof())
					{
						break;
					}
					
			    	Bowler B;
				    if(f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.oversBowled >> B.runsConceded >> B.wickets >> B.economy)
				    {
				    	count++;
					}
				}
				
				f.close();
				
				if(count != 0)
				{
					Bowler B;
				}
				
				Bowler B;
				B.Input1();
				
				f.open("Bowlers Data.txt", ios::app);
				
				if(count != 0)
				{
					f << endl;
				}
				
				f << B.getFName();
				f << " " << B.getLName();
				f << "\t" << B.bowlerID;
				f << "\t" << B.getAge();
				f << "\t" << B.getNumMatches();
				f << "\t" << B.getNumMOM();
				f << "\t" << B.getOversBowled();
				f << "\t" << B.getRunsConceded();
				f << "\t" << B.getWickets();
				f << "\t" << setprecision(4) << B.getEconomy();
				
				f.close();
				
				cout << "\n\n\n\t\t Record Added! PRESS ANY KEY TO RETURN ";
				getchar();
			}
			
			else if(choice == 3)
			{
				fstream f;
				int a, count = 0;
				
				f.open("WicketKeeper Data.txt", ios::in);
				if(!f)
				{
					f.close();
					f.open("WicketKeeper Data.txt", ios::app);
					f.close();
						f.open("WicketKeeper Data.txt", ios::in);
				}
				
				while(1)
			    {
			    	if(f.eof())
					{
						break;
					}
					
			    	WicketKeeper W;
				    if(f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps)
					{
						count++;
					}				    
				    
				}
				
				f.close();
				
				if(count != 0)
				{
					WicketKeeper W;
				}
				
				WicketKeeper W;				
				W.Input3();
				
				f.open("WicketKeeper Data.txt", ios::app);
				
				if(count != 0)
				{
					f << endl;
				}
				
				f << W.getFName();
				f << " " << W.getLName();
				f << "\t" << W.wicketID;
				f << "\t" << W.getAge();
				f << "\t" << W.getNumMatches();
				f << "\t" << W.getNumMOM();
				f << "\t" << W.getNumCatches();
				f << "\t" << W.getNumStumps();
								
				f.close();
				
				cout << "\n\n\n\t\t Record Added! PRESS ANY KEY TO RETURN ";
				getchar();
			}
		}
	
		
	    void UpdateRecord(int choice)	// FUNCTION TO UPDATE RECORD OF A PLAYER, WILL RECIEVE A CHOICE FROM "PROMPT" FUNCTION EITHER BATSMAN, BOWLER OR WICKETKEEPER
	    {
	    	system("cls");
	    	int ID;
	    	cout << "Enter the player ID for whom you want to update the data: " << endl;
	    	cin >> ID;
	    	
	    	if(choice == 1)
	    	{
	    		ifstream f;
		    	f.open("Batsman Data.txt", ios::in);
		    	
				Batsman B;
				int a, count = 0, i = 0, j = 0;
			
			    while(1)
			    {
				    f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >> B.avg >> B.srate;
					
					if(a == ID)
					{
						count ++;	
					}
					
					if(f.eof())
					{
						break;
					}
				}
				
				if (count == 0)
				{
					cout << "\n\tTHE PLAYER WITH THIS ID DOES'NT EXIST.\n\n";
					f.clear();
					f.seekg(0, ios::beg);
					getchar();
					return; 
				}
			
				ofstream t;    //new file object
				t.open("temp.temp", ios::app);
				
				if (!t)
				{
					cout << "\n\n\t\t\tTEMP FILE CANNOT BE CREATED!!";
					getchar();
					return; 
				} 
				
				f.clear();
				f.seekg(0, ios::beg);
				
				do {
					f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >>B.avg >> B.srate;
				
					if (a != ID)
					{
				       	t << B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
						t << B.getNumInnings() <<"\t"<< B.getNumBallsPlayed() <<"\t"<< B.getTotRuns() <<"\t"<< setprecision(4) << B.getAVG() <<"\t"<< B.getSRate();
				       	
				       	if(f.eof())
						{
							break;
						}
					}
				
					else
					{
						if (j != 0)
						{
							t << "\n";
						}
						fflush(stdin);
						
						int r, b, m;
						
						cout << "Enter the new match's runs to be added in the previous record:"<<endl;
						cin >> r;
						B.totalRuns += r;
						fflush(stdin);
						
						B.numMatches++;
						
						cout<<"Enter number of balls played in this match: " << endl;
						cin >> b;
						B.numBallsPlayed += b;
						if(b != 0)
						{
							B.numInnings++;
						}
						
						cout<<"Enter how many awards the player received after this match: " << endl;
						cin >> m;
						
						B.numManOfMatch += m;
						
						B.CalAvg();
						B.CalSRate();
						
						t << B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
						t << B.getNumInnings() <<"\t"<< B.getNumBallsPlayed() <<"\t"<< B.getTotRuns() <<"\t"<< setprecision(4) << B.getAVG() <<"\t"<< B.getSRate();
				       	
					}
					
					j++;
					
					if(f.eof())
					{
						break;
					}
					
					}while(1); //end of do while loop
				
				f.close();
				t.close();
				remove("Batsman Data.txt");
				rename("temp.temp","Batsman Data.txt");
				
				cout << "\n\n\n\t\t Record Updated! PRESS ANY KEY TO RETURN ";
				getchar();	
			}
			
			else if(choice == 2)
	    	{
	    		ifstream f;
		    	f.open("Bowlers Data.txt", ios::in);
		    	
				Bowler B;
				int a, count = 0, i = 0, j = 0;
			
			    while(1)
			    {
				    f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.oversBowled >> B.runsConceded >> B.wickets >> B.economy;
			
					if(a == ID)
					{
						count ++;	
					}
					
					if(f.eof())
					{
						break;
					}
				}
				
				if (count == 0)
				{
					cout << "\n\tTHE PLAYER WITH THIS ID DOES'NT EXIST.\n\n";
					f.clear();
					f.seekg(0, ios::beg);
					getchar();
					return; 
				}
			
				ofstream t;    //new file object
				t.open("temp.temp", ios::app);
				
				if (!t)
				{
					cout << "\n\n\t\t\tTEMP FILE CANNOT BE CREATED!!";
					getchar();
					return; 
				} 
				
				f.clear();
				f.seekg(0, ios::beg);
				
				do {
					f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.oversBowled >> B.runsConceded >> B.wickets >> B.economy;
						
					if (a != ID)
					{
						if (j != 0)
						{
							t << "\n";
						}
					
				       	t << B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
						t << B.getOversBowled() <<"\t"<< B.getRunsConceded() <<"\t"<< B.getWickets() <<"\t"<< setprecision(4) << B.getEconomy();			       	
				    
				       	if(f.eof())
						{
							break;
						}
					}
				
					else
					{
						if (j != 0)
						{
							t << "\n";
						}
						fflush(stdin);
						
						int m, r, b, w, ov;
						
						cout << "Enter the new match's runs conceded to be added in the previous record:"<<endl;
						cin >> r;
						B.runsConceded += r;
						fflush(stdin);
						
						B.numMatches++;
						
						cout<<"Enter number of wickets taken in this match: " << endl;
						cin >> w;
						B.wickets += w;
						
						cout<<"Enter number of overs bowled in this match: " << endl;
						cin >> ov;
						B.oversBowled += ov;
						
						cout<<"Enter how many awards the player received after this match: " << endl;
						cin >> m;
						
						B.numManOfMatch += m;
						
						B.calEconomy();
						
						t << B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
						t << B.getOversBowled() <<"\t"<< B.getRunsConceded() <<"\t"<< B.getWickets() <<"\t"<< setprecision(4) << B.getEconomy();	
				       	
					}
					
					j++;
					
					if(f.eof())
					{
						break;
					}
					
					}while(1); //end of do while loop
				
				f.close();
				t.close();
				remove("Bowlers Data.txt");
				rename("temp.temp","Bowlers Data.txt");
				
				cout << "\n\n\n\t\t Record Updated! PRESS ANY KEY TO RETURN ";
				getchar();
			}
			
			else if(choice == 3)
	    	{
	    		ifstream f;
		    	f.open("WicketKeeper Data.txt", ios::in);
		    	
				WicketKeeper W;
				int a, count = 0, i = 0, j = 0;
			
			    while(1)
			    {
				    f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
			
					if(a == ID)
					{
						count ++;	
					}
					
					if(f.eof())
					{
						break;
					}
				}
				
				if (count == 0)
				{
					cout << "\n\tTHE PLAYER WITH THIS ID DOES'NT EXIST.\n\n";
					f.clear();
					f.seekg(0, ios::beg);
					getchar();
					return; 
				}
			
				ofstream t;    //new file object
				t.open("temp.temp", ios::app);
				
				if (!t)
				{
					cout << "\n\n\t\t\tTEMP FILE CANNOT BE CREATED!!";
					getchar();
					return; 
				} 
				
				f.clear();
				f.seekg(0, ios::beg);
				
				do {
					f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
						
					if (a != ID)
					{
						if (j != 0)
						{
							t << "\n";
						}
					
				       	t << W.getFName() <<" "<< W.getLName() <<"\t"<< a <<"\t"<< W.getAge() <<"\t"<< W.getNumMatches() <<"\t"<< W.getNumMOM() <<"\t"; 
						t << W.getNumCatches() <<"\t"<< W.getNumStumps();			       	
				    
				       	if(f.eof())
						{
							break;
						}
					}
				
					else
					{
						if (j != 0)
						{
							t << "\n";
						}
						fflush(stdin);
						
						int m, c, s;
						
						cout << "Enter the number of catches made in the new match: "<<endl;
						cin >> c;
						W.numCatches += c;
						fflush(stdin);
						
						W.numMatches++;
						
						cout<<"Enter number of wickets taken in this match: " << endl;
						cin >> s;
						W.numStumps += s;
						
						cout<<"Enter how many awards the player received after this match: " << endl;
						cin >> m;
						
						W.numManOfMatch += m;
								
						t << W.getFName() <<" "<< W.getLName() <<"\t"<< a <<"\t"<< W.getAge() <<"\t"<< W.getNumMatches() <<"\t"<< W.getNumMOM() <<"\t"; 
						t << W.getNumCatches() <<"\t"<< W.getNumStumps();	
				       	
					}
					
					j++;
					
					if(f.eof())
					{
						break;
					}
					
					}while(1); //end of do while loop
				
				f.close();
				t.close();
				remove("WicketKeeper Data.txt");
				rename("temp.temp","WicketKeeper Data.txt");
				
				cout << "\n\n\n\t\t Record Updated! PRESS ANY KEY TO RETURN ";
				getchar();
			}
			
		}


		void DeleteRecord(int choice)	// FUNCTION TO DELETE A PLAYER, WILL RECIEVE A CHOICE FROM "PROMPT" FUNCTION EITHER BATSMAN, BOWLER OR WICKETKEEPER
		{
			system("cls");
			int ID;
		    	cout << "Enter the player ID for whom you want to delete the data: " << endl;
		    	cin >> ID;
		    	if(choice == 1)
		    	{
		    		ifstream f;
			    	f.open("Batsman Data.txt", ios::in);
			    	
					Batsman B;
					int a, count = 0, i = 0, j = 0;
					ofstream t;    //new file object
					t.open("temp.temp", ios::app);
					do
					{
						f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >>B.avg >> B.srate;
				    if(a!=ID)
				    {
				    		if (j != 0)
							{
								t << "\n";
							}
							t << B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
							t << B.getNumInnings() <<"\t"<< B.getNumBallsPlayed() <<"\t"<< B.getTotRuns() <<"\t"<< setprecision(4) << B.getAVG() <<"\t"<< B.getSRate();
					}
					
					j++;
					
					if(f.eof())
						{
							break;
						}
					}while(1);
					f.close();
					t.close();
					cout << "PLAYER DATA DELETED";
					remove("Batsman Data.txt");
					rename("temp.temp","Batsman Data.txt");
					cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
					getchar();
		    
		        }
		        else if(choice == 2)
		    	{
		    		ifstream f;
			    	f.open("Bowlers Data.txt", ios::in);
			    	
					Bowler B;
					int a, count = 0, i = 0, j = 0;
					ofstream t;    //new file object
					t.open("temp.temp", ios::app);
					do
					{
							f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.oversBowled >> B.runsConceded >> B.wickets >> B.economy;
				    if(a!=ID)
				    {
				    		if (j != 0)
							{
								t << "\n";
							}
						t << B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
						t << B.getOversBowled() <<"\t"<< B.getRunsConceded() <<"\t"<< B.getWickets() <<"\t"<< setprecision(4) << B.getEconomy();	
					}
					
					j++;
					
					if(f.eof())
					{
						break;
					}
						
					}while(1);
					f.close();
					t.close();
					cout<<"PLAYER DATA DELETED";
					remove("Bowlers Data.txt");
					rename("temp.temp","Bowlers Data.txt");
					cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
					getchar();
		    
		        }
		         else if(choice == 3)
		    	{
		    		ifstream f;
			    	f.open("WicketKeeper Data.txt", ios::in);
			    	
					WicketKeeper W;
					int a, count = 0, i = 0, j = 0;
					ofstream t;    //new file object
					t.open("temp.temp", ios::app);
					do
					{
						f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
				    if(a!=ID)
				    {
				    		if (j != 0)
							{
								t << "\n";
							}
							t << W.getFName() <<" "<< W.getLName() <<"\t"<< a <<"\t"<< W.getAge() <<"\t"<< W.getNumMatches() <<"\t"<< W.getNumMOM() <<"\t"; 
							t << W.getNumCatches() <<"\t"<< W.getNumStumps();	
					}
					
					j++;
					
					if(f.eof())
					{
						break;
					}
					
					}while(1);
					f.close();
					t.close();
					cout<<"PLAYER DATA DELETED";
					remove("WicketKeeper Data.txt");
					rename("temp.temp","WicketKeeper Data.txt");
					cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
					getchar();
		    
		        }
			}   
			
			
		void ViewRecord(int choice)		// FUNCTION TO VIEW ALL THE PLAYERS, WILL RECIEVE A CHOICE FROM "PROMPT" FUNCTION EITHER BATSMAN, BOWLER OR WICKETKEEPER
		{
			system("cls");
			if(choice==1)
			{
				ifstream f;
			    f.open("Batsman Data.txt", ios::in);
			    Batsman B;
				int a, count = 0, i = 0, j = 0;
				
				cout << "===============================================================================\n";
				cout << "Name\t\tID\tAge\tMatches\tNo. of\tBalls\tTotal\tAVG\tStrike\n";
				cout << "\t\t\t\tPlayed\tAwards\tPlayed\tRuns\t\tRate\n";
				cout << "===============================================================================\n";
				
			    while(!f.eof())
			    {
			    	f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >>B.avg >> B.srate;
			    	cout<< B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
			    	cout<< B.getNumBallsPlayed() <<"\t"<< B.getTotRuns() <<"\t"<< setprecision(4) << B.getAVG() <<"\t"<< B.getSRate();
			    	cout<<endl;
				}
				f.close();
				cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
			}
			else if(choice==2)
			{
				ifstream f;
			    f.open("Bowlers Data.txt", ios::in);
			    Bowler B;
				int a, count = 0, i = 0, j = 0;
				
				cout << "===============================================================================\n";
				cout << "Name\t\tID\tAge\tMatches\tNo. of\tOvers\tRuns\t No. of Economy\n";
				cout << "\t\t\t\tPlayed\tAwards\tBowled\tConceded Wickets\n";
				cout << "===============================================================================\n";
				
			    while(!f.eof())
			    {
			    	f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.oversBowled >> B.runsConceded >> B.wickets >> B.economy;
			    	cout<< B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
					cout << B.getOversBowled() <<"\t"<< B.getRunsConceded() <<"\t "<< B.getWickets() <<"\t "<< setprecision(4) << B.getEconomy();
					cout<<endl;
				}
				f.close();
				cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
			}
			else if(choice==3)
			{
				ifstream f;
			    f.open("WicketKeeper Data.txt", ios::in);
			    WicketKeeper W;
				int a, count = 0, i = 0, j = 0;
				
				cout << "==============================================================\n";
				cout << "Name\t\tID\tAge\tMatches\tNo. of\tNo. of\tNo. of\n";
				cout << "\t\t\t\tPlayed\tAwards\tCatches\tStumps\n";
				cout << "==============================================================\n";
				
			    while(!f.eof())
			    {
			    	f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
			    	cout<< W.getFName() <<" "<< W.getLName() <<"\t"<< a <<"\t"<< W.getAge() <<"\t"<< W.getNumMatches() <<"\t"<< W.getNumMOM() <<"\t"; 
					cout << W.getNumCatches() <<"\t"<< W.getNumStumps();
					cout<<endl;
				}
				f.close();
				cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
			}
		}
		
	
		void Search()		// FUNCTION TO SEARCH A PLAYER EITHER BATSMAN, BOWLER OR WICKETKEEPER
		{
			system("cls");
			int ID, a, count = 0, i = 0;
	
			cout << endl << "Enter ID of the player you want to search: " << endl;
			cin >> ID;
			
			fstream f;
			f.open("Batsman Data.txt", ios::in);
		   	
			Batsman B;
			while(1)
		    {
			    f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >> B.avg >> B.srate;
				
				if(a == ID)
				{
					cout << "\nDATA FOR THE SEARCHED BATSMAN: ";
					cout << "\nNAME : " << B.fname << " " << B.lname << endl;
					cout << "ID : " << a << endl;
					cout << "AGE : " << B.age << endl;
					cout << "MATCHES PLAYED : " << B.numMatches << endl;
					cout << "NO. OF AWARDS : " << B.numManOfMatch << endl;
					cout << "NO. OF INNINGS : " << B.getNumBallsPlayed() << endl;
					cout << "NO. OF  BALLS PLAYED : " << B.getNumBallsPlayed() << endl;
					cout << "TOTAL RUNS : " << B.getTotRuns() << endl;
					cout << "AVERAGE : " << B.getAVG() << endl;
					cout << "STRIKE RATE : " << B.getSRate() << endl;
	
					f.close();
					cout << "\n\n\n\t\tPRESS ANY KEY TO RETURN ";
					getch();
					return;
				}
					
				if(f.eof())
				{
					break;
				}
				
			}
			
			f.close();
				
			Bowler Bo;
			
			f.open("Bowlers Data.txt", ios::in);
			while(1){
				f >> Bo.fname >> Bo.lname >> a >> Bo.age >> Bo.numMatches >> Bo.numManOfMatch >> Bo.oversBowled >> Bo.runsConceded >> Bo.wickets >> Bo.economy;
				if(ID == a)
				{
					cout << "\nDATA FOR THE SEARCHED BOWLER: ";
					cout << "\nNAME : " << Bo.fname << " " << Bo.lname <<endl;
					cout << "ID : " << a << endl;
					cout << "AGE : " << Bo.age << endl;
					cout << "MATCHES PLAYED : " << Bo.numMatches << endl;
					cout << "NO. OF AWARDS : " << Bo.numManOfMatch << endl;
					cout << "NO. OF OVERS BOWLED : " << Bo.getOversBowled() << endl;
					cout << "RUNS CONCEEDED : " << Bo.getRunsConceded() << endl;
					cout << "WICKETS : " << Bo.getWickets() << endl;
					cout << "ECONOMY : " << Bo.getEconomy() << endl;
				
					f.close();
					
					cout << "\n\n\n\t\tPRESS ANY KEY TO RETURN ";
					getch();
					
					return;
				}
				
				if(f.eof())
				{
					break;
				}
			}
				
			f.close();
			
		    f.open("WicketKeeper Data.txt", ios::in);
		    	
			WicketKeeper W;
			
			while(1)
			{
			    f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
				if(a == ID)
				{		
					cout << "\nDATA FOR THE SEARCHED WICKET KEEPER: ";
					cout << "\nNAME : " << W.fname << " " << W.lname << endl;
					cout << "ID : " << a << endl;
					cout << "AGE : " << W.age << endl;
					cout << "MATCHES PLAYED : " << W.numMatches << endl;
					cout << "NO. OF AWARDS : " << W.numManOfMatch << endl;
					cout << "NO. OF INNINGS : " << W.getNumBallsPlayed() << endl;
					cout << "NO. OF  BALLS PLAYED : " << W.getNumBallsPlayed() << endl;
					cout << "TOTAL RUNS : " << W.getTotRuns() << endl;
					cout << "AVERAGE : " << W.getAVG() << endl;
					cout << "STRIKE RATE : " <<W.getSRate() << endl;
					
					f.close();
					cout << "\n\n\n\t\tPRESS ANY KEY TO RETURN ";
					getch();
					
					return;
				}
					
				if(f.eof())
				{
					break;
				}
			}
				
			f.close();
			printf("\n\tTHE PLayer with this ID DOES'NT EXIST.\n\n");
			cout << "\n\n\n\t\tPress any key to return.";
			getch();
		}
    	
    	
    	// FUNCTIONS FOR PLAYERS
    	
    	
    	int CheckPlayer(int ID)		// FUNCTION TO ENSURE THE LOGIN OF A PLAYER EITHER CORRECT ID IS INSERTED OR NOT
		{
			system("cls");
			int a;
			int match = 0;
			
			fstream f;
			f.open("Batsman Data.txt", ios::in);
		   	
			Batsman B;
			while(1)
		    {
			    f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >> B.avg >> B.srate;
				
				if(a == ID)
				{
					match = 1;
					f.close();
					return match;
				}
					
				if(f.eof())
				{
					break;
				}
				
			}
			
			f.close();
				
			Bowler Bo;
			
			f.open("Bowlers Data.txt", ios::in);
			while(1){
				f >> Bo.fname >> Bo.lname >> a >> Bo.age >> Bo.numMatches >> Bo.numManOfMatch >> Bo.oversBowled >> Bo.runsConceded >> Bo.wickets >> Bo.economy;
				if(ID == a)
				{
					match = 1;
					f.close();
					return match;
				}
				
				if(f.eof())
				{
					break;
				}
			}
				
			f.close();
			
		    f.open("WicketKeeper Data.txt", ios::in);
		    	
			WicketKeeper W;
			
			while(1)
			{
			    f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
				if(a == ID)
				{		
					match = 1;
					f.close();
					return match;
				}
					
				if(f.eof())
				{
					break;
				}
			}
				
			f.close();
		}
		
				
		void ViewPlayer(int ID)		// FUNCTION TO VIEW THE PLAYER INFO, WILL RECIEVE AN ID 
		{
			system("cls");
			int a, a1;
			
			fstream f;
			f.open("Batsman Data.txt", ios::in);
		   	
			Batsman B;
			while(1)
		    {
			    f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >> B.avg >> B.srate;
				
				if(a == ID)
				{
					cout << "\nYOUR DATA: ";
					cout << "\nNAME : " << B.fname << " " << B.lname << endl;
					cout << "ID : " << a << endl;
					cout << "AGE : " << B.age << endl;
					cout << "MATCHES PLAYED : " << B.numMatches << endl;
					cout << "NO. OF AWARDS : " << B.numManOfMatch << endl;
					cout << "NO. OF INNINGS : " << B.getNumBallsPlayed() << endl;
					cout << "NO. OF  BALLS PLAYED : " << B.getNumBallsPlayed() << endl;
					cout << "TOTAL RUNS : " << B.getTotRuns() << endl;
					cout << "AVERAGE : " << B.getAVG() << endl;
					cout << "STRIKE RATE : " << B.getSRate() << endl;
	
					f.close();
					cout << "\n\n\n\t\tPRESS ANY KEY TO RETURN ";
					getch();
					return;
				}
					
				if(f.eof())
				{
					break;
				}
				
			}
			
			f.close();
				
			Bowler Bo;
			
			f.open("Bowlers Data.txt", ios::in);
			while(1){
				f >> Bo.fname >> Bo.lname >> a >> Bo.age >> Bo.numMatches >> Bo.numManOfMatch >> Bo.oversBowled >> Bo.runsConceded >> Bo.wickets >> Bo.economy;
				if(ID == a)
				{
					cout << "\nYOUR DATA: ";
					cout << "\nNAME : " << Bo.fname << " " << Bo.lname <<endl;
					cout << "ID : " << a << endl;
					cout << "AGE : " << Bo.age << endl;
					cout << "MATCHES PLAYED : " << Bo.numMatches << endl;
					cout << "NO. OF AWARDS : " << Bo.numManOfMatch << endl;
					cout << "NO. OF OVERS BOWLED : " << Bo.getOversBowled() << endl;
					cout << "RUNS CONCEEDED : " << Bo.getRunsConceded() << endl;
					cout << "WICKETS : " << Bo.getWickets() << endl;
					cout << "ECONOMY : " << Bo.getEconomy() << endl;
				
					f.close();
					
					cout << "\n\n\n\t\tPRESS ANY KEY TO RETURN ";
					getch();
					
					return;
				}
				
				if(f.eof())
				{
					break;
				}
			}
				
			f.close();
			
		    f.open("WicketKeeper Data.txt", ios::in);
		    	
			WicketKeeper W;
			
			while(1)
			{
			    f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
				if(a == ID)
				{		
					cout << "\nYOUR DATA: ";
					cout << "\nNAME : " << W.fname << " " << B.lname << endl;
					cout << "ID : " << a1 << endl;
					cout << "AGE : " << W.age << endl;
					cout << "MATCHES PLAYED : " << W.numMatches << endl;
					cout << "NO. OF AWARDS : " << W.numManOfMatch << endl;
					cout << "NO. OF INNINGS : " << W.getNumBallsPlayed() << endl;
					cout << "NO. OF  BALLS PLAYED : " << W.getNumBallsPlayed() << endl;
					cout << "TOTAL RUNS : " << W.getTotRuns() << endl;
					cout << "AVERAGE : " << W.getAVG() << endl;
					cout << "STRIKE RATE : " <<W.getSRate() << endl;
					
					f.close();
					cout << "\n\n\n\t\tPRESS ANY KEY TO RETURN ";
					getch();
					
					return;
				}
					
				if(f.eof())
				{
					break;
				}
			}
				
			f.close();
			cout << "\n\tTHE PLAYER WITH THIS ID DOES'NT EXIST.\n\n";
			cout << "\n\n\n\t\tPress any key to return.";
			getch();
}	


		void UpdatePlayer(int ID)		// FUNCTION TO UPDATE THE PLAYER INFO, WILL RECIEVE AN ID 
	    {
	    	system("cls");
			int a, j = 0;
			int match = 0;
			
			fstream f;
			f.open("Batsman Data.txt", ios::in);
		   	
			Batsman B;
			while(1)
		    {
			    f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >> B.avg >> B.srate;
				
				if(a == ID)
				{
					ofstream t;    //new file object
					t.open("temp.temp", ios::app);
					
					if (!t)
					{
						cout << "\n\n\t\t\tTEMP FILE CANNOT BE CREATED!!";
						getchar();
						return; 
					} 
					
					f.clear();
					f.seekg(0, ios::beg);
					
					do {
						f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >>B.avg >> B.srate;
					
						if (a != ID)
						{
							if (j != 0)
							{
								t << "\n";
							}
							
					       	t << B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
							t << B.getNumInnings() <<"\t"<< B.getNumBallsPlayed() <<"\t"<< B.getTotRuns() <<"\t"<< setprecision(4) << B.getAVG() <<"\t"<< B.getSRate();
					       	
					       	if(f.eof())
							{
								break;
							}
						}
					
						else
						{
							if (j != 0)
							{
								t << "\n";
							}
							fflush(stdin);
							
							string fn, ln;
							int age;
							
							cout << "Edit First Name: ";
							cin >> fn;
							
							fflush(stdin);
										
							cout << "Edit Last Name: ";
							cin >> ln;
							
							fflush(stdin);
										
							cout << "Edit Age: ";
							cin >> age;
							
							B.setFName(fn);
							B.setLName(ln);
							B.setAge(age);
							
							t << B.getFName() <<" "<< B.getLName() <<"\t"<< a <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
							t << B.getNumInnings() <<"\t"<< B.getNumBallsPlayed() <<"\t"<< B.getTotRuns() <<"\t"<< setprecision(4) << B.getAVG() <<"\t"<< B.getSRate();
					       	
						}
						
						j++;
						
						if(f.eof())
						{
							break;
						}
						
						}while(1); //end of do while loop
					
					f.close();
					t.close();
					remove("Batsman Data.txt");
					rename("temp.temp","Batsman Data.txt");
					
					cout << "\n\n\n\t\t Record Updated! PRESS ANY KEY TO RETURN ";
					getchar();	
					return;
				}
					
				if(f.eof())
				{
					break;
				}
				
			}
			
			f.close();
				
			Bowler Bo;
			
			f.open("Bowlers Data.txt", ios::in);
			while(1){
				f >> Bo.fname >> Bo.lname >> a >> Bo.age >> Bo.numMatches >> Bo.numManOfMatch >> Bo.oversBowled >> Bo.runsConceded >> Bo.wickets >> Bo.economy;
				if(ID == a)
				{
					ofstream t;    //new file object
					t.open("temp.temp", ios::app);
					
					if (!t)
					{
						cout << "\n\n\t\t\tTEMP FILE CANNOT BE CREATED!!";
						getchar();
						return; 
					} 
					
					f.clear();
					f.seekg(0, ios::beg);
					
					do {
						f >> Bo.fname >> Bo.lname >> a >> Bo.age >> Bo.numMatches >> Bo.numManOfMatch >> Bo.oversBowled >> Bo.runsConceded >> Bo.wickets >> Bo.economy;
					
						if (a != ID)
						{
							if (j != 0)
							{
								t << "\n";
							}
							
					       	t << Bo.getFName() <<" "<< Bo.getLName() <<"\t"<< a <<"\t"<< Bo.getAge() <<"\t"<< Bo.getNumMatches() <<"\t"<< Bo.getNumMOM() <<"\t"; 
							t << Bo.getOversBowled() <<"\t"<< Bo.getRunsConceded() <<"\t"<< Bo.getWickets() <<"\t"<< setprecision(4) << Bo.getEconomy();
											       	
					       	if(f.eof())
							{
								break;
							}
						}
					
						else
						{
							if (j != 0)
							{
								t << "\n";
							}
							fflush(stdin);
							
							string fn, ln;
							int age;
							
							cout << "Edit First Name: ";
							cin >> fn;
							
							fflush(stdin);
										
							cout << "Edit Last Name: ";
							cin >> ln;
							
							fflush(stdin);
										
							cout << "Edit Age: ";
							cin >> age;
							
							Bo.setFName(fn);
							Bo.setLName(ln);
							Bo.setAge(age);
							
							t << Bo.getFName() <<" "<< Bo.getLName() <<"\t"<< a <<"\t"<< Bo.getAge() <<"\t"<< Bo.getNumMatches() <<"\t"<< Bo.getNumMOM() <<"\t"; 
							t << Bo.getOversBowled() <<"\t"<< Bo.getRunsConceded() <<"\t"<< Bo.getWickets() <<"\t"<< setprecision(4) << Bo.getEconomy();
								       	
						}
						
						j++;
						
						if(f.eof())
						{
							break;
						}
						
						}while(1); //end of do while loop
					
					f.close();
					t.close();
					remove("Bowlers Data.txt");
					rename("temp.temp","Bowlers Data.txt");
					
					cout << "\n\n\n\t\t Record Updated! PRESS ANY KEY TO RETURN ";
					getchar();	
					return;
				}
				
				if(f.eof())
				{
					break;
				}
			}
				
			f.close();
			
		    f.open("WicketKeeper Data.txt", ios::in);
		    	
			WicketKeeper W;
			
			while(1)
			{
			    f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
				if(a == ID)
				{		
					ofstream t;    //new file object
					t.open("temp.temp", ios::app);
					
					if (!t)
					{
						cout << "\n\n\t\t\tTEMP FILE CANNOT BE CREATED!!";
						getchar();
						return; 
					} 
					
					f.clear();
					f.seekg(0, ios::beg);
					
					do {
						f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
					
						if (a != ID)
						{
							if (j != 0)
							{
								t << "\n";
							}
							
					       	t << W.getFName() <<" "<< W.getLName() <<"\t"<< a <<"\t"<< W.getAge() <<"\t"<< W.getNumMatches() <<"\t"<< W.getNumMOM() <<"\t"; 
							t << W.getNumCatches() <<"\t"<< W.getNumStumps();
											       	
					       	if(f.eof())
							{
								break;
							}
						}
					
						else
						{
							if (j != 0)
							{
								t << "\n";
							}
							fflush(stdin);
							
							string fn, ln;
							int age;
							
							cout << "Edit First Name: ";
							cin >> fn;
							
							fflush(stdin);
										
							cout << "Edit Last Name: ";
							cin >> ln;
							
							fflush(stdin);
										
							cout << "Edit Age: ";
							cin >> age;
							
							W.setFName(fn);
							W.setLName(ln);
							W.setAge(age);
							
							t << W.getFName() <<" "<< W.getLName() <<"\t"<< a <<"\t"<< W.getAge() <<"\t"<< W.getNumMatches() <<"\t"<< W.getNumMOM() <<"\t"; 
							t << W.getNumCatches() <<"\t"<< W.getNumStumps();
								       	
						}
						
						j++;
						
						if(f.eof())
						{
							break;
						}
						
						}while(1); //end of do while loop
					
					f.close();
					t.close();
					remove("WicketKeeper Data.txt");
					rename("temp.temp","WicketKeeper Data.txt");
					
					cout << "\n\n\n\t\t Record Updated! PRESS ANY KEY TO RETURN ";
					getchar();	
					return;
				}
					
				if(f.eof())
				{
					break;
				}
			}
				
			f.close();
			
		}


		// FUNCTIONS FOR THE USERS

		void ViewPlayers(int choice) 	// FUNCTION TO VIEW INFO OF ALL PLAYERS, WILL RECIEVE A CHOICE FROM "PROMPT" FUNCTION EITHER BATSMAN, BOWLER OR WICKETKEEPER 
		{
			system("cls");
			if(choice==1)
			{
				ifstream f;
			    f.open("Batsman Data.txt", ios::in);
			    Batsman B;
				int a, count = 0, i = 0, j = 0;
				cout << "===============================================================================\n";
				cout << "Name\t\tAge\tMatches\tNo. of\tInnings\tBalls\tTotal\tAVG\tStrike\n";
				cout << "\t\t\tPlayed\tAwards\tPlayed\tPlayed\tRuns\t\tRate\n";
				cout << "===============================================================================\n";
			    
				while(!f.eof())
			    {
			       	f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >>B.avg >> B.srate;
			    	cout<< B.getFName() <<" "<< B.getLName() <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
			    	cout<< B.getNumInnings() <<"\t"<< B.getNumBallsPlayed() <<"\t"<< B.getTotRuns() <<"\t"<< setprecision(4) << B.getAVG() <<"\t"<< B.getSRate();
			    	cout<<endl;
				}
				f.close();
				cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
			}
			else if(choice==2)
			{
				ifstream f;
			    f.open("Bowlers Data.txt", ios::in);
			    Bowler B;
				int a, count = 0, i = 0, j = 0;
				
				cout << "===============================================================================\n";
				cout << "Name\t\tAge\tMatches\tNo. of\tOvers\tRuns\t Wickets Economy\n";
				cout << "\t\t\tPlayed\tAwards\tBowled\tConceded Taken\n";
				cout << "===============================================================================\n";
				
			    while(!f.eof())
			    {
			    	f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.oversBowled >> B.runsConceded >> B.wickets >> B.economy;
			    	cout<< B.getFName() <<" "<< B.getLName() <<"\t"<< B.getAge() <<"\t"<< B.getNumMatches() <<"\t"<< B.getNumMOM() <<"\t"; 
					cout << B.getOversBowled() <<"\t"<< B.getRunsConceded() <<"\t "<< B.getWickets() <<"\t "<< setprecision(4) << B.getEconomy();
					cout<<endl;
				}
				f.close();
				cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
			}
			else if(choice==3)
			{
				ifstream f;
			    f.open("WicketKeeper Data.txt", ios::in);
			    WicketKeeper W;
				int a, count = 0, i = 0, j = 0;
			    
				cout << "=======================================================\n";
				cout << "Name\t\tAge\tMatches\tNo. of\tNo. of\tNo. of\n";
				cout << "\t\t\tPlayed\tAwards\tCatches\tStumps\n";
				cout << "=======================================================\n";
				
				while(!f.eof())
			    {
			    	f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
			    	cout<< W.getFName() <<" "<< W.getLName()  <<"\t"<< W.getAge() <<"\t"<< W.getNumMatches() <<"\t"<< W.getNumMOM() <<"\t"; 
					cout << W.getNumCatches() <<"\t"<< W.getNumStumps();
					cout<<endl;
				}
				f.close();
				cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
			}
		}


		// FUNCTIONS FOR ALL OF THEM

		void ViewRanking(int choice)
		{
			if(choice == 1)
			{
				system("cls");
				int a, count = 0, i = 0, j = 0;
				ifstream f;
				Batsman B;
				f.open("Batsman Data.txt", ios::in);
				while(!f.eof())
				{
				   	f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >>B.avg >> B.srate;
			        count++;
				}
				
				f.close();
			    float BatsmanAVG[count];
				float temp;
				
				f.open("Batsman Data.txt", ios::in);
				while(!f.eof())
				{
				   	f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >>B.avg >> B.srate;
			        BatsmanAVG[i]=B.getAVG();
			        i++;
				}
				
				f.close();
				
				for(i=0;i<count;i++)
				{
					for(j=i+1;j<count;j++)
					{
						if(BatsmanAVG[i] < BatsmanAVG[j])
					 	{    
		               		temp = BatsmanAVG[i];    
		               		BatsmanAVG[i] = BatsmanAVG[j];    
		               		BatsmanAVG[j] = temp;    
		             	}     
					}
				}
				
				int c=1;
				
				for(i=0;i<5;i++)
				{
			        fstream f;
					f.open("Batsman Data.txt", ios::in);
				   	
					Batsman B;
					
					while(1)
				    {
					    f >> B.fname >> B.lname >> a >> B.age >> B.numMatches >> B.numManOfMatch >> B.numInnings >> B.numBallsPlayed >> B.totalRuns >> B.avg >> B.srate;
						
						if(B.getAVG() ==BatsmanAVG[i])
						{
							cout << "\n NUMBER "<< c <<" BATSMAN:";
							cout << "\nNAME : " << B.fname << " " << B.lname << endl;
							cout << "ID : " << a << endl;
							cout << "AGE : " << B.age << endl;
							cout << "MATCHES PLAYED : " << B.numMatches << endl;
							cout << "NO. OF AWARDS : " << B.numManOfMatch << endl;
							cout << "NO. OF INNINGS : " << B.getNumBallsPlayed() << endl;
							cout << "NO. OF  BALLS PLAYED : " << B.getNumBallsPlayed() << endl;
							cout << "TOTAL RUNS : " << B.getTotRuns() << endl;
							cout << "AVERAGE : " << B.getAVG() << endl;
							cout << "STRIKE RATE : " << B.getSRate() << endl;
			                c++;
						}
							
						if(f.eof())
						{
							break;
						}
						
					}
					
					f.close();
		        }
		        cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
		    }
				
			else if(choice == 2)
		    {
		    	system("cls");
		      	int a, count = 0, i = 0, j = 0;
			    ifstream f;
			    float e;
			    Bowler Bo;
			    f.open("Bowlers Data.txt", ios::in);
			    while(!f.eof())
			    {
			    	 f >> Bo.fname >> Bo.lname >> a >> Bo.age >> Bo.numMatches >> Bo.numManOfMatch >> Bo.oversBowled >> Bo.runsConceded >> Bo.wickets >> Bo.economy;
			         count++;
				}
			    f.close();
			    float BowlerECN[count];
			    float temp;
				  
			    f.open("Bowlers Data.txt", ios::in);
				while(!f.eof())
			    {
			    	f >> Bo.fname >> Bo.lname >> a >> Bo.age >> Bo.numMatches >> Bo.numManOfMatch >> Bo.oversBowled >> Bo.runsConceded >> Bo.wickets >> Bo.economy;
			        BowlerECN[i]=Bo.getEconomy()+(Bo.getOversBowled()/Bo.getWickets());
			        i++;
				}
			 
			    f.close();
			    for(i=0;i<count;i++)
			    {
					for(j=i+1;j<count;j++)
					{
						if(BowlerECN[i] > BowlerECN[j])
						{    
			                temp = BowlerECN[i];    
			                BowlerECN[i] = BowlerECN[j];    
			                BowlerECN[j] = temp;    
			            }     
					}
				 }
				 int c=1;
				 
				 for(i=0;i<5;i++)
				 {
					f.open("Bowlers Data.txt", ios::in);
				   	
					Bowler Bo;
					
					while(1)
				    {
					    
						f >> Bo.fname >> Bo.lname >> a >> Bo.age >> Bo.numMatches >> Bo.numManOfMatch >> Bo.oversBowled >> Bo.runsConceded >> Bo.wickets >> Bo.economy;
						e =  Bo.getEconomy()+(Bo.getOversBowled()/Bo.getWickets());
						if(BowlerECN[i] == e )
						{
							cout << "\n NUMBER "<< c <<" BOWLER:";
							cout << "\nNAME : " << Bo.fname << " " << Bo.lname <<endl;
							cout << "ID : " << a << endl;
							cout << "AGE : " << Bo.age << endl;
							cout << "MATCHES PLAYED : " << Bo.numMatches << endl;
							cout << "NO. OF AWARDS : " << Bo.numManOfMatch << endl;
							cout << "NO. OF OVERS BOWLED : " << Bo.getOversBowled() << endl;
							cout << "RUNS CONCEEDED : " << Bo.getRunsConceded() << endl;
							cout << "WICKETS : " << Bo.getWickets() << endl;
							cout << "ECONOMY : " << Bo.getEconomy() << endl<<endl;
			                c++;
						}
							
						if(f.eof())
						{
							break;
						}
						
					}
					
					f.close();
				}
				cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
			}
			else if(choice == 3)
			{
				system("cls");
				int a, count = 0, i = 0, j = 0;
			    ifstream f;
			    WicketKeeper W;
			    f.open("WicketKeeper Data.txt", ios::in);
			    while(!f.eof())
			    {
			    	 f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
			         count++;
				}
			    f.close();
			    float WicketKeeperCATCHES[count];
			    float temp;
				  
			    f.open("WicketKeeper Data.txt", ios::in);
				while(!f.eof())
			    {
			   		f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
			        WicketKeeperCATCHES[i]=W.getNumCatches();
		            i++;
				}
		
		        f.close();
				for(i=0;i<count;i++)
				{
					for(j=i+1;j<count;j++)
					{
						if(WicketKeeperCATCHES[i] < WicketKeeperCATCHES[j])
						 {    
			               temp = WicketKeeperCATCHES[i];    
			               WicketKeeperCATCHES[i] = WicketKeeperCATCHES[j];    
			               WicketKeeperCATCHES[j] = temp;    
			             }     
					}
				}
				
				int c=1;
				for(i=0;i<5;i++)
				{
					f.open("WicketKeeper Data.txt", ios::in);
				   	
					WicketKeeper W;
					
					while(1)
				    {
					    f >> W.fname >> W.lname >> a >> W.age >> W.numMatches >> W.numManOfMatch >> W.numCatches >> W.numStumps;
						 
						if(W.getNumCatches() ==WicketKeeperCATCHES[i])
						{
							cout << "\n NUMBER "<< c <<" WICKETKEEPER:";
							cout << "\nNAME : " << W.fname << " " << W.lname << endl;
							cout << "ID : " << a << endl;
							cout << "AGE : " << W.age << endl;
							cout << "MATCHES PLAYED : " << W.numMatches << endl;
							cout << "NO. OF AWARDS : " << W.numManOfMatch << endl;
							cout << "NO. OF  CATCHES : " << W.getNumCatches() << endl<<endl;
							c++;
						}
							
						if(f.eof())
						{
							break;
						}
						
					}
					
					f.close();
				}
				cout << "\n\n\n\t\t PRESS ANY KEY TO RETURN ";
				getchar();
			}
			
		}

};

int Admin::numID = 34564; 

void Delay(long int interval)		// FUNCTION TO ANIMATE THE PRINTING PROCESS
{
	
	
	int i = 0;
	for(i = 0; i < interval*1000; i++);
}

void Title()		// FUNCTION TO PRINT THE MAIN TITLE
{
	int i;
	
	cout << endl << endl << endl;
    cout << " \t\t\t  " << ":";   //print left top corner
	
	for(i = 0; i < 20; i++)
	{
		cout << "=";
		Delay(10000);
	}
	
	cout << ":" << endl; //print top right corner
	cout << " \t\t\t  " << ":" <<  "    CRICKET INFO    ";//print vertical borders
	cout << ":" << endl;
	cout << "\t\t\t  " << ":"; //print bottom left corner
	
	for(i = 0; i < 20; i++)
	{
		cout << "=";
		Delay(10000);
	}
	
	cout << ":" << endl;
	
	for(i = 0; i < 4; i++ )
	{
		cout << endl;
	}
}

void Arrow(int i, int j)		// FUNCTION TO JUDGE THE POSITION OF THE ARROW IN THE MENU
{
	if(i == j)
	{
		printf("\t\t    ==>");
	}
	else
	{
		printf("\t\t      ");
	}
}

int MainMenu()		// FUNCTION TO SHOW THE MAIN MENU TO CHOOSE EITHER ONE IS ADMIN, PLAYER OR A USER
{
	int i;
	int position = 1;
	char keyPress = 0;
	#define MAX 3
	#define MIN 1
	while(keyPress != 13)
	{   
		system("cls");
		cout << endl << endl << endl;
	    cout << " \t\t\t  " << ":";   //print left top corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl; //print top right corner
		cout << " \t\t\t  " << ":" <<  "    CRICKET INFO    ";//print vertical borders
		cout << ":" << endl;
		cout << "\t\t\t  " << ":"; //print bottom left corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl;
		
		for(i = 0; i < 4; i++ )
		{
			cout << endl;
		}
		
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
		}
		cout << " HOME PAGE ";
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
		}
		
	
		printf("\n\t\t ------------------------------------------\n");
		Arrow(1,position);
		printf("\t\t   ADMIN           \n");
		Arrow(2,position);
		printf("\t\t   PLAYER          \n");
		Arrow(3,position);
		printf("\t\t   USER            \n");
		printf("\t\t ------------------------------------------");
		
		keyPress = getch();
		
		if(keyPress == 80 && position != MAX)
		{
			position++;	
		}
		else if(keyPress == 72 && position != MIN)
		{
			position--;
		}
		else
		{
			position = position;
		}
	}
	
	return position;
}

void ExitScreen()		// FUNCTION TO PROMPT THE USER BY " THANKS FOR VISITING " AND EXIT THE PROGRAM
{
	system("cls");
	system("color F0");
	int i;
	Title();
	 
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |                Thanks                  |";
	cout << "\n\t\t |                 for                    |";
	cout << "\n\t\t |               visiting!                |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t ------------------------------------------";
	
	for(i = 0; i < 4; i++ )
	{
		printf("\n");
	}
	
	getch();
	
}

int Prompt()		// FUNCTION TO SHOW THE MENU TO CHOOSE EITHER ONE WANTS TO CHECK BATSMAN, BOWLER OR WICKET KEEPER
{
	system("cls");
	Title();
	int i;
	int position = 1;
	char keyPress = 0;
	#define MAXP 3
	#define MINP 1
	while(keyPress != 13)
	{   
		system("cls");
		cout << endl << endl << endl;
	    cout << " \t\t\t  " << ":";   //print left top corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl; //print top right corner
		cout << " \t\t\t  " << ":" <<  "    CRICKET INFO    ";//print vertical borders
		cout << ":" << endl;
		cout << "\t\t\t  " << ":"; //print bottom left corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl;
		
		for(i = 0; i < 4; i++ )
		{
			cout << endl;
		}
	
		printf("\n\t\t ------------------------------------------\n");
		Arrow(1,position);
		printf("\t\t BATSMAN                \n");
		Arrow(2,position);
		printf("\t\t BOWLER                \n");
		Arrow(3,position);
		printf("\t\t WICKET KEEPER            \n");
		printf("\t\t ------------------------------------------");
		
		keyPress = getch();
		
		if(keyPress == 80 && position != MAXP)
		{
			position++;	
		}
		else if(keyPress == 72 && position != MINP)
		{
			position--;
		}
		else
		{
			position = position;
		}
	}
	
	return position;
}

void Menu1()		// FUNCTION TO SHOW THE MENU OF ADMIN FUNCTIONALITIES
{
	system("cls");
	Title();
	int i;
	int position = 1;
	char keyPress = 0;
	#define MAX1 11
	#define MIN1 1
	while(keyPress != 13)
	{   
		system("cls");
		cout << endl << endl << endl;
	    cout << " \t\t\t  " << ":";   //print left top corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl; //print top right corner
		cout << " \t\t\t  " << ":" <<  "    CRICKET INFO    ";//print vertical borders
		cout << ":" << endl;
		cout << "\t\t\t  " << ":"; //print bottom left corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl;
		
		for(i = 0; i < 4; i++ )
		{
			cout << endl;
		}
		
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
		}
		cout << " ADMIN PAGE ";
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
		}
		
	
		printf("\n\t\t ------------------------------------------\n");
		Arrow(1,position);
		printf("\t\t VIEW YOUR INFO                 \n");
		Arrow(2,position);
		printf("\t\t UPDATE YOUR INFO                \n");
		Arrow(3,position);
		printf("\t\t ADD A PLAYER            \n");
		Arrow(4,position);
		printf("\t\t UPDATE RECORD            \n");
		Arrow(5,position);
		printf("\t\t DELETE A PLAYER            \n");
		Arrow(6,position);
		printf("\t\t SEARCH A PLAYER            \n");
		Arrow(7,position);
		printf("\t\t VIEW ALL PLAYERS            \n");
		Arrow(8,position);
		printf("\t\t VIEW THE RANKINGS            \n");
		Arrow(9,position);
		printf("\t\t UPDATE YOUR PASSWORD            \n");
		Arrow(10,position);
		printf("\t\t RETURN TO HOME PAGE            \n");
		Arrow(11,position);
		printf("\t\t EXIT THE PROGRAM            \n");
		printf("\t\t ------------------------------------------");
		
		keyPress = getch();
		
		if(keyPress == 80 && position != MAX1)
		{
			position++;	
		}
		else if(keyPress == 72 && position != MIN1)
		{
			position--;
		}
		else
		{
			position = position;
		}
	}
	
	Admin A;
	int num;
	switch(position)
	{
		case 1:
			A.ViewAdmin();
			Menu1();
			break;
			
		case 2:
			A.UpdateAdmin();
			Menu1();
			break;
			
		case 3:
			num = Prompt();
			A.AddPlayer(num);
			Menu1();
			break;
			
		case 4:
			num = Prompt();
			A.UpdateRecord(num);
			Menu1();
			break;	
		
		case 5:
			num = Prompt();
			A.DeleteRecord(num);
			Menu1();
			break;		
			
		case 6:
			A.Search();
			Menu1();
			break;	
			
		case 7:
			num = Prompt();
			A.ViewRecord(num);
			Menu1();
			break;
			
		case 8:
			num = Prompt();
			A.ViewRanking(num);
			Menu1();
			break;
			
		case 9:
			A.UpdatePass();
			Menu1();
			break;	
			
		case 10:
			return;
			
		case 11:
			ExitScreen();
			exit(0);
			break;	
	}
	
}

void Retry1()		//  RETRY FUNCTION FOR THE ADMIN TO LOGIN WITH PASSWORD
{
	system("cls");
	int i = 0, index = 0;
	char pass[15], ch;
	string str;	
	fstream fp;
	Title();
		
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |       Re-Enter your password           |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t\t\t ";
	
	while((ch = getch()) != 13){
       if(index < 0)
           index = 0;
       // 8 is ASCII value of BACKSPACE character
       if(ch == 8){
           putch('\b');
           putch('\0');
           putch('\b');
           index--;
       continue;
       }
       pass[index++] = ch;
       putch('*');
   }
   pass[index] = '\0';
   
	
	fp.open("Admin.txt", ios::in);
	if(!fp)
	{
		cout << "\n\t\t\tAn unexpected error occured.";
		getchar();
		exit(0);
	}
	
	fp >> str;
	
	fp.close();
	if (str == pass)
	{
		Menu1();
	}
	else
	{
		exit(0);
	}
	
}

void Login1()		// FUNCTION FOR THE ADMIN TO LOGIN WITH PASSWORD
{
	system("cls");
	int i = 0, index = 0;
	char pass[15], ch;
	int r1;	
	string str;
	fstream fp;
	Title();
		
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |          Enter your password           |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t\t\t ";
	
	while((ch = getch()) != 13){
       if(index < 0)
           index = 0;
       // 8 is ASCII value of BACKSPACE character
       if(ch == 8){
           putch('\b');
           putch('\0');
           putch('\b');
           index--;
       continue;
       }
       pass[index++] = ch;
       putch('*');
   }
   pass[index] = '\0';
   
	
	fp.open("Admin.txt", ios::in);
	if(!fp)
	{
		cout << "\n\t\t\tAn unexpected error occured.";
		getchar();
		exit(1);
	}
	
	fp >> str;
	fp.close();
	
	if (str == pass)
	{
		Menu1();
	}
	else
	{
		Retry1();
	}
}

void Menu2(int id)		// FUNCTION TO SHOW THE MENU OF PLAYER FUNCTIONALITIES (PLAYER IS SPECIFIED WITH THE LOGIN ID) 
{
	system("cls");
	Title();
	int i;
	int position = 1;
	char keyPress = 0;
	#define MAX2 5
	#define MIN2 1
	while(keyPress != 13)
	{   
		system("cls");
		cout << endl << endl << endl;
	    cout << " \t\t\t  " << ":";   //print left top corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl; //print top right corner
		cout << " \t\t\t  " << ":" <<  "    CRICKET INFO    ";//print vertical borders
		cout << ":" << endl;
		cout << "\t\t\t  " << ":"; //print bottom left corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl;
		
		for(i = 0; i < 4; i++ )
		{
			cout << endl;
		}
		
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
		}
		cout << " PLAYER PAGE ";
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
		}
		
	
		printf("\n\t\t ------------------------------------------\n");
		Arrow(1,position);
		printf("\t\t VIEW YOUR INFO                 \n");
		Arrow(2,position);
		printf("\t\t UPDATE YOUR INFO                \n");
		Arrow(3,position);
		printf("\t\t VIEW THE RANKINGS            \n");
		Arrow(4,position);
		printf("\t\t RETURN TO HOME PAGE            \n");
		Arrow(5,position);
		printf("\t\t EXIT THE PROGRAM            \n");
		printf("\t\t ------------------------------------------");
		
		keyPress = getch();
		
		if(keyPress == 80 && position != MAX1)
		{
			position++;	
		}
		else if(keyPress == 72 && position != MIN1)
		{
			position--;
		}
		else
		{
			position = position;
		}
	}
	
	Admin A;
	int num;
	switch(position)
	{
		case 1:
			A.ViewPlayer(id);
			Menu2(id);
			break;
			
		case 2:
			A.UpdatePlayer(id);
			Menu2(id);
			break;
		
		case 3:
			num = Prompt();
			A.ViewRanking(num);
			Menu2(id);
			break;
				
		case 4:
			return;
			
		case 5:
			ExitScreen();
			exit(0);
			break;	
	}
	
}

void Retry2()		// RETRY FUNCTION FOR THE PLAYER TO LOGIN WITH PLAYER ID
{
	system("cls");
	int i = 0, index = 0;
	char id[6];
	char ch;
	Admin A;
	Title();
		
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |       Re-Enter your player ID          |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t\t\t ";
	
	while((ch = getch()) != 13){
       if(index < 0)
           index = 0;
       // 8 is ASCII value of BACKSPACE character
       if(ch == 8){
           putch('\b');
           putch('\0');
           putch('\b');
           index--;
       continue;
       }
       id[index++] = ch;
       putch('*');
   }
   id[index] = '\0';

   int a = atoi(id);
   
   int match = A.CheckPlayer(a);
   
	if (match == 1)
	{
		Menu2(a);
	}
	else
	{
		exit(0);
	}
	
}

void Login2()		// FUNCTION FOR THE PLAYER TO LOGIN WITH PLAYER ID
{
	system("cls");
	int i = 0, index = 0;
	char id[6];
	char ch;
	Admin A;
	Title();
		
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t |          Enter your player ID          |";
	cout << "\n\t\t |                                        |";
	cout << "\n\t\t ------------------------------------------";
	cout << "\n\t\t\t\t ";
	
	while((ch = getch()) != 13){
       if(index < 0)
           index = 0;
       // 8 is ASCII value of BACKSPACE character
       if(ch == 8){
           putch('\b');
           putch('\0');
           putch('\b');
           index--;
       continue;
       }
       id[index++] = ch;
       putch('*');
   }
   id[index] = '\0';

   int a = atoi(id);
   
   int match = A.CheckPlayer(a);
	
	if (match == 1)
	{
		Menu2(a);
	}
	else
	{
		Retry2();
	}
}

void Menu3() 	// FUNCTION TO SHOW THE MENU OF USER FUNCTIONALITIES
{
	system("cls");
	Title();
	int i;
	int position = 1;
	char keyPress = 0;
	#define MAX3 4
	#define MIN3 1
	while(keyPress != 13)
	{   
		system("cls");
		cout << endl << endl << endl;
	    cout << " \t\t\t  " << ":";   //print left top corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl; //print top right corner
		cout << " \t\t\t  " << ":" <<  "    CRICKET INFO    ";//print vertical borders
		cout << ":" << endl;
		cout << "\t\t\t  " << ":"; //print bottom left corner
		
		for(i = 0; i < 20; i++)
		{
			cout << "=";
		}
		
		cout << ":" << endl;
		
		for(i = 0; i < 4; i++ )
		{
			cout << endl;
		}
		
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
		}
		cout << " USER PAGE ";
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
		}
		
	
		printf("\n\t\t ------------------------------------------\n");
		Arrow(1,position);
		printf("\t\t VIEW ALL PLAYERS                 \n");
		Arrow(2,position);
		printf("\t\t VIEW THE RANKINGS            \n");
		Arrow(3,position);
		printf("\t\t RETURN TO HOME PAGE            \n");
		Arrow(4,position);
		printf("\t\t EXIT THE PROGRAM            \n");
		printf("\t\t ------------------------------------------");
		
		keyPress = getch();
		
		if(keyPress == 80 && position != MAX3)
		{
			position++;	
		}
		else if(keyPress == 72 && position != MIN3)
		{
			position--;
		}
		else
		{
			position = position;
		}
	}
	
	Admin A;
	int num;
	switch(position)
	{
		case 1:
			num = Prompt();
			A.ViewPlayers(num);
			Menu3();
			break;
			
		case 2:
			num = Prompt();
			A.ViewRanking(num);
			Menu3();
			break;
		
		case 3:
			return;
			
		case 4:
			ExitScreen();
			exit(0);
			break;	
	}
	
}

void Choice(int choice)		// FUNCTION TO PROCEED TO MENU1, MENU2 OR MENU3
{
	switch(choice)
	{
		case 1:
			Login1();
			break;
			
		case 2:
			Login2();
			break;		
		
		case 3:
			Menu3();
			break;	
	}
	
	return;
}

void Home()		// FUNCTION TO PRINT "HOME PAGE" AND CALLS THE MAIN MENU EVERY TIME
{
	int choice;
	
	while(1)
	{
		system("cls");
		Title();
		int i;
		
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
			Delay(10000);
		}
		cout << " HOME PAGE ";
		for (i = 0; i < 32; i++ )
		{
			cout << "_";
			Delay(10000);
		}
		choice = MainMenu();
		Choice(choice);
	}
	
}


int main()
{
	Home();
}
