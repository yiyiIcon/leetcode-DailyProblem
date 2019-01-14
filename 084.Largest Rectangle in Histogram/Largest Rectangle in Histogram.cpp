/*这道题考虑用一个栈来维持一个递增序列，栈中保存的是当前元素的索引。如果当前值比栈顶元素小，那么栈中元素就需要弹出，直到栈为空或者栈顶元素小于当前元素。这样的话可以保证栈中第i个元素对应的高度总是小于等于栈中第i-1个元素至当前欲插入元素对应的矩阵高度，这样当元素弹出时，以它为最低高度的最大矩阵面积就很好求出来了。高直接可以得出，而长度则为第i-1个元素对应的索引至当前欲插入元素的索引的差值。
示例的过程如下：stack<int> st
矩阵1，高度为2，入栈，栈中元素为 0
矩阵2，高度为1，弹出栈顶元素并计算当前最大面积，弹出后栈为空，当前元素索引为1，故长度为1，面积为1*2=2，当前元素入栈，栈中元素为 1
矩阵3，高度为5，直接入栈，栈中元素为 1,2
矩阵4，高度为6，直接入栈，栈中元素为1,2,3
矩阵5，高度为2，小于栈顶元素对应矩阵高度，弹出栈顶元素3，栈非空，栈顶元素为2，故以矩阵4为最低高度的面积最大为6*(4-2-1)=6，栈中元素为1,2。此时当前矩阵高度依然小于栈顶元素对应矩阵高度，继续弹出2，栈非空，栈顶元素为1，故长度为4-1-1=2，面积为2*5=10。入栈，栈中元素为1,4
矩阵6，高度为3,大于栈顶元素，入栈，栈中元素为1,4,5
此时元素遍历完，弹出栈中元素。
弹出栈顶元素5，此时栈顶元素为4，此时长度为6-4-1=1，面积为1*3=3
弹出栈顶元素4，此时栈顶元素为1，此时长度为6-1-1=4，面积为4*2=8
弹出栈顶元素1，此时栈为空，此时长度为6，面积为1*6=6
注意：元素遍历完之后，栈顶元素对应的高度是小于等于其后所有矩阵的高度的，所以计算长度的时候要以矩阵个数来计算。*/

 class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
    // Exceptional Case: 
    if(n == 0){
      return 0;
    }
    if(n == 1){
      return heights[0];
    }
    // insert 0 height
    heights.push_back(0);
    stack<int> st;
    int ans = 0;
    for(int i = 0; i <= n; i++){
      if(st.empty() || heights[i] >= heights[st.top()]){
        st.push(i);
      }
      else{
        int top = st.top();
        st.pop();
        int w = st.empty()? i: i - 1 - st.top();
        ans = max(ans, heights[top] * w);
        i--;
      }
    }
    return ans;
    }
};

