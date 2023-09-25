# Hello world in Drogon

From Drogon docs :

https://drogonframework.github.io/drogon-docs/#/ENG-03-Quick-Start

## Static Site

```bash
drogon_ctl version

drogon_ctl create project hello-drogon
cd hello-drogon

cd build
cmake ..
make

# Create index.html en ./build
echo '<h1>Hello Drogon!</h1>' >>index.html

# Execute program in ./build
./hello-drogon 

# The default root path is "./"

# open http://localhost:5555/index.html

``` 

## Dynamic Site

```bash

cd controllers

drogon_ctl create controller TestCtrl

cd ../build
cmake ..
make
./hello-drogon


```

## Drogon's CSP (C++ Server Pages)

```bash

cd views 

# Create ListParameters.csp and

drogon_ctl create view ListParameters.csp

# http://localhost/list_para?p1=a&p2=b&p3=c


```