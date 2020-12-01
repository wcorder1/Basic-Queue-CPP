// Test driver
#include <iostream>
using namespace std;
#include <fstream>
#include <string>

#include "QueType.cpp"


void help()
{
	std::cout << "enqueue value: Enqueue a value at the end of the Queue\ndequeue: Remove the most urgent item \npeek: Peeks at the first item without removing it\nclear: Clears the queue.\nisempty: Reports whether the queue is empyty\n\nisfull: Reports whether the queue is full\nlist: Reports the items in the queue, in the order they will be processed\nhelp: Prints this message\n";
}
int main()
{

	ofstream outFile;
	ifstream inFile;
	string command;

	outFile.open("outFile.txt");
	inFile.open("inFile.txt");
	if(!outFile)
	{
		std::cout << "error openning output file" << endl;
		return 1;
	}
  int item;
  QueType<int> queue(5);
  int numCommands=0;
  //std::cout << "Enter a command:\n";
  help();
  while (true)
  {
	  
	  inFile >> command;

    try 
   {
		if (command == "enqueue")
		{
			inFile >> item;
			queue.enqueue(item);
			outFile << item << " is enqueued." << endl;
		}
		else if (command == "dequeue")
		{
			queue.dequeue(item);
			outFile << item << " is dequeued. " << endl;
		}
		else if (command == "isempty")
		{
			if (queue.isEmpty())
				outFile << "Queue is Empty\n";
			else
				outFile << "Queue is Not Empty\n";
		}
		else if (command == "isfull")
			if (queue.isFull())
				outFile << "Queue is full." << endl;
			else outFile << "Queue is not full." << endl;
		else if (command == "length")
			outFile << "Number of items in the Queue is: " << queue.length() << endl;
		else if (command == "clear")
				queue.makeEmpty();
		else if (command == "list")
					queue.printQueue(outFile);
		else if (command == "peek") {
					int x= queue.peek();
					outFile << "Item at the front of the queue is " << x << endl;
					}
		else if (command == "help")
		     	help();
		else if (command == "quit")
			break;
		else outFile << " Invalid Command" << endl;
    }
  catch (QueueOverflow)
   {
	  outFile << "Queue Overflow, exception thrown!" << endl;
   }
    
    catch (QueueUnderflow)
   {
		outFile << "Queue Underflow, exception thrown!" << endl;
    } 
    numCommands++;
	cout <<  " Command number " << numCommands << " completed."
         << endl;
	
  }
 
  cout << "Testing completed."  << endl;
  outFile.close();
  return 0;
}


