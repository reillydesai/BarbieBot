#ifndef MEDIAN_FILTER
#define MEDIAN_FILTER

#define SIZE 5 

class MedianFilter{
    private:
        void Swap(float &a, float &b);
        void BubbleSort(float arr[], int);
        void PushValueFIFO(float);

        float readings[SIZE];

    public:
        void Init(float);
        float GetMedian(float);
        float GetMedian(void);
        void Stop(void);
};

#endif