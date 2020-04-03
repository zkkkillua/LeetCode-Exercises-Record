## 框架
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
    }
};
```
  
练习排序的题，要求复杂度`O(nlogn)`。  
  
## 1. 憨批解法之直接STL sort()
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};
```
  
## 2. 计数排序counting sort
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
  
同样，计数排序的空间复杂度也不一定必须是`O(range)`的。  
当`range`很大而数据很少时，申请一个大空间是非常浪费的，因此可以申请一个大小为`n`的空间作为`counter`。  
`counter[i]`不再是数据`i`出现的次数，而是小于和在数据左侧等于`nums[i]`这个数据的数据个数。  
这样就直接获得了`nums[i]`这个数据在有序数组中的位置，并且还保证了排序的稳定性。  
获取`counter`数组的时间复杂度为`O(n^2)`。排序的空间复杂度为`O(n)`。  
![stable_counting_sort_capable_with_with_range](pics/counting_stable_O(n).png)  
  
## 3. 堆排序heap sort
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
  
## 4. 选择排序selection sort
每次选最大的，交换到最后面。~~稳定排序~~，时间`O(n^2)`，空间可原地排`O(n)`。  
选择排序是不稳定的，之前只考虑到了`5,5,2,2`选择后面的`5`与`2`交换，却没想到后面的`2`被换到了前面。  
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int left = n; left > 1; left--) {
            int maxIndex = 0;
            // bool sorted = true;
            for (int i = 1; i < left; i++) {
                maxIndex = nums[i] >= nums[maxIndex] ? i : maxIndex;
                // if (maxIndex != i)
                //     sorted = false;
            }
            // if (sorted)
            //     return nums;
            swap(nums[maxIndex], nums[left - 1]);
        }

        return nums;
    }
};
```
及时终止的选择排序：当数据已有序时，上述代码仍需要每次遍历比较，浪费时间。  
判断有序的条件就是，当在一次找最大值索引的过程中，该索引一直在变化，说明已有序。  
代码以注释的形式添加进上述代码中。  
  
## 5. 冒泡排序bubble sort
通过交换把最大值冒泡到最右侧。时间`O(n^2)`，空间原地重排`O(n)`，稳定排序。  
缺点是需要大量的交换操作，最差需要`O(n^2)`次（当序列为从大到小时）  
及时终止的冒泡排序：当一次循环中一直没有交换，说明已有序。同样以注释方式展示。  
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int left = n; left > 1; left--) {
            // int sorted = true;
            for (int i = 0; i < left - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                    // sorted = false;
                }
            }
            // if (sorted)
            //     return nums;
        }

        return nums;
    }
};
```
  
## 6. 插入排序insertion sort
将右侧无序部分的最左侧的数据插入到左侧有序部分的对应位置，时间`O(n^2)`，空间原地重排`O(n)`，稳定排序。  
插入方法是左侧有序部分的右侧数据不断向右移动，直到找到数据应该在的位置，并且已为其空出位置。  
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int value = nums[i];
            int loc = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] > value) {
                    nums[j + 1] = nums[j];
                    loc = j;
                } else {
                    loc = j + 1;
                    break;
                }
            }
            nums[loc] = value;
        }

        return nums;
    }
};
```