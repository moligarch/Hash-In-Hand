#pragma once

#ifndef HIH_SHA256_H
#define HIH_SHA256_H

#include "hih/result.h"
#include "hih/type.h"

namespace hih {
	namespace sha {
		state get_file_sha256(const fs::path& source, std::string& hash);
	}

	namespace utility
	{
		
	}
}


#endif //HIH_SHA256_H