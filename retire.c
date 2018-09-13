/*
 *Author(s): Collin Sipple, Victor Nguyen, Joe Wyrick
 *Date Created: 09/12/2018
 *Date Modified: 09/13/2018
 *Purpose: Calculate the interest and balance of a 401(k) given user input.
 */
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main(int argc, char **argv){

  if(argc != 6) {
    printf("ERROR: INVALID COMMAND INPUTS\n");
    return 0;
  }

  double startBalance = atof(argv[1]);
  double monthContribute = atof(argv[2]);
  double rateReturn = atof(argv[3]);
  double rateInflate = atof(argv[4]);
  int years = atoi(argv[5]);
  double interest = 0;
  double interestTotal = 0;
  
  if(monthContribute > (18500 / 12)) {
	printf("ERROR: EXCEEDS MONTHLY CONTRIBUTION LIMIT\n");
	return 0;
  }
  
  if(rateReturn < 0 || rateReturn > 1){
	printf("ERROR: INVALID DOMAIN\n");
	return 0;
  } else if(rateInflate < 0 || rateInflate > 1){
	printf("ERROR: INVALID DOMAIN\n");
	return 0;
  }
  
  printf("~~401(K) CALCULATOR~~\n");

  //Adjust the rate of return for inflation
  double inflatedRateReturn = ((1.0 + rateReturn) / (1.0 + rateInflate)) - 1.0;
  
  //Display Table of Results
  printf("Month     Interest     Balance\n");
  
  for(int month = 1; month <= (years * 12); month++) {
	
	//Compounding where interest comes from balance, then contribution is added
	interest = round((startBalance * (inflatedRateReturn / 12.0)) * 100.0) / 100.0;
	startBalance += (interest + monthContribute);
	
	printf("%5d $%11.2f $%10.2f\n", month, interest, startBalance);
	
	interestTotal += interest;
  }
  
  //Final totals
  printf("Total Interest Earned: $%.2f\n", interestTotal);
  printf("Total Nest Egg: $%.2f\n", startBalance);
  
  return 0;
}
