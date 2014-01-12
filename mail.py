#! /usr/bin/python2
# Filename: mail.py
# Coding: utf-8

from smtplib         import Smtp
from email.header    import Header
from email.mime.text import Text

# 默认设置为使用Gmail，若需要修改可参考“帮助”——“指南”
# 发信人设置：
# sender   = '你的邮箱帐号'
# passwd   = '你的邮箱密码'
# classid  = '你的班级号码'
sender     = ' '
passwd     = ' '
classid    = ' '

# 按照如下格式添加收信人邮箱帐号：
# receivers = (
#   '第1个邮箱地址',
#   '第2个邮箱地址',
#   ...
#   '第n个邮箱地址
# )
receivers = (
    ' ', 
    ' '
)

infile = open('message.txt')
content = infile.read()
infile.close()
message = Text(content, _charset = 'utf-8')
message['Subject'] = Header(classid + '通知', 'utf-8')

smtp = SMTP('smtp.gmail.com', 465, timeout = 10)

try:
    smtp.login(sender, passwd)
    smtp.sendmail(sender, receivers, message.as_string())
finally:
    smtp.quit()
