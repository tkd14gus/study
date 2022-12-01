#include <iostream>
#include <vector>

using BYTE = unsigned char;

const BYTE question = '?';
const BYTE star = '*';

const int _MAX_SIZE = 50;

char memoization[_MAX_SIZE];


bool result_wild_card(const std::string& pattern, const size_t& pattern_pos, const std::string check_file_name, const size_t& file_name_pos)
{
	size_t question_pos = pattern.find(question, pattern_pos);
	size_t star_pos		= pattern.find(star, pattern_pos);

	if (question_pos == std::string::npos && star_pos == std::string::npos)
	{
		if (pattern.find(check_file_name, file_name_pos + 1) == std::string::npos)
			return false;

		return true;
	}
	else if (question_pos == std::string::npos || question_pos > star_pos)
	{
		//star가 나온 경우
		size_t temp_star_pos		= pattern.find(star, star_pos + 1);
		size_t temp_question_pos	= pattern.find(star, star_pos + 1);

		size_t check_pos			= temp_star_pos > temp_question_pos ? temp_question_pos : temp_star_pos;

		std::string sub_str			= pattern.substr(pattern_pos, check_pos - pattern_pos);

		size_t zero_check			= check_file_name.find(sub_str, file_name_pos);

		if (temp_star_pos < zero_check || temp_question_pos < zero_check || zero_check == std::string::npos)
			return false;

		return result_wild_card(pattern, pattern_pos + (check_pos - pattern_pos), check_file_name, zero_check + (check_pos - pattern_pos));
	}
	else if (star_pos == std::string::npos || star_pos > question_pos)
	{
		//question이 나온 경우
	}

	return false;
}

std::vector<std::string> wild_card(const int& count, const std::string& pattern, const std::vector<std::string>& file_name)
{
	std::vector<std::string> result;
	result.clear();



	return result;
}

int main()
{
	std::vector<std::string> _file_name1 = { "help", "heap", "helpp" };
	std::vector<std::string> answer1 = wild_card(3, "he?p", _file_name1);

	for (unsigned int i = 0; i < answer1.size(); i++)
		std::cout << answer1[i] << std::endl;

	return 0;
}