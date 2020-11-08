#include <iostream>
#include <cstdlib>
#include <vector>
#include <conio.h>

using namespace std;

vector< vector< vector<unsigned char> > > vector_byte_bricks =  
{
	{
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	},

	{
		{0, 1, 0},
		{0, 1, 0},
		{0, 1, 0}
	},

	{
		{1, 1, 0},
		{1, 0, 0},
		{1, 0, 0}
	},

	{
		{0, 1, 1},
		{0, 0, 1},
		{0, 0, 1}
	},

	{
		{0, 0, 0},
		{0, 1, 1},
		{0, 1, 1}
	},

	{
		{0, 1, 0},
		{0, 1, 1},
		{0, 0, 1}
	},

	{
		{0, 0, 1},
		{0, 1, 1},
		{0, 0, 1}
	}
};

struct Brick_inf {
	bool life;
//	int typebrick;
	int posx, posy, posz;
	unsigned char array_byte_map[3][3][3];
};

Brick_inf every_brick;


vector< vector< vector<unsigned char> > > vector_byte_map = vector< vector< vector<unsigned char> > >(
	8, vector< vector<unsigned char> >(
		8, vector<unsigned char>(
			8, 0
		)
	)
);

vector< vector< vector<unsigned char> > > result_xz_xy_vector_byte_maps(
	2, vector< vector<unsigned char> >(
		8, vector<unsigned char>(
			8, 0
		)
	)
);

void Draw_map() {
	system("cls");

//where start position?? 

	//3rd idea
	//xz plane
	for (int z = 0; z < vector_byte_map.size(); z++) {
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				result_xz_xy_vector_byte_maps[0][z][x] |= vector_byte_map[z][y][x];
			}
		}
	}
	
	//xy plane
	for (int y = 0; y < 8; y++) {
		for (int x = x; y < 8; x++) {
			for (int z = 0; z < 8; z++) {
				result_xz_xy_vector_byte_maps[1][y][x] |= vector_byte_map[z][y][x];
			}
		}
	}
	
	//draw two planes
	cout << "front" << endl;
	for (int i = 0; i < 2; i++) {
		for (int zy = 0; zy < 8; zy++) {
			for (int x = 0; x < 8; x++) {
				unsigned char buff = 43;
				if (result_xz_xy_vector_byte_maps[i][zy][x] & 1) {
					buff = 127;
				}
				cout << buff;
			}
			cout << endl;
		}
		cout << endl << endl << "hight" << endl;;
	}
}

void Move_block(char button_char) {
	//move in 3d
	int button_int = button_char;
	switch(button_int) {
			case 72: {
//				cout << "UP(Push) ";
				
				break;
			}
			case 80: {
//				cout << "DOWN(Pop) ";
				
				break;
			}
			case 75: {
//				cout << "LEFT ";
				
				break;
			}
			case 77: {
//				cout << "RIGHT ";
				
				break;
			}
			default: {
//				cout << button_int << "_" << button_char << " ";
				break;
			}
		}
		Draw_map();
}


void Create_brick() {
	//code for generate block in map??
	every_brick.life = true;
	every_brick.posx = 4; 
	every_brick.posy = 4; 
	every_brick.posz = 1;
	
	
//	every_brick = Brick_inf();
}

void Brick_Down() {
	cout << "BRICK_DOWN" << endl;
	
	if (every_brick.life) {
		//code for brick in down
		
	} else {
		Create_brick();
	}
	Draw_map();
}


void Rotate_block() {
	
}

//void Check_condition() {
//	
//}


// only for pc game
void Pause() {
	
}


void Timer(int seconds) {
//	int timer = seconds;
	while (seconds >= 1) {
		system("cls");
		cout << "ready" << seconds;
		for (int i = 0; i < 300000000; i++) int a = 0;
		seconds--;
	} 
}

void Game() {
	cout << "game started";
	Timer(3);
	cout << "after Timer" << endl;
	bool play_game = true;
	cout << "after play_game" << endl;
	int step = 0;
	cout << "after step" << endl;
	Draw_map();
	while (play_game) {
		step++;
		if (step > 10000) {
			Brick_Down();
			step = 0;
//			cout << "step downed" << endl;
		}
		char button_char;
		if ( (_kbhit()) && (button_char = getch()) ){
			Move_block(button_char);
		}
		if (button_char == 'q') {
			play_game = false;
		}
	}
}

void For_testing() {
	cout << "all bricks=" << vector_byte_bricks.size() << endl;
	for (int i = 0; i < vector_byte_bricks.size(); i++) {
		cout << i << " type. block_matrix " << vector_byte_bricks[i].size() << endl;
	}
}

int main() {
	//testing some things
//	For_testing();
//	Game();
	Draw_map();
	return 0;
	//main menu
//	bool main_menu = true;
//	while (main_menu) {
//		char buffer;
//		cout << "press 'X' to start game" << endl;
//		cout << "press 'Q' to exit" << endl;
//		cin >> buffer;
//		switch (buffer) {
//			case 'p': {
//				cout << "starting game..." << endl;
//				Game();
//				break;
//			}
//				
//			case 'q': {
//				cout << "closing program..." << endl;
//				main_menu = false;
//				break;
//			}
//				
//			default:
//				break;
//		}
//	}
//	cout << "exit";
}
