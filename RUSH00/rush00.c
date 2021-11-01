void ft_putchar(char c);
void print_col (  int y, char start, char middle , char end ) {

	int col =0;
	while (col < y ) {
	
		if ( col ==0 ) {
			ft_putchar (start) ;
		}
		else if ( col == y-1) {
			ft_putchar(end);
		}
		else {
			ft_putchar(middle);
		}
	col++;	
	}
}


void	rush(int x, int y) {
	int tempx =0;
	// row 만 따질 것 
	while (tempx < x ) {
	
		if ( tempx ==0 ) {	
			print_col(y,'o','-','o');
		}
		else if ( tempx == x-1 ) {
			print_col(y,'o','-','o');
		}
		else {
			print_col (y,'|', ' ', '|');
		}
		tempx++;
		ft_putchar('\n');
	}
}
