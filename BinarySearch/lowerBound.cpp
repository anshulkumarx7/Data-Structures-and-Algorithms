#include <iostream>
using namespace std;
int singleNonDuplicate(int nums[], int size)
{
    int n = size;
    if (n == 1)
    {
        return nums[0];
    }
    if (nums[0] != nums[1])
    {
        return nums[0];
    }
    if (nums[n - 1] != nums[n - 2])
    {
        return nums[n - 1];
    }
    int start = 1;
    int end = n - 2;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            cout << "enter25"
                 << "\n";
            return mid;
        }
        else if (mid % 2 != 0)
        {
            cout << "enter30"
                 << "\n";

            if (nums[mid - 1] == nums[mid])
            {
                cout << "enter34"
                     << "\n";

                start = mid + 1;
            }
            else
            {
                cout << "enter40"
                     << "\n";
                end = mid - 1;
            }
        }
        else
        {
            if (nums[mid] == nums[mid + 1])
            {
                cout << "enter52"<< "\n";
                end = mid - 1;
            }
            else
            {
                cout<<"enter57"<<"\n";

                start = mid + 1;
            }
        }
        mid = start + (end - start) / 2;
            cout<<"reloop"<<"\n";

    }

    return -1;
}
int main()
{
    int nums[] = {1, 1, 2, 3, 3, 4, 4, 8};
    cout << singleNonDuplicate(nums, 8);
    return 0;
}