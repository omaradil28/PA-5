#include "run.h"

//Constructor
Run::Run() {}

//Destructor
Run::~Run() {}

void Run::runSim(){

	srand(time(0));
	
	int totalTime = 0;
	int userTime = 0;

	int custNum = 0;

	int expressArrival = randomNum(1);
	int normalArrival = randomNum(2);

	int expressEnter = 100;
	int normalEnter = 100;

	Data expressLeave;
	Data normalLeave;
	
	userTime = userChoice();

	while (userTime != totalTime) {
		
		if (expressArrival == 0) {
			custNum++;

			enterLane(custNum, totalTime, 1, express);
			expressArrival = randomNum(1);
			expressEnter = express.getHead()->getData().serviceGet();

			cout << "Customer:" << express << "Has Entered Express" << endl;
			system("pause");
		}
		if (normalArrival == 0) {
			custNum++;

			enterLane(custNum, totalTime, 2, normal);
			normalArrival = randomNum(2);
			normalEnter = normal.getHead()->getData().serviceGet();
		
			cout << "Customer:" << normal << "Has Entered Normal" << endl;
			system("pause");
		}

		if (expressEnter == 0) {
			if (!express.isEmpty())
			{
				expressLeave = express.dequeue();
				cout << expressLeave << "dequeued\n" << endl;
			}
		}
		if (normalEnter == 0) {
			if (!normal.isEmpty())
			{
				normalLeave = normal.dequeue();
				cout << normalLeave << "dequeued\n" << endl;
			}
		}
		
		totalTime++;
		expressArrival--;
		normalArrival--;
		expressEnter--;
		normalEnter--;
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
		rando = (rand() % 6) + 3;
	}
	
	return rando;
}

void Run::enterLane(int num, int time, int type, Queue& info) {
	int service = 0;

	//Skips over these below lines for some reason a
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

	express.enqueue(Data(1, 2, 3)); // Front of queue
	express.enqueue(Data(4, 5, 6)); // Back of queue

	express.printQueue(express); // Should print 1,2,3

	if (!express.isEmpty()) {
		data = express.dequeue(); // Should dequeue 1,2,3 since its the front. Now 4,5,6 should be front of queue.
	}

	express.printQueue(express); // Should print front of queue AKA 4,5,6, but it doesnt.
}
