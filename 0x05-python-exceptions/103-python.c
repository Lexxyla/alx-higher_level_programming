#include <Python.h>
#include <stdio.h>
#include <strings.h>
/**
 * My_PyBytes - prints some basic info about Python lists.
 * @op: pointer to a object
 * Return: no return
**/
char *My_PyBytes(PyObject *op)
{
	if (!PyBytes_Check(op))
	{
		PyErr_Format(PyExc_TypeError, "expected bytes, %.200s found",
				(((PyObject*)(op))->ob_type)->tp_name);
		return (NULL);
	}
	return (((PyBytesObject *)op)->ob_sval);
}
/**
 * print_python_float - prints python float
 * @p: pointer to a object
 * Return: no return
**/
void print_python_float(PyObject *p)
{
	double num;
	char output[500];
	int i = 0;

	printf("[.] float object info\n");
	fflush(stdout);
	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		fflush(stdout);
		return;
	}
	num = (((PyFloatObject *)(p))->ob_fval);
	snprintf(output, 500, "%lf", num);
	printf("  value: ");
	while (output[i] != '.')
		printf("%c", output[i++]);
	printf(".");
	i++;
	if (output[i] == '0')
		printf("0");
	else
	{
	while (output[i] != '0' && output[i] != '\0')
		printf("%c", output[i++]);
	}
	printf("\n");
	fflush(stdout);
}
/**
 *  print_python_bytes - prints some basic info about Python lists.
 * @p: pointer to a object
 * Return: no return
**/
void print_python_bytes(PyObject *p)
{
	int size;
	int i = 0;
	char *str;

	printf("[.] bytes object info\n");
	fflush(stdout);
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		fflush(stdout);
		return;
	}
	size =  (int)(assert(PyBytes_Check(p)), (((PyVarObject *)(p))->ob_size));
	printf("  size: %d\n", size);
	fflush(stdout);
	str =  My_PyBytes(p);
	printf("  trying string: %s\n", str);
	fflush(stdout);
	if (size >= 10)
		size = 9;
	printf("  first %d bytes:", size + 1);
	fflush(stdout);
	while (i <= size)
	{
		printf(" %02x", (unsigned int) *str++ & 0xFF);
		fflush(stdout);
		i++;
	}
	printf("\n");
	fflush(stdout);

}
/**
 * print_python_list - prints some basic info about Python lists.
 * @p: pointer to a object
 * Return: no return
**/
void print_python_list(PyObject *p)
{
	int sizeobj;
	int i;
	PyObject *p2;

	printf("[*] Python list info\n");
	fflush(stdout);
	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		fflush(stdout);
		return;
	}
	sizeobj = (((PyVarObject *)(p))->ob_size);
	printf("[*] Size of the Python List = %d\n", sizeobj);
	fflush(stdout);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
	fflush(stdout);
	for (i = 0; i < sizeobj; i++)
	{
		p2 = (((PyListObject *)(p))->ob_item[i]);
		printf("Element %d: %s\n", i, ((p2)->ob_type)->tp_name);
		fflush(stdout);
		if (strcmp(((p2)->ob_type)->tp_name, "bytes") == 0)
		{
			print_python_bytes(p2);
		}
		if (strcmp(((p2)->ob_type)->tp_name, "float") == 0)
		{
			print_python_float(p2);
		}
	}
}
