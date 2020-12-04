#include <string>
#include <iostream>

const char TREE = '#';

struct Path
{
  int x;
  int y;
  int position;
  int tree_count;
};

void updatePath(std::string geography, Path *p)
{
  int i = p->position % geography.size();

  if (geography[i] == TREE)
  {
    p->tree_count += 1;
  }

  p->position += p->x;
}

long int calculateTotal(Path *paths, size_t len)
{
  long int product = 1;
  for (int i = 0; i < len; i++)
  {
    product *= paths[i].tree_count;
  }

  return product;
}

int main()
{
  Path paths[5] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
  int len = sizeof(paths) / sizeof(Path);

  std::string geography = "";
  int y_pos = 0;
  while (std::getline(std::cin, geography))
  {
    for (int j = 0; j < len; j++)
    {
      if (y_pos % paths[j].y == 0)
      {
        updatePath(geography, &paths[j]);
      }
    }
    y_pos++;
  }

  std::cout << "Part One: " << paths[1].tree_count << std::endl;
  std::cout << "Part Two: " << calculateTotal(paths, len) << std::endl;

  return (0);
}