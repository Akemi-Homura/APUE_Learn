# a
为每个命令行参数打印设备号，若此参数引用的是字符特殊文件或块特殊文件，则还打印该特殊文件的st_rdev值

#### test
```shell
./a.out /home/quals /dev/tty[01]
mount
ls -l /dev/tty[01] /dev/sda[34]
```
