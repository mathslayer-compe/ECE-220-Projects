int i,j;
  for(i=0; i<9; i++)
  {
	for(j=0;j<9;j++)
        {
		if(sudoku[i][j]==0)
		{
			for(int num=1; num<=9; num++)
  			{
				if(is_val_valid(num,i,j,sudoku))
        			{
					sudoku[i][j]=num;
					if(solve_sudoku(sudoku))
                			{
						return 1;
                			}
					else
					{
						sudoku[i][j]=0;
					}
					
			}
			return 0;
  	
  		 }
  		
		}
        }	
	
  }
  
  // END TODO.
}
