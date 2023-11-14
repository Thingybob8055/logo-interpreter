# Group 6 CE320

## How to build & run

To compile a binary to run you will need to use make. This will run all the GCC commands to compile and link the project.

```shell
make
make run
```

## Running Test

```shell
make test
./bin/test_main
```

## Generate xUnit report

```shell
make gen_report
```

## Clean repository
### Remove all binaries and reports
```shell
make rm
```
### Remove object files
```shell
make clean
```