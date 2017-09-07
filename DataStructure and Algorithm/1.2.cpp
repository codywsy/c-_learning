low=0;
high=List.length-1;
当low<high时
	mid=(high-low)/2;
	如果( list[mid]<X )
		low=mid+1;
	如果( list[mid]>x )
		high=mid-1;
	否则
		返回mid
		
关于时间复杂度和空间复杂度：from others

假设数据规模为n，每次查找后范围缩小一半，直到最后只剩下一个元素：
第零次：在 n 个元素中查找
第一次：在 n / 2 个元素中查找
第二次：在 n / 2 / 2 个元素中查找
第三次：在 n / 2 / 2 / 2 个元素中查找
...
第 k 次：在 n / (2 ^ k) 个元素中查找

最坏情况下，二分法每次将查找范围缩小一半，直到最后只剩下最后一个元素，也就是最后一次是在 1 个元素中查找，设最坏情况下要找 k 次，那么：
n / (2 ^ k) = 1

可解得，k = log(n)，也就是最坏情况下要查找 log(n) 次，设每次查找（元素比较等操作）需要的时间为 C，则最坏情况下需要耗费总时间为：
T(n) = C * log(n)

因此，最坏情况下的时间复杂度为 O(log(n))
最好情况就是第一次查找就找到了，O(1)
查找不需要独立的空间，所以空间复杂度即为数据的存储空间 O(n)