#include <stdio.h>
#include <string.h>

int count = 0;
int firstFreeSlot = -1;

int hash(char *str)
{
  int len, i, val = -1, sum = 0;

  len = strlen(str);

  for (i = 0; i < len; i++)
  {
    sum += (str[i] * (i+1));
  }

  sum *= 19;
  val = sum % 101;

  return val;
}

int search(char hashTable[][16], char *str)
{
  int hashVal, idx, i;
  int found = 0, emptySlot = 0;
  idx = -1;
  firstFreeSlot = -1;

  hashVal = hash(str);

  for (i = 0; i < 20; i++)
  {
    idx = (hashVal + i * i + 23 * i) % 101;

    if (!emptySlot && hashTable[idx][0] == '\0')
    {
      firstFreeSlot = idx;
      emptySlot = 1;
    }

    if (strcmp(str, hashTable[idx]) == 0)
    {
      found = 1;
      break;
    }
  }

  if (!found)
    idx = -1;

  return idx;
}

void printHashTable(char hashTable[][16])
{
  int i;
  printf("%d\n", count);

  for (i = 0; i < 101; i++)
  {
    if (hashTable[i][0] != '\0')
    {
      printf("%d:%s\n", i, hashTable[i]);
    }
  }
}

void insertVal(char table[][16], char *str)
{
  int ret;

  ret = search(table, str);

  if (ret != -1 || firstFreeSlot == -1)
    return;

  strcpy(table[firstFreeSlot], str); 
  count++;
  //printf("Insert %s %d \n", str, count);
}

void deleteVal(char table[][16], char *str)
{
  int ret;

  ret = search(table, str);

  if (ret == -1)
    return;

  table[ret][0] = '\0'; 
  count--;
  //printf("Delete %s %d \n", str, count);
}

int main()
{
  int t, n, i, j;
  char query[100];

  scanf("%d", &t);

  for (i = 0; i < t; i++)
  {
    count = 0;
    char hashTable[101][16] = {'\0'};
    scanf("%d", &n);

    for (j = 0; j < n; j++)
    {
      scanf("%s", query);

      if (query[0] == 'A' && query[1] == 'D' && query[2] == 'D')
      {
        insertVal(hashTable, query+4);
      }
      else
      {
        deleteVal(hashTable, query+4);
      }

    }

    printHashTable(hashTable);

  }


  return 0;
}
