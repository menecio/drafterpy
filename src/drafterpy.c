#include <Python.h>
#include <drafter/drafter.h>

static PyObject *drafterpy_parse_blueprint_to(PyObject *self, PyObject *args){
    char *blueprint;
    char *format;
    char *result = NULL;

    drafter_options options;
    options.sourcemap = true;

    if(!PyArg_ParseTuple(args, "ss", &blueprint, &format))
        return NULL;

    if(strcmp("json", format) == 0)
        options.format = DRAFTER_SERIALIZE_JSON;
    else if (strcmp("yaml", format) == 0)
        options.format = DRAFTER_SERIALIZE_YAML;
    else {
        fprintf(stderr, "Fatal error: Invalid output format\n");
        return NULL;
    }
    drafter_parse_blueprint_to(blueprint, &result, options);

    return Py_BuildValue("s", result);

}

static PyObject *drafterpy_check_blueprint(PyObject *self, PyObject *args){
    char *blueprint;
    char *format;
    
    if(!PyArg_ParseTuple(args, "s", &blueprint))
        return NULL;
    
    drafter_result* result = drafter_check_blueprint(blueprint);
    
    if (result == NULL)
        return Py_BuildValue("O", Py_True);
        
    drafter_free_result(result);
    return Py_BuildValue("O", Py_False);
    
}

static PyMethodDef drafterpy_methods[] = {
    {"parse_blueprint_to", (PyCFunction)drafterpy_parse_blueprint_to, METH_VARARGS, 
     "Parses a blueprint into JSON or YAML."},
    {"check_blueprint", (PyCFunction)drafterpy_check_blueprint, METH_VARARGS, 
     "Verify given blueprint correctness."},
    {NULL, NULL, 0, NULL}   /* Sentinel */
};

static char drafterpy_docstring[] =
    "Python bindings for libdrafter.\nDrafter is a Snowcrash parser harness.";
    
static struct PyModuleDef drafterpymodule = {
    PyModuleDef_HEAD_INIT,
    "drafterpy",
    drafterpy_docstring,
    -1,
    drafterpy_methods
};

PyMODINIT_FUNC PyInit_drafterpy(void){
    return PyModule_Create(&drafterpymodule);
}

int main(int argc, char *argv[]){
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
    }

    /* Add a built-in module, before Py_Initialize */
    PyImport_AppendInittab("drafterpy", PyInit_drafterpy);

    /* Pass argv[0] to the Python interpreter. REQUIRED */
    Py_SetProgramName(program);

    /* Initialize the Python Interpreter. REQUIRED */
    Py_Initialize();

    PyImport_ImportModule("drafterpy");

    PyMem_RawFree(program);
    return 0;
}
