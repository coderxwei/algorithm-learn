#include <iostream>
#include <vector>
#include <bits/deque.tcc>


//选择排序
std::vector<int> select_sort(std::vector<int> &nums) {
    int minvalue;
    int minidnex = 0;
    int n = nums.size();
    int searchidnex = 0;
    while (searchidnex < n) {
        int minindex = searchidnex;
        for (int i = searchidnex + 1; i < n; i++) {
            if (nums[i] >= nums[minidnex]) {
                minidnex = i;
            }
        }
        //找到最小值之后交换位置
        std::swap(nums[minidnex], nums[searchidnex]);
        searchidnex++;
    }
    return nums;
}

//插入排序
std::vector<int> insert_sort(std::vector<int> &nums) {
    int sortidnex = 0;
    int n = nums.size();
    while (sortidnex < n) {
        for (int i = sortidnex; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                std::swap(nums[i], nums[i - 1]);
            } else {
                break;
            }
        }
        sortidnex++;
    }
}

//快速排序

/*
 *  三步走
 *  1- 找基准
 *  排左边
 *  排右边
 *
 *
 */
int protitation(std::vector<int>nums,int left,int right) {
    //先定义基准
   int provit=nums[left];
    int i=left+1;
    int j=right;
    while (1) {
        //左边元素找一个比他大的
        while (i<=j &&nums[i]<=provit ) i++;
        //右边元素查找比他小的
        while (i<=j &&nums[j]>=provit)j--;
        if (i>=j)
            break;
        std::swap(nums[i],nums[j]);
    }
    //处理之后  此时 nums 数据的排列方式为  provet [小于provi的值] [>provite的值]
    std::swap(nums[left],nums[j]);
    return  j;
}
void quicksort(std::vector<int> nums, int left, int right) {
    int privote=protitation(nums,left,right);
    quicksort(nums,left ,privote-1);
    quicksort(nums,privote+1,right);
}
//堆排序


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
