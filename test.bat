@echo off

python -m ci.ci

.\dist\bin\lct %*
