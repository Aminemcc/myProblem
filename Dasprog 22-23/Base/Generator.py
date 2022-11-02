import random
cons_nums = (0, (1 << 64) - 1)
# cons_nums = (0, 1000)
cons_base = (2, 64)
print(cons_nums)


def gen_palindrom(base, bit):
    num = 0
    bits = []
    limit = (bit + 1) >> 1
    cur = 1
    while(bit >= limit ):
        if(not bool(bits)):
            temp = random.randint(1, base - 1)
        else:
            temp = random.randint(0, base - 1)
        if(temp * cur + num > cons_nums[1]):
            break
        num += temp * cur
        cur *= base
        bits.append(temp)
        bit -= 1
    for i in bits[::-1]:
        if(i * cur + num > cons_nums[1]):
            break
        num += i * cur
        cur *= base
    return (num, base)


def generate(file, inputs):

    filename_in = f"secret_{file}.in"
    with open(filename_in, "w") as outfile:
        for i in range(inputs):
            gen_pal = random.randint(0,1)
            if(gen_pal == 1):
                num , base = gen_palindrom(random.randint(cons_base[0], cons_base[1]), random.randint(1, 20))
            else:
                num = random.randint(cons_nums[0], cons_nums[1])
                base = random.randint(cons_base[0], cons_base[1])
            outfile.write(f"{num} {base}\n")
        outfile.write("-1 -1\n")

    return None

# generate(1, 10)
# generate(2, 5)
# generate(3, 100)
# generate(4, 1000)
# generate(5, 10000)
# generate(6, 100000)
generate(7, 500000)