#include "pch.h"
#include <hih/sha256.h>

namespace UnitTest {

	class TestAlgorithmSHA : public ::testing::Test
	{
	protected:
		fs::path test_path{ "sha.txt" };
		std::string expected_sha256{ "2D8002F57D71618A1C485C72480622E57070E11FF2E9BB82159DAE1C9D8C8890" };
		virtual void SetUp()
		{
			std::ofstream tmp;
			tmp.open(test_path, std::ios::out);
			ASSERT_TRUE(tmp.good()) << "Unable to initiate test file";
			tmp << "asdajdajdsjadkjs;dksakdasfjfpafpa";
			tmp.close();
		}

		virtual void TearDown()
		{
			std::error_code ec;
			ASSERT_TRUE(fs::remove(test_path, ec)) << "Failed in test cleanup";
		}

	};


	TEST_F(TestAlgorithmSHA, FileHash)
	{
		std::string hash;
		auto state = hih::sha::get_file_sha256(hash, test_path);
		EXPECT_TRUE(state == hih::state::Successful);
		EXPECT_EQ(hash, expected_sha256);
	}
}