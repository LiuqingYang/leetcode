// https://leetcode.com/problems/container-with-most-water/
// Yang Liuqing
// yllqq@outlook.com

// Caution for time out, need optimization

#include "header.h"

int maxArea(int* height, int heightSize) {
    int *left_x;
    int *left_h;
    int left_count = 0;
    int left_current_h = 0;

    int *right_x;
    int *right_h;
    int right_count = 0;
    int right_current_h = 0;

    int max_area = 0;

    left_x = malloc(sizeof(int) * heightSize);
    left_h = malloc(sizeof(int) * heightSize);
    right_x = malloc(sizeof(int) * heightSize);
    right_h = malloc(sizeof(int) * heightSize);

    for (int i = 0; i < heightSize - 1; i++)
    {
        int h = height[i];
        if (h > left_current_h)
        {
            left_current_h = h;
            left_x[left_count] = i;
            left_h[left_count] = h;
            left_count++;
        }
    }
    for (int j = heightSize - 1; j > 0; j--)
    {
        int h = height[j];
        if (h > right_current_h)
        {
            right_current_h = h;
            right_x[right_count] = j;
            right_h[right_count] = h;
            right_count++;
        }
    }

    for (int i = 0; i < left_count; i++)
    {
        int x1 = left_x[i];
        int h1 = left_h[i];

        for (int j = 0; j < right_count; j++)
        {
            int x2 = right_x[j];
            int h2 = right_h[j];
            int h;
            int area;

            if (x1 >= x2) break;

            h = h1 > h2 ? h2 : h1;
            area = h * (x2 - x1);
            if (area > max_area) max_area = area;
        }
    }

    return max_area;
}


int maxArea_no_optimization(int* height, int heightSize) {
    int max_area = 0;

    for (int i = 0; i < heightSize - 1; i++)
        for (int j = i+1; j < heightSize; j++)
        {
            int h1 = height[i];
            int h2 = height[j];
            int h = h1 > h2 ? h2 : h1;
            int area = h * (j - 1);

            if (area > max_area) max_area = area;
        }

    return max_area;
}


int main()
{
    int height[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("Max area: %d", maxArea(height, 10));
}
