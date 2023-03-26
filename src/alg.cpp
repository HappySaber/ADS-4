// Copyright 2021 NNTU-CS
int binarniypoisk(int* arr, int lens, int value) {
    int r = 0;
    int s = 0;
    int e = lens - 1;
    while (s <= e) {
    int mid = (s + e) / 2;
    if ((arr[mid]) == value) {
        r++;
        int mid2 = mid;
        if (mid != lens - 1) {
          while (((arr[mid + 1])) == value) {
            r++;
            mid++;
          }
        }
        if (mid2) {
          while ((arr[mid2 - 1]) == value) {
            r++;
            mid2--;
            if (mid2 == 0) break;
          }
        }
        return r;
    } else if (arr[mid] > value) {
        e = mid - 1;
    } else {
        s = mid + 1;
    }
    }
    return r;
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value)
          count++;
    }
  }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int j, i;
    for (int i = 0; i < len - 1; i++) {
      for (int j = len - 1; j > i; j--) {
        if ((arr[i] + arr[j]) == value)
            count++;
      }
      if (j - i == 1 && ((arr[j] + arr[i]) > value)) return count;
    }
    return count;
}



int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1 && arr[i] <= value; i++)
      count += binarniypoisk(arr + i + 1, len - i - 1, value - arr[i]);
    return count;
}
