#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

int nums[10];
void trans(int p1,int p2,int mid)
{
    while(nums[p1])
    {
        if(!nums[mid]){
            nums[mid]++;
            nums[p2]++;
            printf("%c%c+\n",'A'+p2,'A'+mid);
        }
        nums[mid]--;
        nums[p1]--;
        printf("%c%c-\n",'A'+p1,'A'+mid);
    }
}
int main()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    for(int i = 0; i < 8; i++)
    {
        iss >> nums[i];
    }
    if((nums[0] + nums[2] + nums[5] + nums[7]) != (nums[1] + nums[3] + nums[4] + nums[6]))
        printf("IMPOSSIBLE\n");
    else
    {
        // part 1
        trans(2,0,1);trans(5,0,4);trans(7,0,4);
        // part 2
        trans(6,4,5);trans(1,4,0);trans(3,4,0);

        while(nums[0]--)
            printf("AE-\n");
    }
    return 0;
    }
    