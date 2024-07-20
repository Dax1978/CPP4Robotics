import library

print(library.add())
print(library.subtract(10, 3))

print(library.the_answer)
print(library.what)

p = library.Pet("Richard")
print(p)
print(p.name)
p.name = "Bob"
print(p.name)

v1 = library.Vector3D()
print("v1:", v1.toString())
v2 = library.Vector3D(7., 7., 7.)
print("v2:", v2.toString())
v3 = library.Vector3D(v2)
print("v3:", v3.toString())
print("v1 == v3:", v1 == v3)
print("v2 == v3:", v2 == v3)
print("Magnitude v1:", v1.length())
print("Magnitude v3:", v3.length())
-v3
print("v3:", v3.toString())
v2 + v3
print("v2:", v2.toString())
v2.X = 5
v2.Y = 6
v2.Z = 7
print("v2:", v2.toString())
v2 * 2
print("v2:", v2.toString())
v2 / 2
print("v2:", v2.toString())
print(v2 * v3)
# print("v4:", v4.toString())
v4 = v2.cross(v3)
print("v4:", v4.toString())
v5 = v3.sum(v2)
print("v5:", v5.toString())
v6 = v3.sub(v2)
print("v6:", v6.toString())
v7 = v6
print(v7.norm().toString())