#include "run.h"

//Constructor
Run::Run() {}

//Destructor
Run::~Run() {}

void Run::runSim(){
	srand(time(0));
	
	int totalTime = 0;
	int userTime = 0;

	int expressNum = 0;
	int normalNum = 0;

	int expressArrival = randomNum(1);
	int normalArrival = randomNum(2);

	int expressEnter = 0;
	int normalEnter = 0;

	int expressDone = 0;
	int normalDone = 0;
	
	userTime = userChoice();

	while (userTime != totalTime) {
		
		if (expressArrival == expressDone) {
			expressNum++;

			enterLane(expressNum, totalTime, 1, express);
			expressArrival = randomNum(1);

			cout << express << endl;
			system("pause");
		}
		if (normalArrival == normalDone) {
			normalNum++;

			enterLane(normalNum, totalTime, 2, normal);
			normalArrival = randomNum(2);
		
			cout << normal << endl;
			system("pause");
		}
		
		totalTime++;
		expressArrival--;
		normalArrival--;
	}
}

int Run::userChoice() {
	int num;
	do
	{
		cout << "Grocery Line Simulator\n" << "Please enter a number (minutes) to run simulator for:" << " ";
		cin >> num;
		if (num < 0) {
			cout << "\nIncorrect Input. Try Again." << endl;
			system("pause");
			system("cls");
			num = -1;
		}
	} while (num < 0);

	return num;
}

int Run::randomNum(int num) {
	int rando = 0;
	if (num == 1) {
		rando = (rand() % 5) + 1;
	}
	else if (num == 2) {
		rando = (rand() % 8) + 3;
	}
	
	return rando;
}

void Run::enterLane(int num, int time, int type, Queue& info) {
	int service = 0;

	
	if (type == 1) {
		service = randomNum(type);
		info.enqueue(Data(num, service, time));
	}
	else if (type == 2) {

		service = randomNum(type);
		info.enqueue(Data(num, service, time));
	}
}

void Run::runTest() {
	Data data;

	express.enqueue(Data(1, 2, 3));
	express.enqueue(Data(4, 5, 6));

	if (!express.isEmpty()) {
		data = express.dequeue();
	}

	cout << data << endl;

	express.enqueue(Data(7, 8, 9));

	if (!express.isEmpty()) {
		data = express.dequeue();
	}

	cout << data << endl;

	if (!express.isEmpty()) {  // Perform another dequeue operation
		data = express.dequeue();
	}

	cout << data << endl;  // Should print Data(4, 5, 6), but it does not

}
