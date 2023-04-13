class Date{
    int dd;
    int mm;
    int yy;
    int maxDay();
public:
    void inDate();
    void outDate();
    void increase1day();
    void increaseNDay(int n);
    void decrease1day();
    void decreaseNDay(int n);
    int compare(Date khac);
};