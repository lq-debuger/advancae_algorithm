#include<bits/stdc++.h>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;

int job_t[20];

//job的数量
int n = 7 ;

int num = 0;
int average = 0;

//机器的负载
int m1 = 0;
int m2 = 0;
int m3 = 0;

//记录每个机器里的job

// 比较三个机器的load
int get_min_m(){
    int temp1 = min(m1,min(m2,m3));
    if(temp1 == m1) return 1;
    if(temp1 == m2) return 2;
    if(temp1 == m3) return 3;
}

bool cmp(int a , int b)
{
    return a > b;
}

int main()
{
    memset(job_t,0,sizeof(job_t));
    int temp;
    srand((unsigned)time(NULL));
    //生成随机的job值
    for (int i = 0; i < n; i++)
    {
        temp = rand()%9 + 1;
        num += temp;
        job_t[i] = temp;
        // printf("job_t[%d]=%d\n",i,job_t[i]);
    }

    //对job进行降序
    sort(job_t,job_t+n,cmp);

    for (int i = 0; i < n; i++)
    {
        printf("job_t[%d]=%d\n",i,job_t[i]);
    }
    
    //把前三个job分配给前三个机器
    m1 += job_t[0];
    m2 += job_t[1];
    m3 += job_t[2];

    //按照greedy alogrithm进行分配
    for(int i = 3; i<n;i++)
    {
        if(get_min_m() == 1) m1 += job_t[i];
        else if(get_min_m() == 2) m2 += job_t[i];
        else if(get_min_m() == 3) m3 += job_t[i];
    }

    int min_t = max(m1,max(m2,m3));
    cout << "按照greedy algorithm得到的makesapand T is :" << min_t << endl;
    cout << "总值是：" << num;
    return 0;
}