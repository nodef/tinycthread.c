#!/usr/bin/env bash
URL="https://github.com/tinycthread/tinycthread/archive/refs/heads/master.zip"
ZIP="${URL##*/}"
DIR="tinycthread-master"


# Build the library
build() {
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to tinycthread/ ..."
rm -rf tinycthread
mkdir -p tinycthread
cp -rf ".build/$DIR/source"/* tinycthread/
echo ""
}


# Test the library
test() {
echo "Running 01-hello_thread.c ..."
clang -I. examples/01-hello_thread.c  && ./a && echo -e "\n"
echo "Running 02-mutex_example.c ..."
clang -I. examples/02-mutex_example.c && ./a && echo -e "\n"
}


# Main
if [[ "$1" == "test" ]]; then test; else build; fi
