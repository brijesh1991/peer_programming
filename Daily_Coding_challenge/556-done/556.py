import os 

def read_number_line_by_line(path):
    with open(path,"r") as f:
        input = []
        for line in f:
            number= int(line.strip())
            input.append(number)
    return input

def read_number_single_line_with_space(path):
    with open(path,"r") as f:
        number = f.read().split(" ")
        input = []
        for i in number:
            input.append(int(i))
    return input

def check_single_swap_work():
    input = read_number_single_line_with_space("linear.txt")
    print(input)
    
    dip= -1
    index=[]
    for i in range(0,len(input)):
        if dip != -1:
            if input[i-1]> input[i]:
                index.append(i-1)
        else:
            dip=0
    
    if len(index) !=1:
        print("dips present at index {}".format(index))
        return False
    
    print(index)
    
    if len(input) ==2 and index[0] ==0 and input[1]>1:
        print("can insert 1 in index 0")
        return True
    elif len(input) ==2 and index[0] ==0 and input[1]==1:
        print("can insert {} value in index 1".format(input[0]+1))
        return True
    else:
        if input[index[0]+1]-input[index[0]-1] ==2:
            print("can1 insert {} at index {}".format((input[i+1]+input[i-1])/2, index[0]))
            return True
        elif  input[index[0]+1]-input[index[0]-1] <2:
            print("cannot insert any value at index {}".format(index[0]))
            return False
        else:
            print("can2 insert {} at index {}".format((input[i-1]+1), index[0]))
            return True
            
        
        
        

if __name__ == "__main__":
    print(check_single_swap_work())