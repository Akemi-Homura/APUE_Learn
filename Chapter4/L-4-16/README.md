# a
测试link和unlink函数

#### 测试步骤
```shell
dd if=/dev/zero of=tempfile bs=1024 count=1024000 # 生成测试文件 1GB
df /home                # 检查可用磁盘空间
./a.out &               # 后台运行
ls -l tempfile          # 观察文件是否仍然存在
df /home                # 检查可用磁盘空间
df /home                # 程序结束后再次检查磁盘空间
```

#### 结论
执行unlink后文件就已经不存在，磁盘空间未释放，程序结束后磁盘空间才被释放
