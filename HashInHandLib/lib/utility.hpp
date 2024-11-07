#pragma once
#ifndef HIH_UTILITY_H
#define HIH_UTILITY_H
#include "hih/type.h"
#include "hih/result.h"
#include <fstream>

namespace hih
{
	namespace utility
	{

		/// <summary>Read file into memory.</summary>
		/// <param name='source'>[IN] A path to source file to read.</param>
		/// <param name='storage'>[OUT] A file_t container to store file content in it.</param>
		/// <returns>Returns task state</returns>
		[[nodiscard]] state read(fs::path source, file_t& buffer)
		{
			std::error_code ec;
			if (!fs::exists(source, ec))
			{
				return state::FileNotExists;
			}

			if (!fs::is_regular_file(source, ec))
			{
				return state::BadContent;
			}

			// open the file:
			std::ifstream file(source, std::ios_base::binary | std::ios_base::in);
			file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
			if (!file.good()) {
				return state::FileOpenFailed;
			}

			// read the data:
			buffer.resize(static_cast<size_t>(fs::file_size(source)));

			file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

			return state::Successful;
		}
	} // Utility
} // hih

#endif //HIH_UTILITY_H