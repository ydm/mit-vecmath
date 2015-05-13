CXXFLAGS = -Wall -Wextra -pedantic -fPIC
objects =  Matrix2f.o Matrix3f.o Matrix4f.o Quat4f.o Vector2f.o Vector3f.o Vector4f.o
output = ./output

vecmath: $(objects) headers
	$(CXX) -shared -Wl,-soname,libvecmath.so.1 -o $(output)/libvecmath.so.1.0 $(objects)
	cd $(output)
	ln -sf libvecmath.so.1.0 $(output)/libvecmath.so
	ln -sf libvecmath.so.1.0 $(output)/libvecmath.so.1

headers:
	mkdir -p $(output)/vecmath
	cp *.h   $(output)/vecmath

Matrix2f.o: Matrix2f.h Vector2f.h
Matrix3f.o: Matrix2f.h Matrix3f.h Quat4f.h Vector3f.h
Matrix4f.o: Matrix2f.h Matrix3f.h Matrix4f.h Quat4f.h Vector3f.h Vector4f.h
Quat4f.o: Quat4f.h Vector3f.h Vector4f.h
Vector2f.o: Vector2f.h Vector3f.h
Vector3f.o: Vector2f.h Vector3f.h
Vector4f.o: Vector2f.h Vector3f.h Vector4f.h

.PHONY: clean
clean:
	rm -f $(objects)
	rm -fr $(output)
