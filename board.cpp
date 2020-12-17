
#include "circle.cpp"
#include "triangle.cpp"
#include "square.cpp"

class board {
	shape *** shapes_Array;
	int ** board_Array;
	int  mouse_X;
	int  mouse_Y;
	int score;
	int target;
	int progressBar;
	int time;
	int level;
	string playerName;
	bool paused;
	int state = 0;
	int size;
	int speed;
	bool timeTrial = false;

public:

	board(int s = 15) {	/*constructor*/
		size = s;
		shapes_Array = new shape**[15]; 
		board_Array = new int*[15];
		for (int i = 0; i < 15; i++) {
			shapes_Array[i] = new shape*[15];
			board_Array[i] = new int[15];
		}
		level = 1;
		time = 120;
		target = 500;
		progressBar = 0;
		paused = false;
		score = 0;
	}

	/*some setter/getters*/

	int getMouseX() {
		return mouse_X;
	}

	int getMouseY() {
		return mouse_Y;
	}

	void setMouseX(int x) {
		mouse_X = x;
	}

	void setMouseY(int y) {
		mouse_Y = y;
	}

	int getScore() {
		return score;
	}

	int getTime() {
		return time;
	}

	void setTime(int x) {
		time = x;
	}

	int getState() {
		return state;
	}

	void setName() {
		string name;
		cout << "Enter name: ";
		cin >> name;
		playerName = name;
	}

	bool isPaused() {
		return paused;
	}

	void pauseGame() {
		paused = !paused;
	}

	bool isTimeTrial() {
		return timeTrial;
	}

	void setState() {
		if (mouse_X > 240 && mouse_X < 360 && mouse_Y < (600-315) && mouse_Y > (600-335))
			state = -1;
		else if (mouse_X > 240 && mouse_X < 362 && mouse_Y < (600-285) && mouse_Y > (600-315))
			loadGame();
		else if (mouse_X > 240 && mouse_X < 364 && mouse_Y < (600-255) && mouse_Y > (600-285))
			state = 2;
		mouse_X = 0; mouse_Y = 0;
	}

	void gameMode() {
		if (mouse_X > 240 && mouse_X < 360 && mouse_Y < (600-315) && mouse_Y > (600-335))
		{
			//cout << "1" << endl;
			timeTrial = true;
			progressBar = 50;
			state = 1;
		}

		else if (mouse_X > 240 && mouse_X < 362 && mouse_Y < (600-285) && mouse_Y > (600-315))
		{
			//cout << "2" << endl;	
			state = 1;
			timeTrial = false;
		}

	}

	void goBack(){
		if (mouse_X > 50 && mouse_X < 100 && mouse_Y < (600-50) && mouse_Y > (600-80))
		{
			//cout << "1" << endl;
			state = 0;
		}
	}

