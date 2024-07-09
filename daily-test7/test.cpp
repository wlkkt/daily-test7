////�����������������λ��
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
//        if (nums1.size() > nums2.size()) { // ��֤����1һ�����
//            swap(nums1, nums2);
//        }
//        int m = nums1.size();
//        int n = nums2.size();
//
//        // ��������ָ���������е�Ԫ�ظ������ָ��ߵ�һ������
//        int totalLeft = (m + n + 1) / 2;
//
//        int left = 0; // ��һ���������߽�
//        int right = m; // ��һ��������ұ߽�
//
//        // ѭ�����ң����õ���i��ʾ��һ�������ڷָ����Ҳ���ֵ���±꣬j��ʾ�ڶ��������ڷָ����Ҳ���ֵ���±�
//        while (left < right) {
//            int i = (left + right + 1) / 2; // ��һ������ķָ���
//            int j = totalLeft - i; // �ڶ�������ķָ���
//
//            if (nums1[i - 1] > nums2[j]) { // ��һ������ָ���������ֵ���ڵڶ�������ָ����Ҳ����ֵ
//                right = i - 1; // ��һ�ֵ���������Ϊ[left, i - 1]
//            }
//            else {
//                left = i; // ��һ�ֵ���������Ϊ[i, right]
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
//        // ������λ��
//        if ((m + n) % 2 == 1) { // �������ܳ���Ϊ����
//            return max(nums1LeftMax, nums2LeftMax);
//        }
//        else { // �������ܳ���Ϊż��
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


////������Ӵ�
//class Solution {
//public:
//    //���������м�Ѱ��
//    string longestPalindrome(string s) {
//        int sz = s.size();
//        if (sz < 2) return s;
//        int lengthMax = 1;//��ǰ������ִ�����ʼ����
//        int begin = 0;//��ǰ������ִ�����ʼ�±�
//
//        for (int i = 0; i < sz - 1; i++)//���Ĳ����ܵ�����ĩβ����Ϊ��������Ļ�
//        {
//            for (int j = i + 1; j < sz; j++)
//            {//�ж�[i,j]��Χ�ڵ��Ӵ��ǲ��ǻ����Ӵ�������ǣ��һ����ִ��ĳ��ȴ���֮ǰ��¼�ķ�Χ�ڵ��Ӵ��ǲ��ǻ����Ӵ�������ǣ��һ����ִ��ĳ��ȴ���֮ǰ��¼��lengthhMax���͸���lengthMax�ͻ����Ӵ����±�i���͸���lengthMax�ͻ����Ӵ����±�i
//                if (j - i + 1 > lengthMax && judgeLPS(s, i, j))//LPS��������Ӵ�Longest palindromic substring����д
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
//    bool judgeLPS(const string& s, int left, int right)//��ֹ�ַ����������µĳ����ڴ���������,�����ô��ν����ж�
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
//        return true;//��[i,j]��Χ�ڶ���ͬ�˾ͷ�����
//    }
//};

//Z���ͱ任


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
//    printf("��g_flag,��%d->%d\n", g_flag, 1);
//    g_flag = 1;
//}
//
//int main()
//{
//    signal(2, changeflag);
//
//    while (!g_flag); // ����д���������, ������Ĭ�ϻ�����ǵĴ�������Զ��Ż���
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
#include <pthread.h> // ԭ���߳̿��ͷ�ļ�

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
// 1. ���̴߳���
// 2. �̴߳��κͷ���ֵ�����ǿ��Դ��ݼ�����Ϣ��Ҳ���Դ�����������(�������Լ�����ģ�)
// 3. C++11Ҳ���˶��̣߳������ǽ������ʲô��ϵ������ TODO�½ڿ�
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

// // ͬһ�������ڵ��̣߳��󲿷���Դ���ǹ����. ��ַ�ռ��ǹ���ģ�
// int g_val = 100;

// std::string ToHex(pthread_t tid)
// {
//     char id[64];
//     snprintf(id, sizeof(id), "0x%lx", tid);
//     return id;
// }

// // �߳��˳�
// // 1. �������꣬�����
// // 2. �������꣬�������
// // 3. ���쳣�� --- �ص� --- ���߳��У��κ�һ���̳߳����쳣(div 0�� Ұָ��), ���ᵼ�����������˳��� ---- ���̴߳���������׳�Բ���
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
//         // *p = 100; // ����һ��Ұָ��
//         cnt--;
//     }
//     // 1. �̺߳�������
//     // 2. pthread_exit()
//     // pthread_exit((void*)123);
//     // exit(10); // ������exit��ֹ�̣߳���Ϊ������ֹ���̵�.
//     return (void*)123; // warning
// }

// // ���߳��˳� == �����˳� == �����̶߳�Ҫ�˳�
// // 1. ����������Ҫmain thread������
// // 2. �߳�ҲҪ��"wait", Ҫ��Ȼ��������ƽ���������ڴ�й©������
// int main()
// {
//     // 1. id
//     pthread_t tid;
//     pthread_create(&tid, nullptr, threadrun, (void*)"thread-1");

//     // �����߳��У��㱣֤���߳��Ѿ�����
//     // sleep(2);
//     // pthread_cancel(tid);

//     void* ret = nullptr;

//     // 2. �º��������̣߳�˭�������أ���ȷ�����ɵ���������
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
//     // �������߳��쳣�����
//     // PTHREAD_CANCELED; // (void*)-1
//     int n = pthread_join(tid, &ret); // ������ôû�������һ����ȡ�߳��˳����˳��ź��أ�ֻ�����ֶ�д���˳���
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
        static void* threadroutine(void* args) // ���Ա�������β�����thisָ��ģ���
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
        T& _data;  // Ϊ�������е��̷߳���ͬһ��ȫ�ֱ���
        func_t<T> _func;
        bool _stop;
    };
} // namespace ThreadModule

#endif