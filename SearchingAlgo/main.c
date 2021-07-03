#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

void BubbleSort(uint32_t * Arr, uint8_t size);
uint8_t BinarySearch (uint32_t * Arr, uint8_t size, uint32_t data);

int main()
{
   uint32_t Arr[10]={5,2,8,12,34,56,73,90,99,11};
   uint8_t result;
   result=BinarySearch(Arr,10,90);

   if(result == -1)
   {
       printf("Number Not found");
   }else
   {
       printf("Number Found in Index :%d",result);
   }
}


void BubbleSort(uint32_t * Arr, uint8_t size) {
    uint8_t i = 0, j = 0, tmp;

    for (i = 0; i < size; i++) {

        for (j = 0; j < size - i - 1; j++) {

            if (Arr[j] > Arr[j + 1]) {
                tmp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = tmp;
            }
        }
    }
}





uint8_t BinarySearch (uint32_t * Arr, uint8_t size, uint32_t data)
{
	uint32_t mid ;
	uint32_t first=0;
	uint32_t last=size-1;

	BubbleSort(Arr,size);

	while (first <= last) {

		mid=first+(last-first) / 2;

		if (Arr[mid] == data)
		{
			return mid;
		}
		if (Arr[mid] < data)
		{
			first = mid + 1;
		}
		else
		{
			last = mid - 1;
		}

	}

	return -1;
}
