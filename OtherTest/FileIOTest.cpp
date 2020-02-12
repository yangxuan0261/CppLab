#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>


namespace FileIOTest
{
    


void testFileOut()
{

	std::string content("");
	for (size_t i = 0; i < 5; i++)
	{
		content.append("------ test content\n");
	}
	content.append("\n");
	std::ofstream outFile("log.lua", std::ios::app);
	if (outFile.is_open())
	{
		outFile << content;
	}
	outFile.close();
}

void main()
{
	testFileOut();
}

} // FileIOTest
