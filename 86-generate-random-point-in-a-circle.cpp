class Solution {
public:
    double r;
    double x_c;
    double y_c;
    
    Solution(double radius, double x_center, double y_center) 
    {
        r = radius;
        x_c = x_center;
        y_c = y_center;
        
    }
    
    vector<double> randPoint() 
    {
        double xf = (double)rand() / RAND_MAX;
        
        double x_min = x_c - r;
        double x_max = x_c + r;
        
        
        double x = x_min + xf * (x_max - x_min);
        
        double yf = (double)rand() / RAND_MAX;
        
        double y_min = y_c - r;
        double y_max = y_c + r;
        
        double y = y_min + yf * (y_max - y_min);
        
        vector<double>v(2);
        
        if((x - x_c)*(x - x_c) + (y - y_c) * (y - y_c) - r * r < 0 ){
            v[0] = x;
            v[1] = y;
            return v;
        }
        else 
            return randPoint();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */