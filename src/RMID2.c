#include <stdio.h>
#include <malloc.h>


int *minHeap, *maxHeap;
int minHeapSize = 0, maxHeapSize = 0;
int currMinHeapSize = 0, currMaxHeapSize = 0;

void printHeap()
{
  int i;
  printf("MAX Heap : " );
  for (i = 0; i < currMaxHeapSize; i++)
    printf("%d ", maxHeap[i]);
  printf("MIX Heap : " );
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

void insertInMinHeap(int val)
{
  if (minHeapSize == 0)
  {
    minHeap = (int*) malloc(sizeof(int)*10);
    minHeapSize = 10;
  }

  if (currMinHeapSize == minHeapSize)
  {
    minHeapSize = currMinHeapSize * 2;
    minHeap = (int*) realloc(minHeap, sizeof(int)*minHeapSize);
  }

  minHeap[currMinHeapSize] = val;
  percUpMin(currMinHeapSize);
  currMinHeapSize++;
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

// func for max heaps
void percUpMax(int idx)
{
  int tmp;

  while ( (idx-1) >= 0)
  {
    if (maxHeap[idx] > maxHeap[(int)((idx - 1)/2)])
    {
      tmp = maxHeap[(int)((idx-1)/2)];
      maxHeap[(int)((idx-1)/2)] = maxHeap[idx];
      maxHeap[idx] = tmp;
    }

    idx = (int)((idx-1)/2);
  }
}

void insertInMaxHeap(int val)
{
  if (maxHeapSize == 0)
  {
    maxHeap = (int*) malloc(sizeof(int)*10);
    maxHeapSize = 10;
  }

  if (currMaxHeapSize == maxHeapSize)
  {
    maxHeapSize = currMaxHeapSize * 2;
    maxHeap = (int*) realloc(maxHeap, sizeof(int)*maxHeapSize);
  }

  maxHeap[currMaxHeapSize] = val;
  percUpMax(currMaxHeapSize);
  currMaxHeapSize++;
}

int maxChild(int idx)
{

  if ((2 * idx + 2) > (currMaxHeapSize - 1))
    return (2*idx + 1);
  else
  {
    if (maxHeap[2*idx+1] > maxHeap[2*idx+2])
      return (2*idx + 1);
    else
      return (2*idx + 2);
  }
}

void percDownMax(int idx)
{
  int maxIdx, tmp;

  while (2*idx+1 < currMaxHeapSize)
  {
    maxIdx = maxChild(idx);

    if (maxHeap[idx] < maxHeap[maxIdx])
    {
      tmp = maxHeap[maxIdx];
      maxHeap[maxIdx] = maxHeap[idx];
      maxHeap[idx] = tmp;
    }

    idx = maxIdx;
  }
}

int delMax()
{
  int ret = maxHeap[0];
  maxHeap[0] = maxHeap[currMaxHeapSize - 1];
  currMaxHeapSize--;
  percDownMax(0);

  return ret;
}



void insert(int val)
{
  int tmp;

  if (currMaxHeapSize == 0 && currMinHeapSize == 0)
    insertInMaxHeap(val);

  else if (currMaxHeapSize == 0)
  {
    if (val < minHeap[0])
      insertInMaxHeap(val);
    else
    {
      tmp = delMin();
      insertInMaxHeap(tmp);
      insertInMinHeap(val);
    }
  }

  else if (currMinHeapSize == 0)
  {
    if (val < maxHeap[0])
    {
      tmp = delMax();
      insertInMaxHeap(val);
      insertInMinHeap(tmp);
    }
    else
      insertInMinHeap(val);
  }

  else if (currMaxHeapSize == currMinHeapSize)
  {
    if (val < maxHeap[0])
      insertInMaxHeap(val);
    else
      insertInMinHeap(val);
  }

  else if (currMaxHeapSize > currMinHeapSize)
  {
    if (val > maxHeap[0])
      insertInMinHeap(val);
    else
    {
      tmp = delMax();
      insertInMinHeap(tmp);
      insertInMaxHeap(val);
    }
  }

  else if (currMaxHeapSize < currMinHeapSize)
  {
    if (val < minHeap[0])
      insertInMaxHeap(val);
    else
    {
      tmp = delMin();
      insertInMinHeap(val);
      insertInMaxHeap(tmp);
    }
  }
}

int findMedian()
{
  int ret;

  if (currMinHeapSize == 0 && currMaxHeapSize == 0)
    return;

  if (currMinHeapSize == currMaxHeapSize)
    ret = delMax();
  else if (currMinHeapSize < currMaxHeapSize)
    ret = delMax();
  else if (currMinHeapSize > currMaxHeapSize)
    ret = delMin();

  printf("%d\n", ret);
  return ret;
}

void reinit()
{
  free(minHeap);
  free(maxHeap);
  currMinHeapSize = 0;
  currMaxHeapSize = 0;
  minHeapSize = 0;
  maxHeapSize = 0;
}

int main()
{
  int t, n, i;
  scanf("%d", &t);

  for (i = 0; i < t; i++)
  {
    scanf("%d", &n);

    while (n != 0)
    {
      if (n == -1)
      {
        findMedian();
      }
      else
      {
        insert(n);
      }
      //printHeap();

      scanf("%d", &n);
    }
    reinit();
  }

  return 0;
}
