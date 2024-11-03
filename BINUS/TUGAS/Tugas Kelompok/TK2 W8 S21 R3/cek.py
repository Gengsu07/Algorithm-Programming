with open("BINUS/TUGAS/Tugas Kelompok/TK2 W8 S21 R3/db.csv",'r') as file:
    file = file.read()
    for line in file.splitlines():
        print(line.strip())
