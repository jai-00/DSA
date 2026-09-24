#include <iostream>
#include <vector>

using namespace std;
bool canMove(char move, vector<vector<int>> &maze, int currRow, int currCol, vector<vector<bool>> &visited)
{
    switch (move)
    {
    case 'R':
        /* code */
        currCol++;
        break;
    case 'D':
        currRow++;
        break;
    case 'L':
        currCol--;
        break;
    case 'U':
        currRow--;
        break;
    default:
        break;
    }

    if (currRow >= maze.size() || currCol >= maze[0].size() || currRow < 0 || currCol < 0 || maze[currRow][currCol] == 0)
    {
        return false;
    }

    if (visited[currRow][currCol] == true)
    {
        return false;
    }

    return true;
}
void solveMaze(vector<vector<int>> &maze, int currRow, int currCol, vector<vector<bool>> &visited, vector<string> &ans, string solution)
{
    vector<char> moves = {'R', 'D', 'L', 'U'};
    if (currRow == maze.size() - 1 && currCol == maze[0].size() - 1)
    {
        ans.push_back(solution);
        return;
    }
    visited[currRow][currCol] = true;
    for (char move : moves)
    {

        if (canMove(move, maze, currRow, currCol, visited))
        {

            solution.push_back(move);

            if (move == 'R')
            {

                solveMaze(maze, currRow, currCol + 1, visited, ans, solution);
            }
            else if (move == 'D')
            {

                solveMaze(maze, currRow + 1, currCol, visited, ans, solution);
            }
            else if (move == 'L')
            {

                solveMaze(maze, currRow, currCol - 1, visited, ans, solution);
            }
            else if (move == 'U')
            {

                solveMaze(maze, currRow - 1, currCol, visited, ans, solution);
            }

            solution.pop_back();
        }
    }
    visited[currRow][currCol] = false;
    return;
}
int main()
{
    // vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<vector<int>> maze = {
        {1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1}};
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<string> ans;
    string solution;
    cout << endl
         << "------------------------" << endl;

    for (vector<int> rows : maze)
    {
        for (int val : rows)
        {
            cout << val << "  ";
        }
        cout << endl;
    }
    cout
        << endl
        << "==================" << endl;
    solveMaze(maze, 0, 0, visited, ans, solution);
    for (string solution : ans)
    {
        cout << solution << " ";
    }
    cout << endl
         << "------------------------" << endl;

    return 0;
}