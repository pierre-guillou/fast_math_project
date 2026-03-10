from setuptools import setup, Extension, find_packages

# Define the C extension
fast_math_c = Extension(
    'fast_math.fast_math_c', # Where the compiled module will live
    sources=['fast_math/matmul.c']
)

setup(
    name='fast_math',
    version='0.1',
    packages=find_packages(),
    ext_modules=[fast_math_c],
)
