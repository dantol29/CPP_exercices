template <typename T, typename F>
void	iter(T* a, int size, void (*function)(F& a))
{
	int i = 0;
	
	while (i < size)
		function(a[i++]);
}