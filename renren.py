#! /usr/bin/python2
# Filename: renren.py
# Come from: https://github.com/jsl9208/renrenStatus
# Coding: utf-8

import urllib
import urllib2
import re
import cookielib

# sender = 'your renren id'
# passwd = 'your renren password'
sender = ''
passwd = ''

def login(sender, passwd):
    data = {'email': sender, 'password': passwd}
    url_data = urllib.urlencode(data);
    cj = cookielib.CookieJar()
    handler = urllib2.HTTPCookieProcessor(cj)
    opener = urllib2.build_opener(handler)
    urllib2.install_opener(opener)
    res = opener.open('http://www.renren.com/ajaxLogin/login', url_data)
    res = opener.open('http://www.renren.com/home')
    html = res.read()
    uid = re.search("'ruid':'(\d+)'", html).group(1)
    return (opener, uid)

def status(sender, passwd):
    l = login(sender, passwd)
    opener = l[0]
    uid = l[1]
    res = opener.open("http://www.renren.com/home")
    html = res.read()
    rt = re.search("requesttoken=(\S+)", html).group(1)
    rtk = re.search("get_check_x:'(\w+)'", html).group(1)
    infile = open('message.txt')
    message = infile.read()
    message = message.rstrip()
    infile.close()
    data = {"content": message, "hostid": uid, "requestToken": rt, "_rtk": rtk, "channel": "renren"}
    url_data = urllib.urlencode(data)
    res = opener.open("http://shell.renren.com/"+uid+"/status", url_data)

status(sender, passwd)
