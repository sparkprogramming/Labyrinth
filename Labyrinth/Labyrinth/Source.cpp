#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdio.h>

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

vector<int> findPlayer(vector<vector<int>> mazeMap)
{
	vector<int> pos;
	int row;
	int col;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (mazeMap[i][j] == 2)
			{
				row = i;
				col = j;
				break;
			}
		}

	pos.push_back(row);
	pos.push_back(col);

	return pos;
}

void moveUp(vector<vector<int>> &mazeMap, vector<int> pos)
{
	if (pos[0] != 0)
	{
		if (mazeMap[pos[0] - 1][pos[1]] == 0)
		{
			mazeMap[pos[0] - 1][pos[1]] = 2;
			mazeMap[pos[0]][pos[1]] = 0;

			system("CLS");
			printMaze(mazeMap);
		}
	}
}

void moveLeft(vector<vector<int>> &mazeMap, vector<int> pos)
{
	if (pos[1] != 0)
	{
		if (mazeMap[pos[0]][pos[1] - 1] == 0)
		{
			mazeMap[pos[0]][pos[1] - 1] = 2;
			mazeMap[pos[0]][pos[1]] = 0;

			system("CLS");
			printMaze(mazeMap);
		}
	}
}

void moveDown(vector<vector<int>> &mazeMap, vector<int> pos)
{
	if (pos[0] != 9)
	{
		if (mazeMap[pos[0] + 1][pos[1]] == 0)
		{
			mazeMap[pos[0] + 1][pos[1]] = 2;
			mazeMap[pos[0]][pos[1]] = 0;

			system("CLS");
			printMaze(mazeMap);
		}
	}
}

void moveRight(vector<vector<int>> &mazeMap, vector<int> pos)
{
	if (pos[1] != 9)
	{
		if (mazeMap[pos[0]][pos[1] + 1] == 0)
		{
			mazeMap[pos[0]][pos[1] + 1] = 2;
			mazeMap[pos[0]][pos[1]] = 0;

			system("CLS");
			printMaze(mazeMap);
		}
	}
}


int main()
{
	string filename = "mazetest.txt";

	vector<vector<int>> mazeMap;

	vector<int> playerPos;

	getMaze(filename, mazeMap);
	printMaze(mazeMap);

	playerPos = findPlayer(mazeMap);

	char direction = _getch();
	while (direction != 'q')
	{
		if (direction == 'w')
		{
			moveUp(mazeMap, findPlayer(mazeMap));
		}
		else if (direction == 'a')
		{
			moveLeft(mazeMap, findPlayer(mazeMap));
		}
		else if (direction == 's')
		{
			moveDown(mazeMap, findPlayer(mazeMap));
		}
		else if (direction == 'd')
		{
			moveRight(mazeMap, findPlayer(mazeMap));
		}

		direction = _getch();
	}


	return 0;
}