#include <stdio.h>

int minHeap[1100001];
int currMinHeapSize = 0;

void printHeap()
{
  int i;
 for (i = 0; i < currMinHeapSize; i++)
    printf("%d ", minHeap[i]);

  printf("\n");
}

void percUpMin(int idx)
{
  int tmp;

  while ( (idx-1) >= 0)
  {
    if (minHeap[idx] < minHeap[(int)((idx - 1)/2)])
    {
      tmp = minHeap[(int)((idx-1)/2)];
      minHeap[(int)((idx-1)/2)] = minHeap[idx];
      minHeap[idx] = tmp;
    }

    idx = (int)((idx-1)/2);
  }
}

int minChild(int idx)
{

  if ((2 * idx + 2) > (currMinHeapSize - 1))
    return (2*idx + 1);
  else
  {
    if (minHeap[2*idx+1] < minHeap[2*idx+2])
      return (2*idx + 1);
    else
      return (2*idx + 2);
  }
}

void percDownMin(int idx)
{
  int minIdx, tmp;

  while (2*idx+1 < currMinHeapSize)
  {
    minIdx = minChild(idx);

    if (minHeap[idx] > minHeap[minIdx])
    {
      tmp = minHeap[minIdx];
      minHeap[minIdx] = minHeap[idx];
      minHeap[idx] = tmp;
    }

    idx = minIdx;
  }
}

int delMin()
{
  int ret = minHeap[0];
  minHeap[0] = minHeap[currMinHeapSize - 1];
  currMinHeapSize--;
  percDownMin(0);

  return ret;
}

void buildHeap()
{
  int i = currMinHeapSize - 1;

  while (i > -1)
  {
    percDownMin(i);
    i--;
  }

}

int main()
{
  int t, i, j;
  int val[1100001];
  scanf("%d", & t);

  val[0] = 0;
  val[1] = 1;

  for (i = 2; i < 1100001; i++)
    val[i] = (val[i-1] + val[i-2]) % 100000;

  for (i = 0; i < t; i++)
  {
    int start, n, end;
    scanf("%d %d", &start, &n);
    start--;
    end = start+n;

    printf("Case %d:", i+1);
    int count = 0;
    currMinHeapSize = 0;
    for (j = start; j <= end; j++)
    {
      minHeap[currMinHeapSize++] = val[j];
    }
    buildHeap();


    while (currMinHeapSize != 0 && count < 100)
    {
      printf(" %d", delMin());
      count++;
    }

    printf("\n");

  }

  return 0;

}
