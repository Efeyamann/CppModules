#include <iostream>

int main(int argc, char **argv)
{
	int i = 1;
	int j;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
		if(argv[i] != NULL)
			std::cout << " ";
	}
	std::cout << std::endl;
}