#include <stdio.h>

void merge_sort(int a[], int length);

void merge_sort_recursion(int a[], int l, int r);

void merge_sorted_arrays(int a[], int l, int m, int r);


int binary_search(int a[], int target, int l, int r) {
    int result = -1;
    while (l <= r) {
        int m = l + (r - l) / 2; 
        
        if (a[m] == target) {
            result = m;
            r = m - 1; 
        } else if (a[m] < target) {
            l = m + 1; 
        } else {
            r = m - 1;
        }
    }
    return result;
}


int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int len = sizeof(arr) / sizeof(arr[0]);
	merge_sort(arr, n);
	
	int target[m];
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &target[i]);
	}
	
	for(int i = 0; i < m; i++)
	{
		int result = binary_search(arr, target[i], 0, n - 1);
		printf("%d\n", result == -1 ? -1 : result + 1);
	}
	return 0;
}

void merge_sort(int a[], int length)
{
	merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;
		
		merge_sort_recursion(a, l, m);
		merge_sort_recursion(a, m + 1, r);
		
		merge_sorted_arrays(a, l, m, r);
	}
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
	int left_len = m - l + 1;
	int right_len = r - m;
	
	int temp_left[left_len];
	int temp_right[right_len];
	
	for(int i = 0; i < left_len; i++)
	{
		temp_left[i] = a[l + i];
	}
	
	for(int i = 0; i < right_len; i++)
	{
		temp_right[i] = a[m + i + 1];
	}
	
	int i = 0, j = 0, k = l;
	while(i < left_len && j < right_len)
	{
		if(temp_left[i] <= temp_right[j])
		{
			a[k] = temp_left[i];
			i++;
		}
		
		else
		{
			a[k] = temp_right[j];
			j++;
		}
		k++;
	}
	
	while(i < left_len)
	{
		a[k] = temp_left[i];
		i++;
		k++;
	}
	
	while(j < right_len)
	{
		a[k] = temp_right[j];
		j++;
		k++;
	}
}
