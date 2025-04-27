/*
Use the command "python setup.py build_ext --inplace" to build this file
*/
#include <Python.h>

// Function to be exposed in the Python module
static PyObject* WriteLine(PyObject* self, PyObject* args) {
    const char* str;  // Variable to store the string received from Python

    // Parse the received arguments (format "s" = string)
    if (!PyArg_ParseTuple(args, "s", &str)) {
        return NULL;  // Return error if conversion fails
    }
    
    printf("%s\n", str);  // Prints the string to the console with a new line
    Py_RETURN_NONE;       // Returns None to Python (void function)
};

// Module method table - list of exposed functions
static PyMethodDef methods[] = {
    // Each entry contains:
    {"WriteLine",           // Method name in Python
     WriteLine,             // Corresponding C function
     METH_VARARGS,          // Flag indicating it receives positional arguments
     "Print a log."},       // Documentation string (__doc__)
     
    {NULL, NULL, 0, NULL}  // Sentinel - marks the end of the table (required)
};

// Python module configuration
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,  // Standard initialization (required)
    "console",              // Module name (must match PyInit's)
    NULL,                   // Module documentation (can be NULL)
    -1,                     // Size for module state (-1 = global module)
    methods                // Module method table (our functions)
};

// Module initialization function (must be named PyInit_<modulename>)
PyMODINIT_FUNC PyInit_console(void) {
    // Creates and returns the module object using the defined configuration
    return PyModule_Create(&module);
};