template <typename T>
void	iter(T* a, int size, void (*function)(T& a)){
	int i = 0;
	while (i < size && a[i]){
		function(a[i]);
		i++;
	}
}