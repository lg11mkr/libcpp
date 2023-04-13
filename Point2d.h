class Point2d{
    double x;
    double y;
public:
    Point2d();
    Point2d(double x0, double y0);
    Point2d(const Point2d& a);
    Point2d operator=(const Point2d& a);
    void input();
    void output();
    double distance(Point2d b);
    void outDistance(Point2d b);
};