#!/usr/bin/env python3

import os
import sys


try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension


with open('./lib/__init__.py') as src:
    ver = [line.split("'")[1] for line in src.readlines()
           if line.startswith('__version__')][0]


with open('README.md') as file:
    long_descr = file.read()

sources = ['drafterpy.c', ]


depends = ['drafterpy.c', ]


libdirs = []
macros = []
incldirs = []
if sys.platform == 'darwin':
    libdirs.append('/usr/local/lib')
    incldirs.append('/usr/local/include')
    macros.append(('MACOSX', 1))


sources = [os.path.join('src', s) for s in sources]
depends = [os.path.join('src', d) for d in depends]
libs = ['drafter', ]


extension = Extension(
    'drafterpy._drafter', 
    libraries=libs,
    sources=sources,
    depends=depends,
    define_macros=macros,
    library_dirs=libdirs)


setup(
    name='DrafterPy',
    version=ver,
    ext_modules=[extension],
    description='Python bindings for libdrafter',
    long_description=long_descr,
    platforms=['any'],
    author='menecio',
    author_email='aristobulo@gmail.com',
    url='https://github.com/menecio/drafterpy',
    package_dir={'drafterpy': 'lib', },
    packages=['drafterpy', ],
    license='MIT License',
    keywords=['python3', 'api-blueprint', ],
    classifiers=[
        'Development Status :: Alpha',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Operating System :: Unix',
        'Programming Language :: C',
        'Programming Language :: Python :: 3',
        'Topic :: Software Development :: Libraries :: Python Modules', ], )
