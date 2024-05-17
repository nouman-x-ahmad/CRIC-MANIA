/*
		Nouman_X_ahmad


*/


#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void swap_player(int player_1, int player_2, string name_1, string name_2)
{
	int temp = 0;
	temp = player_1;
	player_1 = player_2;
	player_2 = temp;
	string temp_2;
	temp_2 = name_1;
	name_1 = name_2;
	name_2 = temp_2;





}

//----------------------------------------------------------------------------
void live_score_b(string name_1, int player_1, float* balls_b, float* strikerate_b, int x, int* overs_a, float* bals_a, int* total_b, int i, int* run_rte_b, string* name_a, int* wicket_a, int* runs_md_a, int* over_md_a, int g)
{


	cout << "name " << "                        " << "score" << "                 " << "balls" << "                        runrate" << endl;


	cout << name_1 << "                          ";
	cout << player_1 << "                  " << balls_b[i] << "                        " << strikerate_b[i] << endl;


	cout << "| overs in each innings: " << x << "|  overs bowled : " << overs_a[0] << "." << bals_a[0] << " | " << endl;
	cout << "total score: " << total_b[0] << " |  wickets: " << i << " | run-rate " << run_rte_b[0] << "" << endl;
	cout << endl;

	cout << "bowler: " << name_a[g] << "    |	  wickets/runs " << wicket_a[g] << "/" << runs_md_a[g] << " |          overs:" << over_md_a[g] << endl;










}


//--------------------------------------------------------------------------------------










void runs_card_b(int* bat_b, int i)
{
	int t = 0;
	if (i < 5)
	{
		t = rand() % 10;
		if (t == 7)
		{
			bat_b[0] = 7;
		}
		else if (t == 0)
		{
			bat_b[0] = 0;
		}
		else if (t == 1)
		{
			bat_b[0] = 1;
		}
		else if (t == 2)
		{
			bat_b[0] = 2;

		}
		else if (t == 3)
		{
			bat_b[0] = 3;

		}
		else if (t == 4)
		{
			bat_b[0] = 4;
		}
		else if (t == 5)
		{
			bat_b[0] = 5;
		}
		else if (t == 6)
		{
			bat_b[0] = 4;
		}
		else if (t == 8 or t == 9)
		{
			bat_b[0] = 6;
		}
	}
	else if (i > 5)
	{
		if (t == 1)
		{
			bat_b[0] = 1;
		}
		else if (t == 2)
		{
			bat_b[0] = 2;

		}
		else if (t == 3)
		{
			bat_b[0] = 3;

		}
		else if (t == 4)
		{
			bat_b[0] = 4;
		}
		else if (t == 5)
		{
			bat_b[0] = 5;
		}
		else if (t == 6 or t == 7 or t == 8 or t == 9)
		{
			bat_b[0] = 7;
		}
	}
}


//-----------------------------------------------------------------------------------------------------------

void batting_b(int* runs_b, int i, string* name_a, int* bat_b, float* balls_b, float* strikerate_b, int x, float* bals_a, int* overs_a, int* total_b, int* run_rte_b, string* name_b, int k, int* temp_b, int* wicket_a, int* over_md_a, int* runs_md_a, int* b6_b, int* b4_b, int* result_a, int* result_b)
{
	//name_a[i];
	//name_b[j];
	runs_card_b(bat_b, i);
	//bat_b[0] = rand() % 8;
	bals_a[0] += 1;
	//cout << bat[0] << endl;

	int player_1 = runs_b[i];
	//int player_2 = run_a[i + 1];
	string name_1 = name_b[i];
	//string name_2 = name_a[i + 1];

	system("pause ");
	system("cls");


	runs_b[i] += bat_b[0];
	balls_b[i] += 1.0;

	int g = temp_b[0];
	strikerate_b[i] = (runs_b[i] / balls_b[i]) * 100.0;

	if (bals_a[0] == 6)
	{
		overs_a[0] += 1;
		bals_a[0] = 0.0;

		run_rte_b[0] = total_b[0] / overs_a[0];
		temp_b[0] -= 1;
		g = temp_b[0];

		over_md_a[g] += 1;

		if (temp_b[0] == 6)
		{
			temp_b[0] = 10;

		}

	}
	wicket_a[g] = i;

	//TEAM B LIVE RUN::::
	live_score_b(name_1, player_1, balls_b, strikerate_b, x, overs_a, bals_a, total_b, i, run_rte_b, name_a, wicket_a, runs_md_a, over_md_a, g);


	runs_md_a[g] += bat_b[0];
	result_b[0] = total_b[0];
	if (bat_b[0] == 7)
	{
		cout << name_1 << player_1 << " out" << endl;
		//balling_b(overs_b, bals_b);
		return;
	}

	total_b[0] += bat_b[0];
	if (bat_b[0] == 6)
	{
		b6_b[i] += 1;
	}
	if (bat_b[0] == 4)
	{
		b4_b[i] += 1;
	}
	if (result_a[0] != 0)
	{
		if (result_a[0] < result_b[0])
		{
			return;
		}
	}
	if (x == overs_a[0])
	{
		return;
	}

	if (bat_b[0] != 7)
	{
		//RECURSION...
		batting_b(runs_b, i, name_a, bat_b, balls_b, strikerate_b, x, bals_a, overs_a, total_b, run_rte_b, name_b, k, temp_b, wicket_a, over_md_a, runs_md_a, b6_b, b4_b, result_a, result_b);
	}
	bat_b[0] = 0;
}


