class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& a) {
        int n=a.size();
		int m=a[0].size();
		for(int i=0;i<n;i++) {
			int l=0,r=m-1;
			while(l<=r) {
				int mid=(l+r)/2;
				
				int left=mid-1>=0?a[i][mid-1]:INT_MIN;
				int right=mid+1<m?a[i][mid+1]:INT_MIN;
				int up=i-1>=0?a[i-1][mid]:INT_MIN;
				int down=i+1<n?a[i+1][mid]:INT_MIN;
				
				if(a[i][mid]>left&&a[i][mid]>right
				   &&a[i][mid]>up&&a[i][mid]>down) {
					return {i,mid};    
				}
				else if(left<right) l=mid+1;
				else r=mid-1;
			}
		}
		return {-1,-1};
    }
};