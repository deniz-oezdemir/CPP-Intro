#include <iostream>
#include <string>
#include <fstream>

void replace(std::string &content, const std::string &s1, const std::string &s2) {
	std::string tmp;
	size_t position = content.find(s1, 0);
	while (position != std::string::npos){
		tmp = content.substr(0, position);
		tmp += s2;
		tmp += content.substr(position + s1.length());
		content = tmp;
		position += s2.length();
		position = content.find(s1, position);
	}
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Error: " << av[0] << " file s1 s2 expected" << std::endl;
		return 1;
	}
	if (std::string(av[1]) == "" || std::string(av[2]) == "") {
		std::cerr << "Error: nothing to replace" << std::endl;
		return 1;
	}
	std::string name_outfile = std::string(av[1]) + ".replace";
	std::ifstream infile(av[1]);
	if (!infile) {
		std::cerr << "Error: can not open infile" << std::endl;
		return 1;
	}
	std::ofstream outfile(name_outfile);
	if (!outfile) {
		std::cerr << "Error: can not open outfile" << std::endl;
		return 1;
	}
	//read all characters from infile and store them in content
	std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	replace(content, av[2], av[3]);
	outfile << content;
	infile.close();
	outfile.close();
	return 0;
}
