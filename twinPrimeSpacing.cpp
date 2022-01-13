#include <iostream>
#include <math.h> 
#include <map>
#include <algorithm>    // std::sort
#include <vector>

bool isPrime(int z){
	for(int i = 2; i <= z/2; i++){
		if(z%i==0){
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]){
	std::cout<<"WELCOME TO THE TWIN PRIME WORLD!"<<std::endl;
	int last_prime = 2;
	std::map<int, int> twin_prime_map;
	for( int i = 3; i < 20000; i++ ){
		if(isPrime(i)){
			if( (i - last_prime) == 2){
				std::cout<<"TWIN PRIME :: "<< last_prime << " AND "<< i << std::endl;
				twin_prime_map.insert(std::pair<int,int>(last_prime, i));
			}
			last_prime = i;
		}
	}
	bool flag = false;
	int last_first = 0;
	int q = 1;
	std::vector<int> primeSpacingVector;
	for(auto const&x : twin_prime_map){
		if(flag){
			std::cout << "SPACING BETWEEN PRIMES :: #" << q << ": " << x.second << " - " << last_first << " = " << x.second - last_first << std::endl;
			primeSpacingVector.push_back(x.second - last_first);
			q++;
		} else {
			flag = true;
		}
		last_first = x.first;
	}
	std::sort(primeSpacingVector.begin(), primeSpacingVector.end());
	for (auto & element : primeSpacingVector) {
    	std::cout<<element<<" ";
	}
}
