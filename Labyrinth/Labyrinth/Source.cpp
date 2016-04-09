#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

 void getMaze(string filename, vector<vector<int>> &mazeMap)
{	
	ifstream myMazeFile(filename);
	string line;
	int lineNum;
	
	if (myMazeFile.is_open())
		while (getline(myMazeFile, line))
		{
			vector<int> row;
			for (int i = 0; i < line.size(); i++)
				if (line[i] != ' ')
				{
					if (line[i] == '0')
						row.push_back(0);
					else if (line[i] == '1')
						row.push_back(1);
					else if (line[i] == '2')
						row.push_back(2);
					//lineNum = atoi(line[i]);
					//row.push_back(lineNum);
				}
			mazeMap.push_back(row);
		}
	myMazeFile.close();
}

void printMaze(vector<vector<int>> mazeMap)
{
	for (int i = 0; i < mazeMap.size(); i++)
	{
		for (int j = 0; j < mazeMap[i].size(); j++)
		{
			cout << mazeMap[i][j] << " ";
		}
		cout << endl;
	}

}

int main()
{
	string filename = "mazetest.txt";

	vector<vector<int>> mazeMap;

	getMaze(filename, mazeMap);
	printMaze(mazeMap);

	system("pause");

	return 0;
}