# Import necessary functions from setuptools for building Python extensions
from setuptools import setup, Extension

# Configure the package setup using setuptools
setup(
    name="console",  # Distribution name of the package
    
    # List of extension modules to build (in this case, our C extension)
    ext_modules=[
        Extension(
            "console",  # Name of the resulting Python module (must match PyInit name)
            
            # List of source files to compile (path to our C implementation)
            sources=["src/console/console.c"],
            
            # Optional: Add include directories if needed
            # include_dirs=[...]
            
            # Optional: Link against specific libraries if needed
            # libraries=[...]
            
            # Optional: Add custom compiler flags if needed
            # extra_compile_args=[...]
        )
    ],
    
    # Optional: Add package metadata
    # version="1.0",
    # description="Python extension for console operations",
    # author="Your Name",
    # author_email="your.email@example.com",
)

# To build the extension:
# Run: python setup.py build_ext --inplace
# This will compile the C code and create a shared library (.pyd on Windows/.so on Unix)

# After building, the module can be imported in Python with:
# import console
# console.WriteLine("Hello from C extension!")