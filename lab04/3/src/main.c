int main ()
{	
	int k = 3;
	int m = 2;
	int n = 1;
	
	
	 if (k > m && m > n){
	 int tmp = k;
	 k = n;
	 n = tmp;
	 
	 }else if (k > n && n > m){
	 int tmp = k;
	 k = m;
	 int tmp1 = n;
	 n = tmp;
	 m = tmp1;
	 
	 } else if (m > n && n > k){
	 int tmp = m;
	 m = n;
	 n = tmp;
	 
	 }else if (m > k && k > n){
	 int tmp = k;
	 k = n;
	 int tmp1 = m;
	 m = tmp;
	 n = tmp1;
	 
	 }else if(n > k && k > m){
	 int tmp = k;
	 k = m;
	 m = tmp;
	 }
	  
	 
	return 0;
}
