## 框架
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
    }
};
```
  
练习排序的题，要求复杂度`O(nlogn)`。  
  
## 1. 憨批解法之直接sort()
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};
```
  
## 2. 计数排序
计数排序的时间复杂度是`O(n+range)`的，空间复杂度是`O(range)`。  
由于计数排序不是比较排序，所以不受最优时间复杂度是`O(nlogn)`的限制。  
计数排序是稳定的排序方法，但是下面的代码不是稳定的。  
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int *counter = new int[100010]{};   //需要加{}进行初始化
        for (int i = 0; i < nums.size(); i++)
            counter[nums[i] + 50000]++;
        
        int k = 0;
        for (int i = 0; i <= 100000; i++) {
            if (counter[i] != 0) {
                for (int j = counter[i]; j > 0; j--)
                    nums[k++] = i - 50000;
            }
        }

        delete []counter;
        return nums;
    }
};
```
稳定的计数排序如下所示，A是待排数组，B是排序之后的数组，k是范围：  
![stable_counting_sort](pics/stable_counting_sort.png)  
大致流程是：  
1. `C[i]`首先记录`i`的出现次数，遍历数组`A`。  
2. `C[i]`之后作为记录小于等于`i`的元素的出现次数，即`C[i] = C[i] + C[i - 1]`。  
3. 从数组`A`的最后一个元素开始，倒着向前遍历`A[i]`。  
   - 检查`C[A[i]]`获得元素`A[i]`的出现次数。  
   - 由于`A[i]`元素必存在，且通过`C[A[i]]`获得了小于等于`A[i]`的元素的个数，因此`A[i]`在有序数组`B`中的位置最大为`C[A[i]] - 1`。  
   - `B[C[A[i]] - 1] = A[i]`，然后`C[A[i]]--; i--;`.  
   - 逆序遍历完`A`数组之后，`C[i]`就变成了小于i的元素的个数，`B`为有序的新数组。  
4. 以上方法就相当于倒着每次把数组`A`中最后的元素放到它可能在的最后的位置，从而保证了是稳定的。  
  
![counting_process1](pics/counting_1.png)  
![counting_process2](pics/counting_2.png)  
![counting_process3](pics/counting_3.png)  
  
## 3. 堆排序
时间复杂度`O(nlogn)`，空间上可以原地排。不稳定的排序。  
### 堆
由于堆是满二叉树，所以不需要定义节点的左右孩子，而直接通过索引运算就可以得到。  
以下以最大堆为例。  
#### 初始化`heapify`
从最后一个有子节点的节点开始，判断以它为根的部分是否为满足要求的堆，若不满足，则下沉。  
节点从最后一个开始，直到修改到根节点。由于修改之后以当前节点为根的堆就满足条件了，所以再修改之上的节点就下沉即可满足要求。  
修改一个节点是`O(logn)`，修改n个节点即为`O(nlogn)`。但heapify的复杂度是并不是`O(nlogn)`，而是`O(n)`，这个可以通过数学推导得出。  
当然，也可以最开始是一个空堆，然后插入n次，但这样的复杂度就是`O(nlogn)`，比heapify要复杂。  
```cpp
void heapify(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1)
        return;
    for (int i = (n - 2) / 2; i >= 0; i--) {
        int loc = i;
        while (loc <= (n - 2) / 2) {
            int child = 2 * loc + 1;
            if (child + 1 < n && nums[child] < nums[child + 1])
                child++;
            if (nums[loc] < nums[child]) {
                int temp = nums[loc];
                nums[loc] = nums[child];
                nums[child] = temp;
                loc = child;
            } else
                break;
        }
    }
}
```
  
#### 插入`push`
将节点添加到最后一个位置，然后判断是否需要对其进行上升操作。  
```cpp
void push(vector<int>& nums, int value)
{
    nums.push_back(value);
    int n = nums.size();
    int parent = (n - 2) / 2;
    while (parent >= 0) {
        int child = 2 * parent + 1;
        if (child + 1 < n && nums[child] < nums[child + 1])
            child++;
        if (nums[parent] < nums[child]) {
            int temp = nums[parent];
            nums[parent] = nums[child];
            nums[child] = temp;
            parent = (parent - 1) / 2;
        } else
            break;
    }
}
```
  
#### 删除`pop`
删除堆的根节点，然后将最后一个节点移动到根节点，对新的根节点判断是否需要下降。  
由于为了与题目对应，这里用vector作为存储工具，因为没有定义自己的size，所以用vector的resize()修改大小。  
```cpp
int pop(vector<int>& nums)
{
    int n = nums.size();
    int value = nums[0];
    nums[0] = nums[n - 1];
    nums.resize(--n);
    int loc = 0;
    while (loc >= (n - 2) / 2) {
        int child = 2 * loc + 1;
        if (child + 1 < n && nums[child] < nums[child + 1])
            child++;
        if (nums[loc] < nums[child]) {
            int temp = nums[loc];
            nums[loc] = nums[child];
            nums[child] = temp;
            loc = child;
        } else 
            break;
    }

    return value;
}
```
如果想删除堆中任意位置的元素，则删除方法是用最后一个元素覆盖当前位置，size--，然后对当前位置元素进行上浮或下沉。  
  
#### 堆排序
直接想到的方法是首先heapify建堆，然后每次弹出一个元素弹出到新的数组中。  
不过堆排序是可以in-place修改的。  
只需要把堆的根节点放到与数组最末尾的元素交换位置，然后size--不再考虑这个节点，就得到了一个最大值。这也是为什么从小到大排序需要大根堆的原因。  
这样做就相当于是弹出了：离开了堆，且将最后一个元素换到了根节点位置上。  
```cpp
class Solution {
public:
    void heapify(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return;
        for (int i = (n - 2) / 2; i >= 0; i--) {
            int loc = i;
            while (loc <= (n - 2) / 2) {
                int child = 2 * loc + 1;
                if (child + 1 < n && nums[child] < nums[child + 1])
                    child++;
                if (nums[loc] < nums[child]) {
                    int temp = nums[loc];
                    nums[loc] = nums[child];
                    nums[child] = temp;
                    loc = child;
                } else
                    break;
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heapify(nums);
        int last = n - 1;

        while(last > 0) {
            int temp = nums[0];
            nums[0] = nums[last];
            nums[last--] = temp;
            int loc = 0;
            while (last > 0 && loc <= (last - 1) / 2) {
                int child = loc * 2 + 1;
                if (child + 1 <= last && nums[child] < nums[child + 1])
                    child++;
                if (nums[loc] < nums[child]) {
                    int ttemp = nums[loc];
                    nums[loc] = nums[child];
                    nums[child] = ttemp;
                    loc = child;
                } else
                    break;
            }
        }

        return nums;
    }
};
```
  
