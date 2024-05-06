template <typename A>
void	swap(A& a, A& b){
	A tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename A>
const A&	min(const A& a, const A& b){
	return (a < b ? a : b);
}

template <typename A>
const A&	max(const A& a, const A& b){
	return (a > b ? a : b);
}