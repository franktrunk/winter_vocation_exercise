#include"function.h"
//日期问题
int normdays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int leapdays[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
bool leapyear(int y)
{
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return true;
    return false;
}
bool check(int y, int m, int d)
{
    if (leapyear(y))
    {
        if (leapdays[m] < d)
            return false;
    }
    else
    {
        if (normdays[m] < d)
            return false;
    }
    return true;
}
void cout_date()
{
    set<int> s;
    int a, b, c;
    char ch1, ch2;
    cin >> a >> ch1 >> b >> ch2 >> c;
    int y, m, d;
    y = a + 2000;
    m = b;
    d = c;
    if (check(y, m, d))
        s.insert(y * 10000 + m * 100 + d);
    y = c + 2000;
    m = a;
    d = b;
    if (check(y, m, d))
        s.insert(y * 10000 + m * 100 + d);
    y = c + 2000;
    m = b;
    d = a;
    if (check(y, m, d))
        s.insert(y * 10000 + m * 100 + d);
    for (auto it = s.begin(); it != s.end(); ++it) {
        int total = *it;
        int year = total / 10000;
        total = total % 10000;
        int month = total / 100;
        total = total % 100;
        int day = total;
        cout << year << "--";
        if (month < 10)
            cout << 0;
        cout << month << "--";
        if (day < 10)
            cout << 0;
        cout << day << endl;
    }

}

//筛法
void prime(bool* flag,int N)
{
    memset(flag, true, sizeof(flag));
    flag[0] = false;
    flag[1] = false;
    for (int i = 2; i <= N / 2; i++)
    {
        if (flag[i])
        {
            for(int j= i*2;j<=N;j+=i)
            flag[j]=false;
        }
    }

}

void birthday_candle()
{
    int N = 236;
    int begin;
    int now;
    for (begin = 1; begin <= 50; begin++)
    {
        for (now = begin + 1; now <= 50; now++)
        {
            int sum = 0;
            for (int i = begin; i <= now; i++)
            {
                sum += i;
            }
            if (sum == N)
                cout << begin << endl;
        }
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

 int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}


void Indeterminate_equation()
{
    int a, b, c;
    cin >> a >> b >> c;
    int mlcm = lcm(a, b);
    int db = mlcm / b;
    int da = mlcm / a;
    int ansa=0;
    int ansb=0;
    int cnt = 0;
    for (int i = 0; i <= c / a; i++)
    {
        if ((c - i * a) % b == 0)
        {
            ansa = i;
            ansb = (c - i * a) / b;
           
            break;
        }
    }
    while (ansa * a <= c)
    {
        cnt++;
        ansa += da;
    }
    cout << cnt;
}


