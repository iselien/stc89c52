stc89c52单片机学习程序

Mac、Linux平台使用SDCC编译，stcgal上传程序。

```shell
sdcc src/main.c
python3 stcgal.py -P stc89a -p /dev/tty.usbserial-14120 -a main.ihx
```