////求两个有序数组的中位数
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        if (nums1.size() > nums2.size()) { // 保证数组1一定最短
//            swap(nums1, nums2);
//        }
//        int m = nums1.size();
//        int n = nums2.size();
//
//        // 两个数组分割线左侧所有的元素个数（分割线第一条件）
//        int totalLeft = (m + n + 1) / 2;
//
//        int left = 0; // 第一个数组的左边界
//        int right = m; // 第一个数组的右边界
//
//        // 循环查找，最后得到的i表示第一个数组在分割线右侧数值的下标，j表示第二个数组在分割线右侧数值的下标
//        while (left < right) {
//            int i = (left + right + 1) / 2; // 第一个数组的分割线
//            int j = totalLeft - i; // 第二个数组的分割线
//
//            if (nums1[i - 1] > nums2[j]) { // 第一个数组分割线左侧的数值大于第二个数组分割线右侧的数值
//                right = i - 1; // 下一轮的搜索区间为[left, i - 1]
//            }
//            else {
//                left = i; // 下一轮的搜索区间为[i, right]
//            }
//        }
//
//        int i = left;
//        int j = totalLeft - i;
//        int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
//        int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
//        int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
//        int nums2RightMin = (j == n) ? INT_MAX : nums2[j];
//
//        // 计算中位数
//        if ((m + n) % 2 == 1) { // 两数组总长度为奇数
//            return max(nums1LeftMax, nums2LeftMax);
//        }
//        else { // 两数组总长度为偶数
//            return (double)(max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
//        }
//    }
//};
//
//int main() {
//    Solution sol;
//
//    vector<int> nums1 = { 1, 3 };
//    vector<int> nums2 = { 2 };
//    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl; // 2.0
//
//    nums1 = { 1, 2 };
//    nums2 = { 3, 4 };
//    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl; // 2.5
//
//    nums1 = { 2, 4, 6, 15 };
//    nums2 = { 1, 7, 8, 10, 17 };
//    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl; // 7.0
//
//    return 0;
//}


////最长回文子串
//class Solution {
//public:
//    //从两侧向中间寻找
//    string longestPalindrome(string s) {
//        int sz = s.size();
//        if (sz < 2) return s;
//        int lengthMax = 1;//当前最长回文字串的起始长度
//        int begin = 0;//当前最长回文字串的起始下标
//
//        for (int i = 0; i < sz - 1; i++)//回文不可能到数组末尾，因为如果这样的话
//        {
//            for (int j = i + 1; j < sz; j++)
//            {//判断[i,j]范围内的子串是不是回文子串，如果是，且回文字串的长度大于之前记录的范围内的子串是不是回文子串，如果是，且回文字串的长度大于之前记录的lengthhMax，就更新lengthMax和回文子串的下标i，就更新lengthMax和回文子串的下标i
//                if (j - i + 1 > lengthMax && judgeLPS(s, i, j))//LPS是最长回文子串Longest palindromic substring的缩写
//                {
//                    lengthMax = j - i + 1;
//                    begin = i;
//                }
//            }
//        }
//
//        return s.substr(begin, lengthMax);
//    }
//
//private:
//    bool judgeLPS(const string& s, int left, int right)//防止字符串过长导致的超出内存限制问题,传引用传参进行判断
//    {
//        while (left < right)
//        {
//            if (s[left] != s[right])
//            {
//                return false;
//            }
//            else
//            {
//                left++;
//                right--;
//            }
//        }
//        return true;//在[i,j]范围内都相同了就返回真
//    }
//};

//Z字型变换


//
//#include <stdio.h>
//#include <unistd.h>
//#include <signal.h>
//
//// volatile int g_flag = 0;
//int g_flag = 0;
//
//void changeflag(int signo)
//{
//    (void)signo;
//    printf("将g_flag,从%d->%d\n", g_flag, 1);
//    g_flag = 1;
//}
//
//int main()
//{
//    signal(2, changeflag);
//
//    while (!g_flag); // 故意写成这个样子, 编译器默认会对我们的代码进行自动优化！
//    // {
//    //     printf("hello world\n");
//    //     sleep(1);
//    // }
//
//    printf("process quit normal\n");
//    return 0;
//}


//#include <iostream>
//#include <pthread.h>
//#include <unistd.h>
//#include <sys/types.h>
//
//void* newthreadrun(void* args)
//{
//    while (true)
//    {
//        std::cout << "I am new thread, pid: " << getpid() << std::endl;
//        sleep(1);
//    }
//}
//
//int main()
//{
//    pthread_t tid;
//    pthread_create(&tid, nullptr, newthreadrun, nullptr);
//
//    while (true)
//    {
//        std::cout << "I am main thread, pid: " << getpid() << std::endl;
//        sleep(1);
//    }
//}


#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <pthread.h> // 原生线程库的头文件

const int threadnum = 5;

class Task
{
public:
    Task()
    {}
    void SetData(int x, int y)
    {
        datax = x;
        datay = y;
    }
    int Excute()
    {
        return datax + datay;
    }
    ~Task()
    {

    }
private:
    int datax;
    int datay;
};

class ThreadData : public Task
{
public:
    ThreadData(int x, int y, const std::string& threadname) :_threadname(threadname)
    {
        _t.SetData(x, y);
    }
    std::string threadname()
    {
        return _threadname;
    }
    int run()
    {
        return _t.Excute();
    }
private:
    std::string _threadname;
    Task _t;
};

class Result
{
public:
    Result() {}
    ~Result() {}
    void SetResult(int result, const std::string& threadname)
    {
        _result = result;
        _threadname = threadname;
    }
    void Print()
    {
        std::cout << _threadname << " : " << _result << std::endl;
    }
private:
    int _result;
    std::string _threadname;
};

void* handlerTask(void* args)
{
    ThreadData* td = static_cast<ThreadData*>(args);

    std::string name = td->threadname();

    Result* res = new Result();
    int result = td->run();

    res->SetResult(result, name);

    // std::cout << name << "run result : " << result << std::endl;
    delete td;

    sleep(2);
    return res;
    // // std::string threadname =static_cast<char*>(args);
    // const char *threadname = static_cast<char *>(args);
    // while (true)
    // {
    //     std::cout << "I am " << threadname << std::endl;
    //     sleep(2);
    // }

    // delete []threadname;

    // return nullptr;
}
// 1. 多线程创建
// 2. 线程传参和返回值，我们可以传递级别信息，也可以传递其他对象(包括你自己定义的！)
// 3. C++11也带了多线程，和我们今天的是什么关系？？？ TODO下节课
int main()
{
    std::vector<pthread_t> threads;
    for (int i = 0; i < threadnum; i++)
    {
        char threadname[64];
        snprintf(threadname, 64, "Thread-%d", i + 1);
        ThreadData* td = new ThreadData(10, 20, threadname);

        pthread_t tid;
        pthread_create(&tid, nullptr, handlerTask, td);
        threads.push_back(tid);
    }
    std::vector<Result*> result_set;
    void* ret = nullptr;
    for (auto& tid : threads)
    {
        pthread_join(tid, &ret);
        result_set.push_back((Result*)ret);
    }

    for (auto& res : result_set)
    {
        res->Print();
        delete res;
    }
}

// // 同一个进程内的线程，大部分资源都是共享的. 地址空间是共享的！
// int g_val = 100;

// std::string ToHex(pthread_t tid)
// {
//     char id[64];
//     snprintf(id, sizeof(id), "0x%lx", tid);
//     return id;
// }

// // 线程退出
// // 1. 代码跑完，结果对
// // 2. 代码跑完，结果不对
// // 3. 出异常了 --- 重点 --- 多线程中，任何一个线程出现异常(div 0， 野指针), 都会导致整个进程退出！ ---- 多线程代码往往健壮性不好
// void *threadrun(void *args)
// {
//     std::string threadname = (char*)args;
//     int cnt = 5;
//     while (cnt)
//     {
//         printf("new thread, g_val: %d, &g_val: %p\n", g_val, &g_val);

//         // std::cout << threadname << " is running: " << cnt << ", pid: " << getpid()
//         //     << " mythread id: " << ToHex(pthread_self())
//         //     << "g_val: "<< g_val << " &g_val: " << &g_val << std::endl;
//         g_val++;
//         sleep(1);
//         // int *p = nullptr;
//         // *p = 100; // 故意一个野指针
//         cnt--;
//     }
//     // 1. 线程函数结束
//     // 2. pthread_exit()
//     // pthread_exit((void*)123);
//     // exit(10); // 不能用exit终止线程，因为它是终止进程的.
//     return (void*)123; // warning
// }

// // 主线程退出 == 进程退出 == 所有线程都要退出
// // 1. 往往我们需要main thread最后结束
// // 2. 线程也要被"wait", 要不然会产生类似进程哪里的内存泄漏的问题
// int main()
// {
//     // 1. id
//     pthread_t tid;
//     pthread_create(&tid, nullptr, threadrun, (void*)"thread-1");

//     // 在主线程中，你保证新线程已经启动
//     // sleep(2);
//     // pthread_cancel(tid);

//     void* ret = nullptr;

//     // 2. 新和主两个线程，谁先运行呢？不确定，由调度器决定
//     // int cnt = 10;
//     // while (true)
//     // {
//     //     // std::cout << "main thread is running: " << cnt << ", pid: "
//     //     //     << getpid() << " new thread id: " << ToHex(tid) << " "
//     //     //     << " main thread id: " << ToHex(pthread_self())
//     //     //     << "g_val: "<< g_val << " &g_val: " << &g_val << std::endl;
//     //     printf("main thread, g_val: %d, &g_val: %p\n", g_val, &g_val);

//     //     sleep(1);
//     //     cnt--;
//     // }
//     // 不考虑线程异常情况！
//     // PTHREAD_CANCELED; // (void*)-1
//     int n = pthread_join(tid, &ret); // 我们怎么没有像进程一样获取线程退出的退出信号呢？只有你手动写的退出码
//     std::cout << "main thread quit, n=" << n << " main thread get a ret: " << (long long)ret << std::endl;
//     return 0;
// }


#ifndef __THREAD_HPP__
#define __THREAD_HPP__

#include <iostream>
#include <string>
#include <unistd.h>
#include <functional>
#include <pthread.h>

namespace ThreadModule
{
    template<typename T>
    using func_t = std::function<void(T&)>;
    // typedef std::function<void(const T&)> func_t;

    template<typename T>
    class Thread
    {
    public:
        void Excute()
        {
            _func(_data);
        }
    public:
        Thread(func_t<T> func, T& data, const std::string& name = "none-name")
            : _func(func), _data(data), _threadname(name), _stop(true)
        {}
        static void* threadroutine(void* args) // 类成员函数，形参是有this指针的！！
        {
            Thread<T>* self = static_cast<Thread<T> *>(args);
            self->Excute();
            return nullptr;
        }
        bool Start()
        {
            int n = pthread_create(&_tid, nullptr, threadroutine, this);
            if (!n)
            {
                _stop = false;
                return true;
            }
            else
            {
                return false;
            }
        }
        void Detach()
        {
            if (!_stop)
            {
                pthread_detach(_tid);
            }
        }
        void Join()
        {
            if (!_stop)
            {
                pthread_join(_tid, nullptr);
            }
        }
        std::string name()
        {
            return _threadname;
        }
        void Stop()
        {
            _stop = true;
        }
        ~Thread() {}

    private:
        pthread_t _tid;
        std::string _threadname;
        T& _data;  // 为了让所有的线程访问同一个全局变量
        func_t<T> _func;
        bool _stop;
    };
} // namespace ThreadModule

#endif