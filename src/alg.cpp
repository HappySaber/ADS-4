// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
          count++;
    }
  }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
      for (int j = len - 1; j > i; j--) {
        if (arr[i] + arr[j] == value)
            count++;
    }
    }
    return count;
}



int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = len; i < len - 1; i++) {
    int l = i, r = len;
    while (r - 1 > l){
        int m = (l + r) / 2;
        if (arr[i] + arr[m] == value) {
          count++;
          int j = m+1;
          while (arr[i] + arr[j] == value && j < r) {
            count++;
            j--;
          }
          break;
        }
        if (arr[i] + arr[m] > value)
          r = m;
        else
          l = m;
    }
    }
    return count;
}
