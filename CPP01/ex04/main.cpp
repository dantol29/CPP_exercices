#include <string>
#include <iostream>
#include <fstream>
#include <string.h>

std::string getString(char **argv, std::ifstream& file)
{
	std::string	text;
	std::string	fileText;
	int			index;
	int			skip;

	while (std::getline(file, text))
		fileText.append(text).append("\n");
	if (fileText.find(argv[2]) == std::string::npos)
		return ("");
	skip = 0;
	while (1){
		index = fileText.find(argv[2], skip);
		if (index == std::string::npos)
			break ;
		else{
			int	i = index;
			int	j = 0;
			while (fileText[i] && fileText[i] == argv[2][j++])
				i++;
			fileText.erase(index, i - index);
			fileText.insert(index, argv[3], strlen(argv[3]));
			skip = index + strlen(argv[3]);
		}
	}
	return (fileText);
}

int replaceFile(std::string filename, std::ifstream& file, char **argv)
{
	std::string	fileText;

	fileText = getString(argv, file);
	if (fileText.empty()){
		std::cout << "No matches found!" << std::endl;
		return (1);
	}
	filename = filename + ".replace";
	std::ofstream outputFile(filename.c_str());
	if (!outputFile.is_open())
	{
		std::cout << "Could not create a file!" << std::endl;
		return (1);
	}
	outputFile << fileText;
	return (0);
}

int main(int argc, char **argv)
{
	std::string filename;
	int			status;

	if (argc != 4)
	{
		std::cout << "Only 3 arguments allowed" << std::endl;
		return (1);
	}
	filename = argv[1];
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "File does not exist!" << std::endl;
		return (1);
	}
	status = replaceFile(filename, file, argv);
	if (status == 0)
		std::cout << "Success!" << std::endl;
	return (status);
}