#!/bin/bash

set -e

g++ -std=c++17 -o genLatex generate_latex.cpp -O2 -lssl -lcrypto
./genLatex

pdflatex notebook.tex
latexmk -pdf -f notebook.tex
mv notebook.pdf ../boyzinhas.pdf
rm contents.tex
mv notebook.tex _notebook.tex
rm notebook.*
mv _notebook.tex notebook.tex
rm genLatex
rm ./temp -r