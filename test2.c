int sum(int n)
{
	int result;
	int i;
	
	i = 1;
	result = 0;

	while(i<=n)
	{
		result = result + i;
		i = i + 1;
	}

	return result;
}

void main(void)
{
	int n;
	int s;

	n = input();
	s = sum(n);
	output(s);
}
