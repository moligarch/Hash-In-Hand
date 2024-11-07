#pragma once

#ifndef HIH_TYPE_H
#define HIH_TYPE_H
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace hih {

	enum class type
	{
		SHA256
	};
	
	
	using file_t = std::vector<unsigned char>;
}

#endif //HIH_TYPE_H