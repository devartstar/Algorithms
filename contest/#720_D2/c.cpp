/*
Hidden Permutation
A number of length n - p1p2p3p4...pn
input - a number(t), indices (i,j), intiger(x)

	i=1;
	max_turns=int)Math.floor(3n/2)+30;
	while(i<max_turns){
		if(t==1){
			return max(min(x,pi),min(x+1,pj))
		}
		else if(t==2){
			return min(max(x,pi),max(x+1,pj))
		}
		i++;
	}

*/
