/*the maximum of three numbers*/
int max(int x, int y, int z)
{
	int biggest;
	biggest = x;
	if(y>biggest)  /*comment example*/
		biggest = y;
	if(z>biggest) biggest = z;

	return biggest;
}

void main(void)
{
	int x;
	int y;
	int z;
	int biggest;

	x = input();
	y = input();
	z = input();

	biggest = max(x, y, z);
	output(biggest);
}
