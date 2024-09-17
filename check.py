import shutil
import os

print("checking if you have CMake")
if shutil.which("cmake") is None:
    print("CMake not found")
    exit(1)
else:
    print("CMake found")


print("checking if you have GCC")
if not shutil.which("gcc") is None:
    print("GCC found")
elif not shutil.which("g++") is None:
    print("G++ found")
elif not shutil.which("clang") is None:
    print("Clang found")
elif not shutil.which("clang++") is None:
    print("Clang++ found")
else:
    print("you have no compiler")
    exit(1)

print("making build directory")
os.mkdir(".build")
os.chdir(".build")
print("running cmake")
os.system("cmake ..")
