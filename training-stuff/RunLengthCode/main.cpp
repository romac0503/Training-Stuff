// RunLengthCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <assert.h>
#include <fstream>
#include <cctype>
#include "MyExceptionClass.h"
#include "InvalidCommandLineException.h"
#include "InvalidFormatException.h"

using namespace std;

void printMsg(string newMsg)
{
	cout << newMsg << endl;
}

string compress(string msg)
{
	assert(msg == "");

	string newMsg;
	int count = 1;
	int amountSameChars = 0;
	int amountMaxMultiplier = 0;
	int restChars = 0;
	unsigned int length = msg.length();

	char c;
	std::string tmpMsg;

	for (unsigned i = 0; i < length; i++)
	{
		c = msg[i];

		if (c == msg[i + 1])
		{
			count++;
		}
		else
		{
			amountMaxMultiplier = count / 9;
			restChars = count - (amountMaxMultiplier * 9);
			count = 1;
		}

		if (amountMaxMultiplier != 0)
		{
			if (amountMaxMultiplier > 0)
			{
				tmpMsg += c;
				tmpMsg += to_string(9);
				amountMaxMultiplier--;
			}
		}

		if (restChars != 0)
		{
			if (restChars < 3)
			{
				for (int z = 0; z < restChars; z++)
				{
					tmpMsg += c;
				}
			}
			else
			{
				tmpMsg += c;
				tmpMsg += to_string(restChars);
			}
			restChars = 0;
		}
	}

	newMsg = tmpMsg;
	return newMsg;
}

string decompress(string msg)
{
	assert(msg != "");
	string newMsg;

	if (newMsg.length() != 0)
	{
		newMsg = "";
	}

	char c;
	char temp;

	if (msg.length() >= 2)
	{
		temp = msg.at(0);

		for (int i = 1; i < msg.length(); i++)
		{
			c = msg.at(i);

			if (temp != c)
			{
				if (isdigit(c))
				{
					int count = c - '0';
					for (int j = 0; j < count; j++)
					{
						newMsg += temp;
					}
				}
				else if (!isdigit(temp))
				{
					newMsg += temp;
				}
				if (!isdigit(c) && i == msg.length() - 1)
				{
					newMsg += c;
				}
				temp = c;
			}
			else
			{
				if (!isdigit(c))
				{
					newMsg += c;
				}
			}
		}
		if (!isdigit(msg.at(msg.length() - 1)))
		{
			newMsg += msg.at(msg.length() - 1);
		}
	}
	return newMsg;
}

bool testIfSame(string msg1, string msg2)
{
	assert(msg1 != "" && msg2 != "");

	if (msg1.compare(msg2))
	{
		return true;
	}
	return false;
}



int main(int argc, char* argv[])
{
	string s = "shrink";
	string comp = "-c";
	string decomp = "-d";
	MyExceptionClass* exc;

	string def = "";
	string opt = "";
	string msg = "";

	if (argc < 4)
	{
		do
		{
			cerr << "not enough parameters" << endl;
			cout << "write the right definition(shrink) and option(-c/-d) with your message!" << endl;
			cin.get();
		} while (argc < 4);
	}

	def = argv[1];
	opt = argv[2];
	msg = argv[3];

	try
	{
		if (argc < 4)
		{
			exc = new InvalidCommandLineException("too less parameters! Please write shrink then option(-c/-d) and your message.");
			throw exc;
		}

		if (def != s)
		{
			exc = new InvalidCommandLineException("write the right definition(shrink) and option(-c/-d) with your message!");
			throw exc;
		}

		if (opt != comp && opt != decomp)
		{
			exc = new InvalidFormatException("wrong option! Please check if you wrote -c for compressing or -d for decompressing your message.");
			throw exc;
		}
	}
	catch (exception& e)
	{
		cout << "some Exception occured: \t" << e.what() << endl;
	}

	if (def == s)
	{
		if (opt == "-c")
		{
			
			string testCompMsg = compress(msg);
			string testDecompMsg = decompress(testCompMsg);

			bool passed = testIfSame(testCompMsg, testDecompMsg);

			if (passed)
			{
				cout << "your original message was: \t" << testDecompMsg << endl;
				cout << endl;
				cout << "your compressed message is: \t" << testCompMsg << endl;
			}
			
		}
		else
		{
			string testDecompMsg = decompress(msg);
			string testCompMsg = compress(testDecompMsg);

			bool passed = testIfSame(testCompMsg, testDecompMsg);

			if (passed)
			{
				cout << "your original message was: \t" << testCompMsg << endl;
				cout << endl;
				cout << "your decompressed message is: \t" << testDecompMsg << endl;
			}
		}
	}



	/*ofstream myfile("compressed.txt");
	if (myfile.is_open())
	{
	myfile << newMsg;
	myfile.close();
	}
	else cout << "Unable to open file";*/

	cin.get();

	return 0;
}

