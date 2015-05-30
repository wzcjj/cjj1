def print_mat(mat):
    print("Looking for",mat)
    while True:
        line = (yield)
        if mat in line:
            print(line)
matc = print_mat("python")
matc.__next__()
matc.send("hello world")
matc.send("pythonis cool")
matc.close()
