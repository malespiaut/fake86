# imagegen

This tool generates a blank file of the given size, for use with Fake86.

Please note that the output of `imagegen` is no different than using `dd`

```
imagegen test.bin 128
```

produces the exact same output as

```
dd if=/dev/zero of=test.bin bs=1M count=128
```
