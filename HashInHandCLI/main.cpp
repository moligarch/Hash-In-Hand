// HashInHandCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <hih.h>

#include <iostream>
#include <string>

int main()
{
    int option{ 0 };
	std::string args;

	do {
		std::cout << "\nSelect Your desired option:"
			"\n================================"
			"\n1. Calculate SHA256 hash of file."
			"\n0. Exit."
			"\n================================\n"
			"Option: ";

		std::cin >> option;
		system("cls");
		switch (option)
		{
		case 0:
		{
			std::cout << "================================"
				"\n    Hope to see you again!"
				"\n================================\n\n";
			break;
		}
		case 1:
		{
			std::cout << "Enter file path: ";
			std::getline(std::cin, args);
			std::getline(std::cin, args);
			fs::path src{ args };
			std::string hash;

			auto state = hih::sha::get_file_sha256(src, hash);

			std::cout << std::setw(20) << std::left << "\n  Source File:" << src.string();
			std::cout << std::setw(20) << std::left << "\n  Algorithm:" << "SHA256";
			if (state == hih::state::Successful)
				std::cout << std::setw(20) << std::left << "\n  Hash:" << hash << "\n\n";
			else
				std::cout << std::setw(20) << std::left << "\n  Status:" << static_cast<int>(state) << "\n\n";

			break;
		}
		default:
		{
			std::cout << "Wrong input. Try again!";
			break;
		}
		};
	} while (option);
	return 0;
}