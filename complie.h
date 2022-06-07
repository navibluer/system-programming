#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "opTable.h"
using namespace std;

map<string, string> compile(string input)
{
	int flag = 0;	 // meet char?
	int count = 0; // word count
	string tmp = "";
	vector<string> instruction;

	// No label, Indent
	// if (input.front() == ' ' || input.front() == '\t')
	// 	input.insert(0, "***");

	for (int i = 0; i < input.length(); i++)
	{
		// Ignore Comment, \r for fucking windows
		if (input[i] == '.' || input[i] == '\n' || input[i] == '\r')
		{
			if (flag == 1)
			{
				instruction.push_back(tmp);
				tmp = "";
				flag = 0;
			}
			break;
		}
		// Ignore Witespace
		else if (input[i] == ' ' || input[i] == '\t')
		{
			if (flag == 1)
			{
				instruction.push_back(tmp);
				tmp = "";
				flag = 0;
			}
			continue;
		}
		else
		{
			// if previous is space, count ++
			if (flag == 0)
				count++;
			// Store Char
			flag = 1;
			tmp += input[i];
		}
	}

	// Store Last Word
	if (flag == 1)
		instruction.push_back(tmp);

	// Statement
	map<string, string> statement;
	statement["Label"] = "";
	statement["Mnemoic"] = "";
	statement["Operand"] = "";
	statement["Addressing"] = "";

	if (instruction.size() > 0)
	{
		string *front = &instruction.front();
		// No label
		if (opcode(*front) != -1 || *front == "END")
			instruction.insert(instruction.begin(), "***");
		// Assign Label, Mnemoic, Operand
		for (int i = 0; i < instruction.size(); i++)
		{
			switch (i)
			{
			case 0:
				if (instruction.at(i) != "***")
					statement["Label"] = instruction.at(i);
				break;
			case 1:
				statement["Mnemoic"] = instruction.at(i);
				break;
			case 2:
				statement["Operand"] = instruction.at(i);
				break;
			default:
				break;
			}
		}
	}
	// Check Operand, Addressing mode
	if (instruction.size() > 5)
	{
		// BYTE C content has space char
		if (statement["Mnemoic"] == "BYTE" && statement["Operand"].front() == 'C')
		{
			statement["Operand"] += instruction[3]; // first '
			// remaining content
			for (size_t i = 4; i < instruction.size(); i++)
			{
				statement["Operand"] += " " + instruction.at(i);
			}
			statement["Addressing"] = "Direct";
		}
		else
			throw "Invalid instruction syntax, possibly too long or wrong spaces.";
	}
	else if (instruction.size() > 3)
	{
		if (instruction[3] == "X") // Operand, X
		{
			statement["Addressing"] = "Index";
			statement["Operand"] += "X";
		}
		else if (instruction[3] == ",X") // Operand ,X
		{
			statement["Addressing"] = "Index";
			statement["Operand"] += ",X";
		}
		else if (instruction[3] == ",") // Operand , ?
		{
			statement["Addressing"] = "Index";
			statement["Operand"] += ", " + instruction.at(4);
		}
		else // BYTE, WORD
		{
			statement["Operand"] += instruction[3];
			statement["Addressing"] = "Direct";
		}
	}
	else if (instruction.size() > 2)
	{
		statement["Addressing"] = "Direct";
	}
	return statement;
}