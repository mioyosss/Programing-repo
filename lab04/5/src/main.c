int main()
{
	float x = 1.5;
	float y;
	if (x >= -3 && x < -1){
	y = -1 * x -1;
	}else if (x == -1){
	y = 0;
	}else if(x > -1 && x < 0){
	y = x + 1;
	}else if(x == 0){
	y = 1;
	}else if(x > 0 && x < 1){
	y = 1 - x;
	}else if(x == 1){
	y = 0;
	}else if(x > 1 && x <= 3){
	y = x - 1;
	} 

	return 0;
}
