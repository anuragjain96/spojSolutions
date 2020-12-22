#include <stdio.h>

int m,n;
int sheep, wolf;

void processLoc(char arr[m][n], int xLoc, int yLoc)
{
  if (arr[xLoc][yLoc] == 'k')
    sheep++;
  else if (arr[xLoc][yLoc] == 'v')
    wolf++;

  arr[xLoc][yLoc] = '#';

  if (xLoc > 0 && arr[xLoc-1][yLoc] != '#')
    processLoc(arr, xLoc-1, yLoc); 
  if (xLoc+1 < m && arr[xLoc+1][yLoc] != '#')
    processLoc(arr, xLoc+1, yLoc);
  if (yLoc > 0 && arr[xLoc][yLoc-1] != '#')
    processLoc(arr, xLoc, yLoc-1);
  if (yLoc+1 < n && arr[xLoc][yLoc+1] != '#')
    processLoc(arr, xLoc, yLoc+1);

}

int main()
{
  int finalSheep = 0, finalWolf = 0;
  int i, j;

  scanf("%d %d", &m, &n);

  char arr[m][n];

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%c\n", &arr[i][j]);
    }
  }

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (arr[i][j] != '#')
      {
        sheep = 0;
        wolf = 0;
        processLoc(arr, i, j);

        if (sheep > wolf)
          finalSheep += sheep;
        else
          finalWolf += wolf;
      }
    }
  }

  printf("%d %d\n", finalSheep, finalWolf);
  return 0;
}

