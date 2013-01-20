/*
This is The chess game screen class which will display the game actions on the screen.

@file Screen.cpp
@author Gandi Pirkov
*/

#include "Screen.hpp"

//Screen::Screen(int a = 0)
//{
//	GameBeginer = a;
//}
//
/////Will maintain the game console.
//void Screen::printScreen()
//{
//	while(Gameover()==0)
//	{
//		cout<<"   "<<"1"<<"    "<<"2"<<"    "<<"3"<<"    "<<"4"<<"    "<<"5"<<"    "<<"6"<<"    "<<"7"<<"    "<<"8"<<"  "<<endl;
//		cout<<"------------------------------------------"<<endl;
//		cout<<"|vvvvv     vvvvv     vvvvv     vvvvv     |"<<endl;
//		cout<<"|> "<<A[0][0]<<" <  "<<A[0][1]<<"  > "<<A[0][2]<<" <  "<<A[0][3]<<"  > "<<A[0][4]<<" <  "<<A[0][5]<<"  > "<<A[0][6]<<" <  "<<A[0][7]<<"  | 1"<<endl;
//		cout<<"|^^^^^     ^^^^^     ^^^^^     ^^^^^     |"<<endl;
//		cout<<"|     vvvvv     vvvvv     vvvvv     vvvvv|"<<endl;
//		cout<<"|  "<<A[1][0]<<"  > "<<A[1][1]<<" <  "<<A[1][2]<<"  > "<<A[1][3]<<" <  "<<A[1][4]<<"  > "<<A[1][5]<<" <  "<<A[1][6]<<"  > "<<A[1][7]<<" <| 2"<<endl;
//		cout<<"|     ^^^^^     ^^^^^     ^^^^^     ^^^^^|"<<endl;
//		cout<<"|vvvvv     vvvvv     vvvvv     vvvvv     |"<<endl;
//		cout<<"|> "<<A[2][0]<<" <  "<<A[2][1]<<"  > "<<A[2][2]<<" <  "<<A[2][3]<<"  > "<<A[2][4]<<" <  "<<A[2][5]<<"  > "<<A[2][6]<<" <  "<<A[2][7]<<"  | 3"<<endl;
//		cout<<"|^^^^^     ^^^^^     ^^^^^     ^^^^^     |"<<endl;
//		cout<<"|     vvvvv     vvvvv     vvvvv     vvvvv|"<<endl;
//		cout<<"|  "<<A[3][0]<<"  > "<<A[3][1]<<" <  "<<A[3][2]<<"  > "<<A[3][3]<<" <  "<<A[3][4]<<"  > "<<A[3][5]<<" <  "<<A[3][6]<<"  > "<<A[3][7]<<" <| 4"<<endl;
//		cout<<"|     ^^^^^     ^^^^^     ^^^^^     ^^^^^|"<<endl;
//		cout<<"|vvvvv     vvvvv     vvvvv     vvvvv     |"<<endl;
//		cout<<"|> "<<A[4][0]<<" <  "<<A[4][1]<<"  > "<<A[4][2]<<" <  "<<A[4][3]<<"  > "<<A[4][4]<<" <  "<<A[4][5]<<"  > "<<A[4][6]<<" <  "<<A[4][7]<<"  | 5"<<endl;
//		cout<<"|^^^^^     ^^^^^     ^^^^^     ^^^^^     |"<<endl;
//		cout<<"|     vvvvv     vvvvv     vvvvv     vvvvv|"<<endl;
//		cout<<"|  "<<A[5][0]<<"  > "<<A[5][1]<<" <  "<<A[5][2]<<"  > "<<A[5][3]<<" <  "<<A[5][4]<<"  > "<<A[5][5]<<" <  "<<A[5][6]<<"  > "<<A[5][7]<<" <| 6"<<endl;
//		cout<<"|     ^^^^^     ^^^^^     ^^^^^     ^^^^^|"<<endl;
//		cout<<"|vvvvv     vvvvv     vvvvv     vvvvv     |"<<endl;
//		cout<<"|> "<<A[6][0]<<" <  "<<A[6][1]<<"  > "<<A[6][2]<<" <  "<<A[6][3]<<"  > "<<A[6][4]<<" <  "<<A[6][5]<<"  > "<<A[6][6]<<" <  "<<A[6][7]<<"  | 7"<<endl;
//		cout<<"|^^^^^     ^^^^^     ^^^^^     ^^^^^     |"<<endl;
//		cout<<"|     vvvvv     vvvvv     vvvvv     vvvvv|"<<endl;
//		cout<<"|  "<<A[7][0]<<"  > "<<A[7][1]<<" <  "<<A[7][2]<<"  > "<<A[7][3]<<" <  "<<A[7][4]<<"  > "<<A[7][5]<<" <  "<<A[7][6]<<"  > "<<A[7][7]<<" <| 8"<<endl;
//		cout<<"|     ^^^^^     ^^^^^     ^^^^^     ^^^^^|"<<endl;
//		cout<<"------------------------------------------"<<endl;
//		int Fcoord,Scoord;
//		int FcoordD,ScoordD;
//		cout << "Choose which figure you want to move: ";
//		cin >> Fcoord >> Scoord;
//		cout << "Choose destination: ";
//		cin >> FcoordD >> ScoordD;
//		ChessBoard::Move(Fcoord, Scoord, FcoordD, ScoordD);
//		system("cls");
//	}
//	if(Gameover() == 1) 
//	{
//		cout<<"White player wins"<<endl; 
//		return; 
//	}
//	if(Gameover() == 2) 
//	{
//		cout<<"Black player wins"<<endl; 
//		return; 
//	}
//}
