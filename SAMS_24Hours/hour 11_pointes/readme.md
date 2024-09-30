---
marp: true
theme: default
header: "**C Programming Language**"
footer: "hour 11 -Pointers"
size: 16:9
paginate: true
---

# Pointers

1. Deklarasi \*ptr
2. Inisiasi ptr = &variablelain
3. dereference(akses) \*ptr

---

# update _ptr == merubah nilai variabel yg direferensikan karena _ merujuk ke yg memory addresnya sudah di assignment

---

# multiple pointer dapat merujuk e memory location yng sama

---

- A pointer is a variable whose value points to another variable.
- A variable declared in C has two values: the left value and the right value.
- The left value of a variable is the address; the right value is the content of
  the variable.
- The address-of operator (&) can be used to obtain the left value (address) of
  a variable.
- The asterisk (\*) in a pointer declaration tells the compiler that the variable is a
  pointer variable.

---

- The dereference operator (\*) is a unary operator; as such, it requires only
  one operand.
- The \*ptr_name expression evaluates to the value pointed to by the pointer variable
  ptr_name, where ptr_name can be any valid variable name in C.
- If the pointer variable’s right value has been assigned the value 0, the pointer is a
  null pointer. A null pointer cannot point to valid data.
- You can update the value of a variable referred by a pointer variable.
- Several pointers can point to the same location of a variable in the memory.

---
