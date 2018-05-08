#include "../str/str.h"

void shell_sort(char a[])
{
  int gap, i, j, temp, n = strl(a);

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; ++i)
      for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
      {
        temp = a[j];
        a[j] = a[j + gap];
        a[j + gap] = temp;
      }
}

// time complexity O(n^2)
// find minimum element and move it to new array
void selection_sort(char a[], char b[])
{
  int i, j, m;

  for (i = 0; a[i] != '\0'; ++i)
  {
    m = 0;
    for (j = 0; a[j] != '\0'; ++j)
    {
      if (a[j] != -1 && a[j] >= a[m])
        m = j;
    }
    b[i] = a[m];
    a[m] = -1;
  }
  b[i] = '\0';
}

// binary search, return position of character c in sorted string s
int binary_search(int c, char s[])
{
  int low, high, mid, n = strl(s);

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (c > s[mid])
      high = mid - 1;
    else if (c < s[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}