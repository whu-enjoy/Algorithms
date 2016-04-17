# max_min_heap
	这个文件夹下是堆的一些用法

1.Max_heap.c
	最大堆的使用方法
	int SiftUp(int heap[],int i);  最大堆的上移操作
	int SiftDown(int heap[], int i, int n); 最大堆的下移操作
	int Insert(int oldheap[], int n, int newheap[], int x) 最大堆的插入操作
	int Delete(int oldheap[], int n, int newheap[], int i) 最大堆的删除操作
	int DeleteMax(int heap[], int n) 删除最大堆的最大值
	int MakeHeap(int heap[], int n)  创建最大堆
	int HeapSort(int heap[], int n)  最大堆的排序操作
	int ShowHeap(int heap[], int n)  最大堆的显示


2.Min_heap.c
	最小堆的使用方法
	int SiftUp(int heap[], int i) 最小堆的上移操作
	int SiftDown(int heap[], int i, int n) 最小堆的下移操作
	int Insert(int oldheap[], int n, int newheap[], int x) 最小堆的插入操作
	int Delete(int oldheap[], int n, int newheap[], int i) 最小堆的删除操作
	int DeleteMin(int heap[], int n) 删除最小堆的最小元素
	int MakeHeap(int heap[], int n) 最小堆的创建操作
	int HeapSort(int heap[], int n) 最小堆的排序操作
	int ShowHeap(int heap[], int n) 最小堆的显示