//---------------------------------------------------------------------------



void print_score_b(int* runs_b, string* name_a, int* bat_b, float* balls_b, float* strikerate_b, int x, float* bals_a, int* overs_a, int* total_b, int* run_rte_b, string* name_b, int k, int* temp_b, int* wicket_a, int* over_md_a, int* runs_md_a, int* b6_b, int* b4_b)
{




	cout << "__________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;

	cout << "|   " << "batter_name" << "\t   |  runs \t\t  balls| \t\t   no. of fours| \t\t numbers of sixes |\t strike rate|" << endl;
	for (int j = 0; j <= 10; j++)
	{
		cout << "|" << name_b[j] << setw(21) << "" << runs_b[j] << "\t\t\t" << balls_b[j] << "\t" << "\t\t" << b4_b[j] << "\t\t" << " " << b6_b[j] << " \t\t " << strikerate_b[j] << "  " << endl;
	}

	system("pause ");
	cout << "balling card" << endl;
	cout << endl;
	cout << "name" << "  \t\t " << "wickets" << "  \t\t " << "runs" << "  \t\t " << "overs" << endl;
	for (int i = 6; i <= 10; i++)
	{
		cout << name_a[i] << "  \t\t  " << wicket_a[i] << "\t\t" << runs_md_a[i] << " \t\t " << over_md_a[i] << endl;
	}

}




//-----------------------------------------------------------------
void live_score_a(string name_1, int player_1, float* balls, float* strikerate, int x, int* overs_b, float* bals_b, int* total_a, int i, int* run_rte, string* name_b, int* wicket_b, int* runs_md_b, int* over_md_b, int g)
{


	cout << "name " << "                        " << "score" << "                 " << "balls" << "                        runrate" << endl;


	cout << name_1 << "                          ";
	cout << player_1 << "                  " << balls[i] << "                        " << strikerate[i] << endl;


	cout << "| overs in each innings: " << x << "|  overs bowled : " << overs_b[0] << "." << bals_b[0] << " | " << endl;
	cout << "total score: " << total_a[0] << " |  wickets: " << i << " | run-rate " << run_rte[0] << "" << endl;
	cout << endl;
	cout << "bowler: " << name_b[g] << "    |	  wickets/runs " << wicket_b[g] << "/" << runs_md_b[g] << " |          overs:" << over_md_b[g] << endl;

}


// TO FIND PROBABILITY OF RUNS
void runs_card_a(int* bat, int i)
{
	int t = 0;
	if (i < 5)
	{
		t = rand() % 10;
		if (t == 7)
		{
			bat[0] = 7;
		}
		else if (t == 0)
		{
			bat[0] = 0;
		}
		else if (t == 1)
		{
			bat[0] = 1;
		}
		else if (t == 2)
		{
			bat[0] = 2;

		}
		else if (t == 3)
		{
			bat[0] = 3;

		}
		else if (t == 4)
		{
			bat[0] = 4;
		}
		else if (t == 5)
		{
			bat[0] = 5;
		}
		else if (t == 6)
		{
			bat[0] = 4;
		}
		else if (t == 8 or t == 9)
		{
			bat[0] = 6;
		}
	}
	else if (i > 5)
	{
		if (t == 1)
		{
			bat[0] = 1;
		}
		else if (t == 2)
		{
			bat[0] = 2;

		}
		else if (t == 3)
		{
			bat[0] = 3;

		}
		else if (t == 4)
		{
			bat[0] = 4;
		}
		else if (t == 5)
		{
			bat[0] = 5;
		}
		else if (t == 6 or t == 7 or t == 8 or t == 9)
		{
			bat[0] = 7;
		}
	}






}



