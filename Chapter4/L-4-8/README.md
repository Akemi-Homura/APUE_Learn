# a
测试access函数的使用方法

#### test command
```shell
su                  # be root
chown root a.out    # change uid
chmod u+s           # 打开设置用户ID
exit                # be normal user
./a.out     /etc/shadow   # can open and read
