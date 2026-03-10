#define PY_SSIZE_T_CLEAN
#include <Python.h>

// The actual C function logic
static PyObject* method_multiply(PyObject* self, PyObject* args) {
    double a, b;
    // "dd" means we expect two doubles
    if (!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }
    return PyFloat_FromDouble(a * b);
}

// Method table linking Python names to C functions
static PyMethodDef MathMethods[] = {
    {"multiply", method_multiply, METH_VARARGS, "Multiplies two numbers."},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef fastmathmodule = {
    PyModuleDef_HEAD_INIT,
    "fast_math_c", // Module name
    "C extension for fast math",
    -1,
    MathMethods
};

// Module initialization
PyMODINIT_FUNC PyInit_fast_math_c(void) {
    return PyModule_Create(&fastmathmodule);
}
