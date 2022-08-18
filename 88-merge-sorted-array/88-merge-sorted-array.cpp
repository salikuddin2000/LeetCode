class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        if(n==0) return;
        if(m==0){
            while(j>-1){
                swap(nums1[j],nums2[j]);
                j--;
            }
        }
        
        while(i>-1&&j>-1){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }
            else {
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        } 
        if(i==-1){
            i=0;
            while(i<=j){
                nums1[i]=nums2[i];
                i++;
            }
        }
    }
};
