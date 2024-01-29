#include <stdio.h>

// Birleştirme (Merge) işlemi
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Geçici diziler
    int L[n1], R[n2];

    // Sol yarıyı kopyala
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Sağ yarıyı kopyala
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // L ve R dizilerini karşılaştırarak ana diziyi sıralı olarak birleştir
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // L dizisinde kalan elemanları ana diziye kopyala
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // R dizisinde kalan elemanları ana diziye kopyala
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort algoritması
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sol yarıyı sırala
        mergeSort(arr, left, mid);
        // Sağ yarıyı sırala
        mergeSort(arr, mid + 1, right);
        // Sıralı yarıları birleştir
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {64, 27, 78, 67, 13, 34, 25, 12, 22, 11, 90};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Merge Sort'u uygula
    mergeSort(arr, 0, arr_size - 1);

    // Sıralanmış diziyi ekrana yazdır
    printf("Siralanmis dizi: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}
