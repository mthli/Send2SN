#! /usr/bin/python2
# Filename: mail.py
# Come from: https://github.com/levisantony/python_email
# Coding: utf-8

from smtplib         import SMTP_SSL
from email.header    import Header
from email.mime.text import MIMEText
import datetime

# Gmail is default mail sender's system.
# If you want to use another mail system, see "menubar"-"help"-"guide"
# sender   = 'your mail count'
# passwd   = 'your mail password'
# classid  = 'your class number'
sender     = ''
passwd     = ''
classid    = ''

# follow this form to add your receivers:
# receivers = (
#   'aaaaaa@gmail.com',
#   'bbbbbb@gmail.com',
#   ...
#   'zzzzzz@gmail.com'
# )
receivers = (
    '',
    ''
)

infile = open('message.txt')
content = infile.read()
content = content.rstrip()
infile.close()
message = MIMEText(content, _charset = 'utf-8')
message['Subject'] = Header(classid + ' ' + str(datetime.datetime.now()) + ' Notice', 'utf-8')

smtp = SMTP_SSL('smtp.gmail.com', 465, timeout = 10)

try:
    smtp.login(sender, passwd)
    smtp.sendmail(sender, receivers, message.as_string())
finally:
    smtp.quit()
