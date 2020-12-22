#include <stdio.h>
#include <limits.h>

int main()
{
  int n, exitCell, time, totalConn;
  int count = 0;
  int i, j;

  scanf("%d", &n);
  scanf("%d", &exitCell);
  scanf("%d", &time);
  scanf("%d", &totalConn);

  exitCell--;

  int arr[n][n];
  int dist[n];
  int mark[n];
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
      arr[i][j] = 0;

    dist[i] = INT_MAX;
    mark[i] = 0;
  }

  int start, end, wt;
  int currentNode, val, min;

  for (i = 0; i < totalConn; i++)
  {
    scanf("%d %d %d", &start, &end, &wt);
    // storing the edges in reverse 
    arr[end-1][start-1] = wt;
  }

  currentNode = exitCell;
  dist[currentNode] = 0;
  mark[currentNode] = 1;

  for (i = 0; i < n-1; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (mark[j])
        continue;

      if (arr[currentNode][j] != 0 && dist[j] == INT_MAX)
      {
        dist[j] = arr[currentNode][j] + dist[currentNode];
      }
      else if (arr[currentNode][j] != 0)
      {
        val = arr[currentNode][j] + dist[currentNode];
        if (dist[j] > val)
          dist[j] = val;
      }
    }

    min = INT_MAX;

    for (j = 0; j < n; j++)
    {
      if (mark[j] == 1)
        continue;

      if (dist[j] < min)
      {
        min = dist[j];
        currentNode = j;
      }
    }

    mark[currentNode] = 1;
  }

  count = 0;
  for (i = 0; i < n; i++)
  {
    if (dist[i] <= time)
      count++;
  }

  printf("%d", count);

  return 0;
}
