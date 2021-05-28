# OEIS ID A011784

starter = 2 # must be greater than 1

seq_len = 10

nums_list = [[starter]]

for i in range(1, seq_len):
    new_num_list = []
    last_num_list = nums_list[len(nums_list) - 1]
    cur_num = 1
    for j in range(len(last_num_list) - 1, -1, -1):
        temp = last_num_list[j]                                                      
        while temp:
            new_num_list.append(cur_num)
            temp -= 1
        cur_num += 1
    nums_list.append(new_num_list)


with open('out.txt', 'w') as f:
    for num_list in nums_list:
        f.write(str(sum(num_list)) + '\n')
    f.close()