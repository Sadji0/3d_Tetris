#include <iostream>
#include <cstdlib>

using namespace std;

unsigned char array_byte_map[3][3][3] = {
											{
												{0, 0, 0},
												{0, 0, 0},
												{0, 0, 0}
											},
											{
												{0, 0, 0},
												{0, 0, 0},
												{0, 0, 0}
											},
											{
												{0, 0, 0},
												{0, 0, 0},
												{0, 0, 0}
											}
										};

void Create_Random_Figure(unsigned char sum_bricks = 4) {
	int posx = rand() % 3;
	int posy = rand() % 3;
	int posz = rand() % 3;
	array_byte_map[posz][posy][posx] = 1;
	for (int i = 0; i < sum_bricks; i++) {
		bool brick_set = false;
		while (!brick_set) {
			char next_coordinate = (rand() % 3 + 1) * (rand() % 3 - 1);
			switch (next_coordinate) {
				case -1:
					if (posz > 0){
						if (array_byte_map[posz - 1][posy][posx] != 1) {
							posz--;
							brick_set = true;
						}
					}
					break;
				
				case 1:
					if (posz < 2){
						if (array_byte_map[posz + 1][posy][posx] != 1) {
							posz++;
							brick_set = true;
						}
					}
					break;
				
				case -2:
					if (posy > 0){
						if (array_byte_map[posz][posy - 1][posx] != 1) {
							posy--;
							brick_set = true;
						}
					}
					break;
				
				case 2:
					if (posy < 2){
						if (array_byte_map[posz][posy + 1][posx] != 1) {
							posy++;
							brick_set = true;
						}
					}
					break;
					
				case -3:
					if (posx > 0){
						if (array_byte_map[posz][posy][posx - 1] != 1) {
							posx--;
							brick_set = true;
						}
					}
					break;
				
				case 3:
					if (posx < 2){
						if (array_byte_map[posz][posy][posx + 1] != 1) {
							posx++;
							brick_set = true;
						}
					}
					break;
				
				default:
					break;
			}
			if (brick_set) {
				array_byte_map[posz][posy][posx] = 1;
			}
		}
	}
}

int main() {
	
	return 0;
}
