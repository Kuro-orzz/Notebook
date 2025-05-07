#!/usr/bin/env python3
from setuptools import find_packages, setup

setup(
    name='online-judge-verify-helper',
    version='5.6.0',
    author='Kimiyuki Onaka',
    author_email='kimiyuki95@gmail.com',
    url='https://github.com/kmyk/online-judge-verify-helper',
    license='MIT License',
    description='',
    python_requires='>=3.8',
    install_requires=[
        'colorlog',
        'pyyaml',
        'online-judge-tools >= 11.3.0',
        'setuptools',
        'toml',
        'importlab',
    ],
)
