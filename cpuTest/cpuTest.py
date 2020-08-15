#!/usr/bin/python3
# -*- coding: utf-8 -*-
#  import urllib2
import requests
from bs4 import BeautifulSoup

response = requests.get('http://rank.kkj.cn/mcpu.shtml')
response.encoding = 'utf-8'
contents = response.text
soup = BeautifulSoup(contents, "html.parser")
print("CPU排行" + "\n" + "CPU\t\t时间\t\t分数")
for tag in soup.find_all('td', class_='merge'):
    cpu = tag.find('li', class_='model1').get_text()
    year = tag.find('li', class_='times1').get_text()
    score = tag.find('li', class_='mark1').get_text()
    print(year + "\t\t" + score + "\t\t" + cpu)
