#include <iostream>

using std::cout;

#define WIDTH 11 //желаемое значение +1
#define HEIGHT 7

void lookAround(int **map, int currentX, int currentY)
{

  if (map[currentY][currentX] == 1)
  {
    map[currentY][currentX] = 0;
    lookAround(map, currentX + 1, currentY);
    lookAround(map, currentX - 1, currentY);
    lookAround(map, currentX, currentY + 1);
    lookAround(map, currentX, currentY - 1);
  }
}

int main()
{

  cout << "Map is generating..."
       << "\n";
  int **map = new int *[HEIGHT];

  for (int i = 0; i < HEIGHT; ++i)
  {
    map[i] = new int[WIDTH];
  }

  std::srand(time(NULL));
  bool isEdge = false;
  for (int i = 0; i < HEIGHT; ++i)
  {
    for (int j = 0; j < WIDTH; ++j)
    {
      isEdge = (i == 0) || (j == WIDTH - 1) || (j == 0) || (i == HEIGHT - 1);
      isEdge == 1 ? map[i][j] = 0 : map[i][j] = std::rand() % 2;
      cout << map[i][j];
    }
    cout << "\n";
  }

  bool isLand = 0;
  bool isLandAround = 0;
  int countEdge = 0;

  for (int i = 1; i < HEIGHT; ++i)
  {
    for (int j = 1; j < WIDTH; ++j)
    {
      if (map[i][j] == 1)
      {
        cout << "Found land" << std::endl;
        countEdge += 1;
        lookAround(map, j, i);
        for (int k = 0; k < HEIGHT; ++k)
        {
          for (int l = 0; l < WIDTH; ++l)
          {
            cout << map[k][l];
          }
          cout << std::endl;
        }
      }
    }
  }

  cout << countEdge;

  for (int i = 0; i < HEIGHT; ++i)
  {
    delete[] map[i];
  }
  delete[] map;
  return 0;
}