//--------------------------------------------------------------------------------

void batting_a(int* run_a, int i, string* name_a, int* bat, float* balls, float* strikerate, int x, float* bals_b, int* overs_b, int* total_a, int* run_rte, string* name_b, int j, int* temp, int* wicket_b, int* over_md_b, int* runs_md_b, int* b6_a, int* b4_a, int* result_a, int* result_b)
{
	name_a[i];
	//name_b[j];



	runs_card_a(bat, i);


	bals_b[0] += 1;
	//cout << bat[0] << endl;

	int player_1 = run_a[i];
	//int player_2 = run_a[i + 1];
	string name_1 = name_a[i];
	//string name_2 = name_a[i + 1];

	system("pause ");
	system("cls");


	run_a[i] += bat[0];
	balls[i] += 1.0;


	strikerate[i] = (run_a[i] / balls[i]) * 100.0;
	int g = temp[0];
	if (bals_b[0] == 6)
	{
		overs_b[0] += 1;
		bals_b[0] = 0.0;

		run_rte[0] = total_a[0] / overs_b[0];
		temp[0] -= 1;
		g = temp[0];

		over_md_b[g] += 1;

		if (temp[0] == 6)
		{
			temp[0] = 10;

		}

	}
	if (bat[0] == 7)
	{
		wicket_b[g] += 1;
	}

	live_score_a(name_1, player_1, balls, strikerate, x, overs_b, bals_b, total_a, i, run_rte, name_b, wicket_b, runs_md_b, over_md_b, g);




	runs_md_b[g] += bat[0];
	result_a[0] = total_a[0];
	if (bat[0] == 7)
	{
		cout << name_1 << player_1 << " out" << endl;
		//balling_b(overs_b, bals_b);
		return;
	}
	total_a[0] += bat[0];
	if (bat[0] == 6)
	{
		b6_a[i] += 1;
	}
	if (bat[0] == 4)
	{
		b4_a[i] += 1;
	}

	if (result_b[0] != 0)
	{
		if (result_a[0] > result_b[0])
		{
			return;
		}
	}
	if (x == overs_b[0])
	{
		return;
	}

	if (bat[0] != 7)
	{
		batting_a(run_a, i, name_a, bat, balls, strikerate, x, bals_b, overs_b, total_a, run_rte, name_b, j, temp, wicket_b, over_md_b, runs_md_b, b6_a, b4_a, result_a, result_b);
	}
	bat[0] = 0;


}

//---------------------------------------------------------------------------------------------------------


void bowl_card_a(string* name_b, int* wicket_b, int* runs_md_b, int* over_md_b)
{
	cout << "name" << "  \t\t " << "wickets" << "  \t\t " << "runs" << "  \t\t " << "overs" << endl;
	for (int i = 6; i <= 10; i++)
	{
		cout << name_b[i] << "  \t\t  " << wicket_b[i] << "\t\t" << runs_md_b[i] << " \t\t " << over_md_b[i] << endl;
	}
}
void print_score_a(int* run_a, string* name_a, int* bat, float* balls, float* strikerate, int x, float* bals_b, int* overs_b, int* total_a, int* run_rte, string* name_b, int j, int* temp, int* wicket_b, int* over_md_b, int* runs_md_b, int* b6_a, int* b4_a)
{

	cout << "__________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;

	cout << "|   " << "batter_name" << "\t   |  runs \t\t  balls| \t\t   no. of fours| \t\t numbers of sixes |\t strike rate|" << endl;
	for (int j = 0; j <= 10; j++)
	{
		cout << "|" << name_a[j] << setw(12) << "  " << run_a[j] << "\t\t\t  " << balls[j] << "\t\t  " << "\t\t" << b4_a[j] << "\t\t\t" << " " << b6_a[j] << " \t\t\t " << strikerate[j] << "  " << endl;
	}

	system("pause ");
	cout << "balling card" << endl;
	cout << endl;
	bowl_card_a(name_b, wicket_b, runs_md_b, over_md_b);


}


/*
________________________________________________________________________________________________________________________________________________________________________________________________
|																																																|
|																																																|
|																																																|
|_______________________________________________________________________________________________________________________________________________________________________________________________|

*/




