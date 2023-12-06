# Group 6 CE320

## How to build & run

To compile a binary to run you will need to use make. This will run all the G++ commands to compile and link the project.

```shell
make
./bin/main <filename> <pd/rl>
```
- Replace `<filename>` with the logo file, such as `./assets/poli.lgo`
- If `pd` is passed in, the binary will run the first iteration UI (PDCurses). If `rl` it runs the second iteration UI (Raylib).

## Running Test

```shell
make test
./bin/test_main
```

## Run tests & generate xUnit and code coverage reports

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
