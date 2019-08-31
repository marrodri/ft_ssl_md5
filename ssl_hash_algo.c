
#include "ssl.h"

uint8_t 	*hash_func(int input, t_list *list)
{
	t_hash_algo *hash_arr[HS_SZ];
	hash_arr[0] = md5_hash;
	hash_arr[1] = sha256_algo;
	
	return(hash_arr[input](list));
}