void Team_A(int* runs_a, int x, int* result_a, int* result_b)
{
	string name_a[11] = { "aslam","nouman","ayushna","laraib","asad","iftikhar","bilorani","charles","dickens","iqra","billo" };
	string name_b[11] = { "babar","fakhar_z","rizwan","imam-h","hafeez","asif-ali","shadab","hassan-a","haris-r","shaheen","nawaz" };
	//INITIALIZING
	int* bat = new int[1];
	int wicket_b[11] = {};
	int over_md_b[11] = {};
	int runs_md_b[11] = {};
	int b6_a[11] = {};
	int b4_a[11] = {};
	float balls[11] = {};

	float strikerate[11] = {};
	float bals_b[1] = {};
	int overs_b[1] = {};
	int total_a[1] = {};
	int run_rte[1] = {};
	static int temp[1];
	temp[0] = 10;
	static int j;
	j = 10;

	for (int i = 0; i <= 10; i++)
	{
		runs_a[i] = 0;
	}



	for (static int i = 0; i <= 10; i++)
	{
		balls[i] = 0;
		bat[0] = 0;
		strikerate[i] = { 0 };
		runs_a[i] = { 0 };


		batting_a(runs_a, i, name_a, bat, balls, strikerate, x, bals_b, overs_b, total_a, run_rte, name_b, j, temp, wicket_b, over_md_b, runs_md_b, b6_a, b4_a, result_a, result_b);
		if (x == overs_b[0])
		{
			break;
		}
		//WINNING CONDITION TO EXIT LOOP
		if (result_b[0] != 0)
		{
			if (result_a[0] > result_b[0])
			{
				return;
			}
		}

		system("pause ");
		system("cls");
		//if()






	}


	//INNING SUMMARY

	print_score_a(runs_a, name_a, bat, balls, strikerate, x, bals_b, overs_b, total_a, run_rte, name_b, j, temp, wicket_b, over_md_b, runs_md_b, b6_a, b4_a);



	system("pause ");
	system("cls");
}


//FOR TEAM B

void Team_B(int* runs_b, int x, int* result_a, int* result_b)
{



	string name_a[11] = { "aslam  ","nouman  ","ayushna ","laraib  ","asad   ","iftikhar","bilorani","charles ","dickens  ","iqra   ","billo  " };
	string name_b[11] = { "babar","fakhar.z","rizwan","imam-h","hafeez","asif-a","shadab","hassan-a","haris-r","shaheen","nawaz" };


	//INITIALIZING
	int* bat_b = new int[1];
	int wicket_a[11] = {};
	int over_md_a[11] = {};
	int runs_md_a[11] = {};
	int b6_b[11] = {};
	int b4_b[11] = {};
	float balls_b[11] = {};

	float strikerate_b[11] = {};
	float bals_a[1] = {};
	int overs_a[1] = {};
	int total_b[1] = {};
	int run_rte_b[1] = {};
	int temp_b[1];
	temp_b[0] = 10;
	static int k = 10;

	for (int i = 0; i <= 10; i++)
	{
		runs_b[i] = 0;
	}



	for (static int i = 0; i <= 10; i++)
	{
		balls_b[i] = 0;
		bat_b[0] = 0;
		strikerate_b[i] = { 0 };
		runs_b[i] = { 0 };

		//LIVE BATTING
		batting_b(runs_b, i, name_a, bat_b, balls_b, strikerate_b, x, bals_a, overs_a, total_b, run_rte_b, name_b, k, temp_b, wicket_a, over_md_a, runs_md_a, b6_b, b4_b, result_a, result_b);
		if (x == overs_a[0])
		{
			break;
		}
		//TO DECIDE THE WINNER...
		if (result_a[0] != 0)
		{
			if (result_a[0] < result_b[0])
			{
				break;
			}
		}


		system("pause ");
		system("cls");
		//if()






	}



	//INNING SUMMARY
	print_score_b(runs_b, name_a, bat_b, balls_b, strikerate_b, x, bals_a, overs_a, total_b, run_rte_b, name_b, k, temp_b, wicket_a, over_md_a, runs_md_a, b6_b, b4_b);



	system("pause ");
	system("cls");










}

//-------------------------------------------------------------------------


//WRITE OVER
void FILEOVERS(int& x)
{
	ofstream write;
	write.open("overs.txt", ios::out);
	if (write.is_open()) {
		write << x << endl;
		write.close();
	}
	else
		cout << "File not Opened!";
}

