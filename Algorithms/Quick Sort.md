```
void Qsort(vector<int>& nums, int head, int tail) {
        int mid = (head + tail) / 2;
        if (nums[head] > nums[mid]) swap(nums[head], nums[mid]);
        if (nums[head] > nums[tail]) swap(nums[head], nums[tail]);
        if (nums[mid] > nums[tail]) swap(nums[mid], nums[tail]);
        if (tail - head > 2) {
            int pivot = nums[mid];
            swap(nums[mid], nums[tail - 1]);
            int i = head + 1;
            int j = tail - 2;
            while (true) {
                while (nums[i] < pivot) i++;
                while (nums[j] > pivot) j--;
                if(i < j){
                    swap(nums[i], nums[j]);
                    i++;
                    j--;
                } 
                else break;
            }
            swap(nums[i], nums[tail - 1]);
            if (i - head > 1) Qsort(nums, head, i - 1);
            if (tail - i > 1) Qsort(nums, i + 1, tail);
        }
    }
```