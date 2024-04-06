# CA5

## External C Libraries used
- [uthash](https://troydhanson.github.io/uthash/)
- [msgpack-c](https://github.com/msgpack/msgpack-c)

## External Python Packages used
- [msgpack](https://github.com/msgpack/msgpack-python)
- [pandas](https://pandas.pydata.org/)

# Quickstart no building steps
```bash
git lfs pull
python CA5.py
```

# Build and Run
## Setting up python for build
```bash
virtualenv venv
source venv/bin/activate
pip install -r requirements.txt
```

## Msgpack Files
- Reasons for msgpack
    - Smaller data size
    - Easy encoding and decoding in libIMDB when using `msgpack-c`

You can either build the msgpack files from scratch using python or there are pre-built versions in git-lfs.

### Pulling pre-built via Git-lfs
```bash
git lfs pull
```

### Building from raw TSV files
```bash
python clean_data.py
```

## C Library

### Pulling pre-built library via Git-lfs
```bash
git lfs pull
```

### Building
Make sure you have both uthash and msgpack-c installed on your system and available in $LD_LIBRARY_PATH.

### OpenSUSE package install command
```bash
sudo zypper in -y uthash-devel msgpack-c-devel
```

### Building C Lib with make
> As a note, this make file assumes the naming of the msgpack library for linking is `msgpack-c`
```bash
cd libIMDB
make
```

# Running

