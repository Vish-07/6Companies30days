/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mArr) 
    {
        int left = 1, right = mArr.length() - 1;
        int peak = -1;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int idx = mArr.get(mid);
            int idxL = mArr.get(mid - 1);
            int idxR = mArr.get(mid + 1);
            
            if(idx > idxL && idx > idxR)
            {
                peak = mid;
                break;
            }
            else if(idxR > idx && idx > idxL)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        left = 0, right = peak;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int x = mArr.get(mid);
            if(x == target)
                return mid;
            else if(x < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        left = peak, right = mArr.length() - 1;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int x = mArr.get(mid);
            
            if(x == target)
                return mid;
            else if(x < target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};