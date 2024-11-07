#include "pch.h"
#include "hih/sha256.h"
#include "hih/type.h"
#include "hih/result.h"
#include "utility.hpp"

#include <openssl/sha.h>

namespace hih {
	namespace sha {
		hih::state get_file_sha256(std::string& hash, const fs::path& source)
		{
            hih::file_t buffer{};
            auto state = hih::utility::read(source, buffer);
            if (state != state::Successful)
            {
                return state;
            }

            unsigned char hash_data[SHA256_DIGEST_LENGTH];
            auto data = const_cast<const unsigned char*>(buffer.data());
            SHA256(data, buffer.size(), hash_data);

            std::stringstream ss;
            for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
            {
                ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash_data[i]);
            }

            hash = ss.str();
			std::transform(hash.begin(), hash.end(), hash.begin(),
				[](unsigned char c) { return ::toupper(static_cast<char>(c)); });

			return state::Successful;
		}
	} // sha

	namespace utility
	{
		
	} // utility
} // hih