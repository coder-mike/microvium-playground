# Microvium Playground

This is a throw-away project I'm using to debug different scenarios in [Microvium](https://github.com/coder-mike/microvium). I have this cloned as a subdirectory under my Microvium directory, so it can access both the compiler and latest distributable code using relative paths like `../dist-c/microvium.h`.

## Build JS

```sh
node ../dist/cli.js src/main.js -s src/generated/snapshot.mvm-bc
```

If you're using Visual C++, I've set this up as a pre-build step in the project, so just hitting "play" in the IDE will build both the JS and C++ and run it.

## Build and Run C++

I'm on Windows, so it was convenient for me to use Visual Studio. I'm using Visual Studio 2022. See `proj/temp-proj.sln`.