#define ToggleBit(val, bitIndex) val ^= (1 << bitIndex)
#define IsBitSet(val, bitIndex) (val & (1 << bitIndex))
#define ClearBit(val, bitIndex) val &= ~(1 << bitIndex)

class Solution {
public:
	bool isValidSudoku(std::vector<std::vector<char>>& board)
	{
		//Index of Which board number we are processing
		// 0 1 2
		// 3 4 5 
		// 6 7 8
		int boardIndex = 0;

		//local coordinate space indices into the localized 3x3 grid
		int subGridColumnIndex;
		int subGridRowIndex;
		int subGridIndex;

		//Hash set of prior digits found
		int priorValues;

		while (boardIndex < 9)
		{
			priorValues = 0;
			subGridIndex = 0;

			while (subGridIndex < 9)
			{
				//check row
				if (toggleIfNotSet(board[boardIndex][subGridIndex], priorValues, 0))
				{
					return false;
				}

				//check col
				if (toggleIfNotSet(board[subGridIndex][boardIndex], priorValues, 10))
				{
					return false;
				}

				//check subgrid
				subGridColumnIndex = (boardIndex % 3) * 3 + subGridIndex % 3;
				subGridRowIndex = (boardIndex / 3) * 3 + subGridIndex / 3;

				if (toggleIfNotSet(board[subGridRowIndex][subGridColumnIndex], priorValues, 19))
				{
					return false;
				}

				subGridIndex++;
			}

			boardIndex++;
		}

		return true;
	}

private:
	bool toggleIfNotSet(const char & gridCharacter, int & bitField, const int offset )
	{
		if (gridCharacter != '.')
		{
			int gridValue = gridCharacter - '0';
			if (IsBitSet(bitField, gridValue + offset))
			{
				return true;
			}
			else
			{
				ToggleBit(bitField, gridValue + offset);
			}
		}

		return false;
	}
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();