//READ OVER
int Readfile(int& x)
{
	//int x;
	ifstream read;
	read.open("overs.txt");
	if (read.is_open()) {
		read >> x;
		read.close();
	}
	else
		cout << "File not Opened!";

	return x;
}


//TOSS FUNC...
int TOSS(int& toss)
{

	toss = rand() % 2;
	return toss;
}





// MAIN FUNC...
int main()
{

	//ofstream MyFile("filename.txt");

	int x = 0;
	int toss = 0;
	string t;

	srand(time(0));

	int* runs_a = new int[11];
	int* runs_b = new int[11];
	int* result_a = new int[1];
	int* result_b = new int[1];
	result_a[0] = 0;
	result_b[0] = 0;


	cout << "\n\n\n\n";
	cout << setw(35) << "			|||		MADE BY NOUMAN AHMAD   |||" << endl;
	//cout << setw(40) << "        |||    ______________________  ||| \n";

	system("pause");
	system("cls");
	cout << "\n\n\n\n\n";
	for (int l = 0; l < 12; l++)
	{
		system("cls");
		cout << "\n\n\n" << endl;
		cout << setw(40) << "loading." << endl;
		system("cls");
		cout << "\n\n\n" << endl;
		cout << setw(41) << "loading.." << endl;
		system("cls");
		cout << "\n\n\n" << endl;
		cout << setw(42) << "loading..." << endl;
	}

	system("cls");
	cout << "\n\n\n\n" << endl;
	for (int i = 0; i < 25; i++)
	{
		cout << "\n\n\n\n";
		cout << setw(50) << "rapid studios present" << endl;
		system("cls");
	}
	system("cls");


	cout << "\n\n\n\n" << endl;
	for (int i = 0; i < 25; i++)
	{
		cout << "\n\n\n\n";
		cout << setw(50) << "cricket mania " << endl;
		system("cls");
	}



	cout << "press any key to start the match" << endl;
	system("pause");



	//file handling for overs........
	cout << "enter no. of overs: ";
	cin >> x;
	FILEOVERS(x);
	x = Readfile(x);





	cout << "one innings hour will be: " << x << endl;
	cout << "the total overs in match will be: " << (x * 2) << endl;

	cout << "Now the match is between :" << endl;
	cout << setw(45) << "Team A v/s Team B " << endl;

	cout << "Time for Toss " << endl;
	toss = TOSS(toss);
	//	toss = rand() % 2;
	if (toss == 1)
	{
		t = "head";
		cout << "head" << endl;
	}

	else if (toss == 0)
	{
		t = "tail";
		cout << "tail" << endl;

	}




	//if team a won the toss

	if (t == "head")
	{
		cout << "names" << setw(45) << "score" << endl;
		cout << "Team A Won the toss" << endl;
		Team_A(runs_a, x, result_a, result_b);
		//score_card_a();
		Team_B(runs_b, x, result_a, result_a);
		//score_card_b();
		cout << endl;
		cout << "\n\n\n";
		cout << "___________________________________________________________________________________________________________________________________________________" << endl;
		if (result_a[0] > result_b[0])
		{
			cout << setw(23) << "*************   " << "Team 'A' won" << " *************   " << endl;
		}

		else if (result_b[0] > result_a[0])
		{

			cout << setw(23) << "*************   " << "Team 'B' won" << " ***********" << endl;
		}
		else
		{
			cout << setw(23) << "*************   " << " 'DRAW' " << " ***********" << endl;
		}

		cout << "___________________________________________________________________________________________________________________________________________________" << endl;

	}
	//total_stats();


//if team b won the toss....
	else if (t == "tail")
	{
		cout << "Team B Won the toss" << endl;
		Team_B(runs_b, x, result_a, result_b);
		//score_card_b();
		Team_A(runs_a, x, result_a, result_b);
		//score_card_a();

		//total_stats();
		cout << endl;
		cout << "\n\n\n";
		cout << "___________________________________________________________________________________________________________________________________________________" << endl;
		if (result_a[0] > result_b[0])
		{
			cout << setw(23) << "*************   " << "Team 'A' won" << "*************   " << endl;
		}

		else if (result_b[0] > result_a[0])
		{

			cout << setw(23) << "*************   " << "Team 'B' won" << " ***********" << endl;
		}
		else
		{
			cout << setw(23) << "*************   " << " 'DRAW' " << " ***********" << endl;
		}

		cout << "___________________________________________________________________________________________________________________________________________________" << endl;

	}
	//int result=result_a[0];



	//******************************************************************************************-----THE   END----******************************************************************************************* 
}