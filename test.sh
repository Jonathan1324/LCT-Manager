python3 -m ci.ci

cd test
../dist/bin/lct $@
cd ..
