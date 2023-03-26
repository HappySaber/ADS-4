int cbinsearch(int* arr, int size, int value) {
int res = 0;
int start = 0;
int end = size - 1;
while (start <= end) {
int middle = (start + end) / 2;
if (*(arr + middle) == value) {
res += 1;
int middle1 = middle;
if (middle != size - 1) {
while ((*(arr + middle + 1)) == value) {
res += 1;
middle += 1;
}
}
if (middle1) {
while ((*(arr + middle1 - 1)) == value) {
res += 1;
middle1 -= 1;
if (middle1 == 0) break;
}
}
return res;
} else if (*(arr + middle) > value) {
end = middle - 1;
} else {
start = middle + 1;
}
}
return res;
}

int countPairs1(int* arr, int len, int value) {
int count = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if (*(arr + i) + *(arr + j) == value) count += 1;
}
}
return count;
}

int countPairs2(int* arr, int len, int value) {
int count = 0;
int j;
for (int i = 0; i < len - 1; i++) {
for (j = i + 1; j < len && arr[i] + arr[j] <= value; j++)
if (*(arr + i) + *(arr + j) == value) count += 1;
if (j - i == 1 && *(arr + j) + *(arr + i) > value) return count;
}
return count;
}

int countPairs3(int* arr, int len, int value) {
int count = 0;
for (int i = 0; i < len - 1 && arr[i] <= value; i++)
count += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
return count;
}
