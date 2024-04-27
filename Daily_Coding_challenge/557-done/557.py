def count_x_in_square_matrix_o_n(n,x):  
    cnt=0;
    for i in range(2,n+1):
        if x % i == 0 and x/i<=n:
            cnt+=1
    return cnt

def count_x_in_square_matrix_o_n_2(n,x):
    if n  ==0 and x ==0 and x > n*n:
        return 0
    if n == 1:
        if x !=1:
            return 0;
        return 1;
    i =1    
    cnt=0;
    while (i*i <x) :
        if x %i ==0 and x <= n *i:
            cnt+=2
        i+=1
        if i*i == x :
            cnt+=1
            
        #print("{} {} ".format(i,cnt))

    return cnt
if __name__ == "__main__":
    print(count_x_in_square_matrix_o_n_2(6,14))
    
    
    """
    count_x_in_square_matrix_o_n
        time complexity =  O(n)
        space complexity = O(1)

    count_x_in_square_matrix_o_n_2
        time complexity =  O(sqrt(n))
        space complexity = O(1)
    """