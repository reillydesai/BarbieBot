#include "Median_filter.h"

void MedianFilter::Init(float intialReading)
{
    // Populates readings
    for (int i = 0; i < SIZE; i++) {
        readings[i] = intialReading;
    }
}

void MedianFilter::PushValueFIFO(float newValue)
{
    // Shift existing values to make room for the new value
    for (int i = 0; i < SIZE - 1; ++i) {
        readings[i] = readings[i + 1];
    }

    // Add the new value at the end
    readings[SIZE - 1] = newValue;
}

float MedianFilter::GetMedian(float newValue)
{
    PushValueFIFO(newValue);
    float sorted_readings[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sorted_readings[i] = readings[i];
    }
    BubbleSort(sorted_readings, SIZE);
    return sorted_readings[(SIZE/2)];
}

float MedianFilter::GetMedian()
{
    float sorted_readings[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sorted_readings[i] = readings[i];
    }
    BubbleSort(sorted_readings, SIZE);
    return sorted_readings[(SIZE/2)];
}

void MedianFilter::BubbleSort(float arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Swap two elements in the array
void MedianFilter::Swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

void MedianFilter::Stop(void)
{

}

