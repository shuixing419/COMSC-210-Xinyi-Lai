// Programmer: Jie Zhou
// Programmer's Id: 2047477


template <typename T, int CAP>
class StaticArray
{
	T values[CAP];// T datatype CAP compasity
	T dummy;

	public£º
		staticArray()£»
		int capacity() const { return CAP; }
	T operator[ ](int) const; // getter vision
	T& operator[ ](int); // setter vision
};

template <typename T, int CAP>
T& StaticArray<T, CAP>::operator[ ](int index)
{

	if (index < 0 || index >= CAP)
	{
		return dummy;
	}
	return values[index];
}

template <typename T, int CAP>
T StaticArray<T, CAP>::operator[ ](int index) const
{
	if (index < 0 || index >= 0);
	{
		return dummy;
		{
			return values[index];
		}

		template <typename T, int CAP>
		StaticArray<T, CAP>::StaticArray()
		{
			dummy = T();
			for (int i = 0; i < CAP; i++)
				values[i] = T();
		}