	void initialiseBoard() {	/*initialises values on board when game starts*/
		int temp = 0;
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				temp = rand()%6;
				board_Array[i][j] = temp;
			}
		}
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {
				while (board_Array[i][j] == board_Array[i][j+1] && board_Array[i][j] == board_Array[i][j+2])
					board_Array[i][j+1] = rand()%6;
				while (board_Array[i][j] == board_Array[i+1][j] && board_Array[i][j] == board_Array[i+2][j])
					board_Array[i+1][j] = rand()%6;
			}
		}
	}

	void display() {	/*display function*/
		if (timeTrial) {
			if (progressBar <= 0)
				DrawString(260,300,"You lose", colors[WHITE]);
			else
				displayStage();
				displayShapes();
		}
		else if (time > 0 && score < target) {
			displayStage();
			displayShapes();
		}
		else {
			DrawSquare(0,0,600,colors[BLACK]);
			if (score < target)
				DrawString(260,300,"You lose", colors[WHITE]);
			else
				if(timeTrial == false)
					levelUp();
		}
	}

	void displayShapes() {	/*displays shapes*/
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				switch (board_Array[i][j]) {
					case 0: shapes_Array[i][j] = new circle(i*25 + 120,j*25 + 120,10,colors[HOT_PINK]);
							break;
					case 1: shapes_Array[i][j] = new square(i*25 + 110, j*25 + 110,20,colors[OLIVE]);
							break;
					case 2: shapes_Array[i][j] = new triangle(i*25 + 110, i*25 + 120, i*25 + 130,j*25 + 110, j*25 + 130, j*25 + 110,colors[MAROON]);
							break;
					case 3: shapes_Array[i][j] = new circle(i*25 + 120,j*25 + 120,10,colors[MIDNIGHT_BLUE]);
							break;
					case 4: shapes_Array[i][j] = new square(i*25 + 110, j*25 + 110,20,colors[DARK_MAGENTA]);
							break;
					case 5: shapes_Array[i][j] = new triangle(i*25 + 110, i*25 + 120, i*25 + 130,j*25 + 110, j*25 + 130, j*25 + 110,colors[STEEL_BLUE]);
							break;
				}
				shapes_Array[i][j]->createShape();
			}
		}
	}

	void displayStage() {	/*displays score, level, target and progress bar*/
		DrawSquare(0,0,600,colors[BLACK]);
		DrawSquare(102,102,385,colors[PALE_GREEN]);
		DrawString(480,560, "Score: ", colors[WHITE]);
		DrawString(260,560, "Level: ", colors[WHITE]);
		if (!timeTrial) {
			DrawString(245,60, "Target: ", colors[WHITE]);
			DrawString(320,60,to_string(target),colors[WHITE]);
		}
		DrawString(321,560,to_string(level),colors[WHITE]);
		DrawString(545,560,to_string(getScore()),colors[WHITE]);
		for (int i = 0; i < 100; i++) {
			if (i <= progressBar)
				DrawSquare(i+250,35,2,colors[RED]);
			else
				DrawSquare(i+250,35,2,colors[PALE_GREEN]);
		}
		if (timeTrial == true)
		{
			speed++;
			if (speed == 20) {
				speed = 0;
				progressBar--;
			}
		}
	}

	void displayMenu() {	/*displays menu*/
		DrawSquare(0,0,600,colors[LIGHT_SKY_BLUE]);
		DrawString(240,320,"New Game",colors[RED]);
		DrawString(240,290,"Load Game", colors[RED]); 
		DrawString(240,260,"Instructions",colors[RED]);
	}

	void displayGameTypeMenu() { /* asks if trial mode or normal mode */
		DrawSquare(0,0,600,colors[LIGHT_SKY_BLUE]);
		DrawString(240,320,"Time Trial Mode",colors[RED]);
		DrawString(240,290,"Normal Game Mode", colors[RED]);
	}

	void displayInstructions() {	/*displays instructions*/
		DrawSquare(0,0,600,colors[LIGHT_SKY_BLUE]);
		DrawString(180,600-80,"Instructions:", colors[RED]);
		DrawString(180,600-110,"1. Click and drag a shape", colors[RED]);
		DrawString(180,600-140,"in a direction up, down", colors[RED]);
		DrawString(180,600-170,"left, or right in order", colors[RED]);
		DrawString(180,600-200,"to make combos of 3, 4 or 5", colors[RED]);
		DrawString(180,600-230,"same types of shapes.", colors[RED]);
		DrawString(180,600-260,"2. Reach the target before", colors[RED]);
		DrawString(180,600-290,"the timer runs out.", colors[RED]);
		DrawString(180,600-320,"3. Time decreases per level.", colors[RED]);
		DrawString(180,600-350,"4. Good Luck!", colors[RED]);
		DrawString(50,50,"<- Back",colors[WHITE]);		

		if (mouse_X > 50 && mouse_X < 110 && mouse_Y > (600-75) && mouse_Y < (600-50))
			state = 0;
	}

	void saveGame() {	/*saves game*/
		cout << "Saving game..." << endl;
		ofstream file;
		string fileName = playerName;
		fileName = fileName + ".txt";
		file.open(fileName);
		for (int i = 0; i < 15; i++)
			for (int j = 0; j < 15; j++)
				file << board_Array[i][j] << " ";
		file << score << " ";
		file << level << " ";
		file << time << " ";
		file << progressBar << " ";
		if (timeTrial == false)
			file << 1;
		else
			file << 0;

		file.close();
	}

	void loadGame() {	/*loads game*/
		ifstream file;
		string fileName = playerName;
		fileName = fileName + ".txt";
		file.open(fileName);
		string value;
		while (!file.eof()) {
			string x;
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 15; j++) {
					getline(file,value,' ');
					board_Array[i][j] = stoi(value);
				}
			}
			getline(file,x,' ');
			score = stoi(x);
			getline(file,x,' ');
			level = stoi(x);
			getline(file,x,' ');
			time = stoi(x);
			getline(file,x,' ');
			progressBar = stoi(x);
			getline(file,x,' ');
			if (x == "0")
				timeTrial = true;
		}
		file.close();
		state = 1;
	}

	bool targetReached() {	/*returns true(1) if target reached, otherwise false(0)*/
		if (score >= target)
			return true;
		return false;
	}

	void levelUp() {	/*function is called when target reached; increases the level and difficulty*/
		level++;
		score = 0;
		time = 120-(level*10);
		progressBar = 0;
		initialiseBoard();
		display();
	}

	double calcDistance(int x1, int y1, int x2, int y2) {	/*utility function to calculate distance*/
		x1 = pow(abs(x1 - x2),2);
		y1 = pow(abs(y1 - y2),2);
		return sqrt(x1 + y1);
	}

	int * checkShape(int x,int y) {	/*checks which shape was clicked*/
		y = 600 - y;
		int * coordinates = new int[2];
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (x > (i*25+110) && x < (i*25+110)+25 && y > (j*25+110) && y < (y*25+110)+25) {
					coordinates[0] = i;
					coordinates[1] = j;
				}
			}
		}
		return coordinates;
	}

	void checkCombos() {	/*checks which combo (3,4 or 5) was made and increases score accordingly*/
		int count = 1;
		int point = 0;
		int num;
		bool row;
		while (count != 0) {
			count = 0;
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 15; j++) {
					num = 0;
					if (combo5(i,j) != -1) {
						num = 5;
						if (combo5(i,j) == 1)
							row = false;
						else
							row = true;
					}
					else if (combo4(i,j) != -1) {
						num = 4;
						if (combo4(i,j) == 1)
							row = false;
						else 
							row = true;
					}
					else if (combo3(i,j) != -1) {
						num = 3;
						if (combo3(i,j) == 1)
							row = false;
						else
							row = true;
					}
					if (num > 0) {
						if (row)
							for (int k = 0; k < num; k++)
								board_Array[i+k][j] = -1;
						else
							for (int k = 0; k < num; k++)
								board_Array[i][j+k] = -1;
						point += num;
						count++;
					}
				}
			}
			score = score + (point*count);
			if(timeTrial == true) { 
				progressBar += (point*count)/2;
				if (progressBar > 100)
					progressBar = 100;
			}
			else
				progressBar = score/5
			fillSpaces();
		}
	}

	void fillSpaces() {		/*fills the empty spaces which were made after a combo was made*/
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				while(board_Array[i][j] == -1) {
					for (int k = j; k < 14; k++)
						board_Array[i][k] = board_Array[i][k+1];
					board_Array[i][14] = rand()%6;
				}
			}
		}
	}

	int combo5(int i, int j) {	/*check for combo of 5 shapes*/
		if (j < 11)
			if (board_Array[i][j] == board_Array[i][j+1] 
				&& board_Array[i][j] == board_Array[i][j+2]
				&& board_Array[i][j] == board_Array[i][j+3] 
				&& board_Array[i][j] == board_Array[i][j+4])
				return 1;
		if (i < 11)	
			if (board_Array[i][j] == board_Array[i+1][j] 
				&& board_Array[i][j] == board_Array[i+2][j]
				&& board_Array[i][j] == board_Array[i+3][j] 
				&& board_Array[i][j] == board_Array[i+4][j])
				return 0;
		return -1;
	}

	int combo4(int i, int j) {	/*check for combo of 4 shapes*/
		if (j < 12)
			if (board_Array[i][j] == board_Array[i][j+1] 
				&& board_Array[i][j] == board_Array[i][j+2]
				&& board_Array[i][j] == board_Array[i][j+3])
				return 1;
		if (i < 12)
			if (board_Array[i][j] == board_Array[i+1][j] 
				&& board_Array[i][j] == board_Array[i+2][j]
				&& board_Array[i][j] == board_Array[i+3][j])
				return 0;
		return -1;
	}

	int combo3(int i, int j) {	/*check for combo of 3 shapes*/
		if (j < 13)
			if (board_Array[i][j] == board_Array[i][j+1] && board_Array[i][j] == board_Array[i][j+2])
				return 1;
		if (i < 13)
			if (board_Array[i][j] == board_Array[i+1][j] && board_Array[i][j] == board_Array[i+2][j])
				return 0;
		return -1;
	}

	template <class type>
	void swapValues(type &val1, type &val2) {	/*generic utility function to swap two values*/
		type temp;
		temp = val1;
		val1 = val2;
		val2 = temp;
	}

	void swapShapes(int direction) {	/*swaps clicked shape with the shape in 'direction'*/
		int * RowColValues;
		if (mouse_X >= 110 && mouse_X <= 600-102 && mouse_Y >= 110 && mouse_Y <= 600-102) {
			RowColValues = checkShape(mouse_X,mouse_Y); 
			int row = RowColValues[0];
			int col = RowColValues[1];
			int temp = 0;
			bool flag = false;
			if (direction == 3) {
				if (row != 14) {
					swapValues(board_Array[row][col], board_Array[row+1][col]);
					for (int i = 0; i < 15; i++)
						for (int j = 0; j < 15; j++)
							if (combo5(i,j) != -1 || combo4(i,j) != -1 || combo3(i,j) != -1)
								flag = true;
					if (flag == false)
						swapValues(board_Array[row][col], board_Array[row+1][col]);
				}
			}
			else if (direction == 1) {
				if (row != 0) {
					swapValues(board_Array[row][col], board_Array[row-1][col]);
					for (int i = 0; i < 15; i++)
						for (int j = 0; j < 15; j++)
							if (combo5(i,j) != -1 || combo4(i,j) != -1 || combo3(i,j) != -1)
								flag = true;
					if (flag == false)
						swapValues(board_Array[row][col], board_Array[row-1][col]);
				}
			}
			else if (direction == 4) {
				if (col != 0) {
					swapValues(board_Array[row][col], board_Array[row][col-1]);
					for (int i = 0; i < 15; i++)
						for (int j = 0; j < 15; j++)
							if (combo5(i,j) != -1 || combo4(i,j) != -1 || combo3(i,j) != -1)
								flag = true;
					if (flag == false)
						swapValues(board_Array[row][col], board_Array[row][col-1]);
				}
			}
			else if (direction == 2) {
				if (col != 14) {
					swapValues(board_Array[row][col], board_Array[row][col+1]);
					for (int i = 0; i < 15; i++)
						for (int j = 0; j < 15; j++)
							if (combo5(i,j) != -1 || combo4(i,j) != -1 || combo3(i,j) != -1)
								flag = true;
					if (flag == false)
						swapValues(board_Array[row][col], board_Array[row][col+1]);
				}
			}

			checkCombos();
		}
	}
};