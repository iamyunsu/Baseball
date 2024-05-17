#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {

	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		GuessResult result = { 0, 0, false };
		result.solved = matchAll(guessNumber);
		result.strikes = matchStrike(guessNumber);
		result.balls = matchBall(guessNumber);

		return result;	
	}
	int matchBall(const std::string& guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (guessNumber[i] == question[j]) {
					result++;
				}
			}
		}
		return result;
	}
	int matchStrike(const std::string& guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) {
				result++;
			}
		}
		return result;
	}
	bool matchAll(const std::string& guessNumber)
	{
		if (guessNumber == question) {
			return true;
		}
		return false;
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}
		for (char number : guessNumber) {
			if (number >= '0' && number <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
private:
	string question;
};

