#include <iostream>
int trap_rain_water(int* arr, int size);
int get_next(int** ,int ,int ,int);
int get_max(int* arr, int size);
int main() {
    // Write C++ code here
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trap_rain_water(arr,12);

    return 0;
}
int trap_rain_water(int* arr, int size){
    int rows = get_max(arr,size);
    int** matrix = new int*[rows];
    for (int i = 0;i < rows;++i){
        matrix[i] = new int[size];
    }
    for (int i = 0;i < rows;++i){
        for (int j = 0;j < size;++j){
            matrix[i][j] = 0;
        }
    }
    for (int i = 0;i < size;++i){
        int current_height = arr[i];
        for (int j = rows - 1;j >= 0 && current_height >= 1;--j){
            matrix[j][i] = 1;
            --current_height;
        }
    }
    
    int result = 0;
    for (int i = rows - 1;i >= 0;--i){
        for (int j = 0;j < size;++j){
            if (matrix[i][j] == 1){
                int next = get_next(matrix, i, size, j);
                if (next == -1) break;
                int difference = next - j - 1;
                result += (difference > 0 ? difference : 0);
                j = next - 1; 
            }
        }
    }
    return result;
}
int get_next(int** matrix, int row, int size, int x){
    for (int i = x + 1; i < size; ++i){
        if (matrix[row][i] == 1){
            return i;
        }
    }
    return -1;
}
int get_max(int* arr, int size){
    int max = 0;
    for (int i = 0;i < size;++i){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


